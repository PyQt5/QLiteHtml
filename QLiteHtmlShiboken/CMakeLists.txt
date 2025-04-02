cmake_minimum_required(VERSION 3.12)

project(QLiteHtmlShiboken LANGUAGES CXX)

# Enable policy to not use RPATH settings for install_name on macOS.
if(POLICY CMP0068)
  cmake_policy(SET CMP0068 NEW)
endif()

# Enable policy to run automoc on generated files.
if(POLICY CMP0071)
  cmake_policy(SET CMP0071 NEW)
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 14)
set(LIBNAME QLiteHtmlWidget)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

# Use provided python interpreter if given.
if(NOT python_interpreter)
  find_program(python_interpreter "python")
endif()
message(STATUS "Using python interpreter: ${python_interpreter}")

# Macro to get various pyside / python include / link flags and paths. Uses the
# not entirely supported utils/pyside2_config.py file.
macro(pyside2_config option output_var)
  if(${ARGC} GREATER 2)
    set(is_list ${ARGV2})
  else()
    set(is_list "")
  endif()

  execute_process(
    COMMAND ${python_interpreter}
            "${CMAKE_CURRENT_SOURCE_DIR}/utils/pyside2_config.py" ${option}
    OUTPUT_VARIABLE ${output_var}
    OUTPUT_STRIP_TRAILING_WHITESPACE)

  if("${${output_var}}" STREQUAL "")
    message(
      FATAL_ERROR
        "Error: Calling pyside2_config.py ${option} returned no output.")
  endif()
  if(is_list)
    string(REPLACE " " ";" ${output_var} "${${output_var}}")
  endif()
endmacro()

if(CMAKE_HOST_UNIX)
  string(REPLACE ";" ":" QtWidgets_INCLUDE_DIRS
                 "${Qt${QT_VERSION_MAJOR}Widgets_INCLUDE_DIRS}")
  string(REPLACE ";" ":" QtGui_INCLUDE_DIRS
                 "${Qt${QT_VERSION_MAJOR}Gui_INCLUDE_DIRS}")
  string(REPLACE ";" ":" QtCore_INCLUDE_DIRS
                 "${Qt${QT_VERSION_MAJOR}Core_INCLUDE_DIRS}")
  set(INCLUDE_DIRS
      "${CMAKE_CURRENT_SOURCE_DIR}/../qlitehtml/src:${QtCore_INCLUDE_DIRS}:${QtGui_INCLUDE_DIRS}:${QtWidgets_INCLUDE_DIRS}:/lib/gcc/x86_64-linux-gnu/12/include"
  )
else()
  set(INCLUDE_DIRS
      "${CMAKE_CURRENT_SOURCE_DIR}/../qlitehtml/src;${Qt${QT_VERSION_MAJOR}Widgets_INCLUDE_DIRS};${Qt${QT_VERSION_MAJOR}Gui_INCLUDE_DIRS};${Qt${QT_VERSION_MAJOR}Core_INCLUDE_DIRS}"
  )
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  set(SHIBOKEN shiboken6)
  execute_process(
    COMMAND
      ${PYTHON} -c
      "import os,PySide6;print(os.path.dirname(PySide6.__file__).replace('\\\\', '/'),end='')"
    OUTPUT_VARIABLE PYSIDEPATH)
else()
  # Query for the shiboken generator path, Python path, include paths and linker
  # flags.
  pyside2_config(--shiboken2-module-path shiboken2_module_path)
  pyside2_config(--shiboken2-generator-path shiboken2_generator_path)
  pyside2_config(--pyside2-path pyside2_path)
  pyside2_config(--pyside2-include-path pyside2_include_dir 1)
  pyside2_config(--python-include-path python_include_dir)
  pyside2_config(--shiboken2-generator-include-path shiboken_include_dir 1)
  pyside2_config(--shiboken2-module-shared-libraries-cmake
                 shiboken_shared_libraries 0)
  pyside2_config(--python-link-flags-cmake python_linking_data 0)
  pyside2_config(--pyside2-shared-libraries-cmake pyside2_shared_libraries 0)

  set(shiboken_path
      "${shiboken2_generator_path}/shiboken2${CMAKE_EXECUTABLE_SUFFIX}")
  if(NOT EXISTS ${shiboken_path})
    message(
      FATAL_ERROR "Shiboken executable not found at path: ${shiboken_path}")
  endif()

  set(PYSIDEPATH "${pyside2_path}")

  message(STATUS "*** shiboken2_module_path=${shiboken2_module_path}")
  message(STATUS "*** shiboken2_generator_path=${shiboken2_generator_path}")
  message(STATUS "*** pyside2_path=${pyside2_path}")
  message(STATUS "*** pyside2_include_dir=${pyside2_include_dir}")
  message(STATUS "*** python_include_dir=${python_include_dir}")
  message(STATUS "*** python_linking_data=${python_linking_data}")
  message(STATUS "*** pyside2_shared_libraries=${pyside2_shared_libraries}")

  # We need to include the headers for the module bindings that we use.
  set(pyside2_additional_includes "")
  foreach(INCLUDE_DIR ${pyside2_include_dir})
    list(APPEND pyside2_additional_includes "${INCLUDE_DIR}/QtCore")
    list(APPEND pyside2_additional_includes "${INCLUDE_DIR}/QtGui")
    list(APPEND pyside2_additional_includes "${INCLUDE_DIR}/QtWidgets")
  endforeach()
  message(
    STATUS "*** pyside2_additional_includes=${pyside2_additional_includes}")

  set(binding_sources
      ${CMAKE_CURRENT_SOURCE_DIR}/out/PySide2/${LIBNAME}/pyside2_qlitehtmlwidget_python.h
      ${CMAKE_CURRENT_SOURCE_DIR}/out/PySide2/${LIBNAME}/qlitehtmlwidget_module_wrapper.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/out/PySide2/${LIBNAME}/qlitehtmlwidget_wrapper.h
      ${CMAKE_CURRENT_SOURCE_DIR}/out/PySide2/${LIBNAME}/qlitehtmlwidget_wrapper.cpp
  )
endif()

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/project.toml.in"
               "${CMAKE_CURRENT_SOURCE_DIR}/project.toml")

# Add custom target to run shiboken to generate the binding cpp files.

get_filename_component(BINARY_DIR ${CMAKE_BINARY_DIR} ABSOLUTE)
set(QLITEHTMLLIBDIR "${BINARY_DIR}/qlitehtml/src")
message(STATUS "*** QLITEHTMLLIBDIR Directory: ${QLITEHTMLLIBDIR}")

add_library(${LIBNAME} SHARED ${binding_sources})
target_include_directories(
  ${LIBNAME}
  PRIVATE ${INCLUDE_DIRS} ${pyside2_additional_includes} ${pyside2_include_dir}
          ${python_include_dir} ${shiboken_include_dir})
target_link_directories(
  ${LIBNAME} PRIVATE "${QLITEHTMLLIBDIR}"
  "${QLITEHTMLLIBDIR}/3rdparty/litehtml"
  "${QLITEHTMLLIBDIR}/3rdparty/litehtml/src/gumbo")
target_link_libraries(
  ${LIBNAME}
  PRIVATE Qt${QT_VERSION_MAJOR}::Core
          Qt${QT_VERSION_MAJOR}::Gui
          Qt${QT_VERSION_MAJOR}::Widgets
          ${pyside2_shared_libraries}
          ${shiboken_shared_libraries}
          qlitehtml1
          litehtml
          gumbo)

# Add QLITEHTML_STATIC_LIBRARY definition to correctly handle static library
# imports
target_compile_definitions(${LIBNAME} PRIVATE QLITEHTML_STATIC_LIBRARY)

set_property(TARGET ${LIBNAME} PROPERTY PREFIX "")
set_property(TARGET ${LIBNAME} PROPERTY OUTPUT_NAME
                                        "${LIBNAME}${PYTHON_EXTENSION_SUFFIX}")
if(WIN32)
  set_property(TARGET ${LIBNAME} PROPERTY SUFFIX ".pyd")
endif()
if(APPLE)
  set_target_properties(${LIBNAME} PROPERTIES LINK_FLAGS
                                              "-undefined dynamic_lookup")
endif(APPLE)

# Find and link to the python import library only on Windows. On Linux and
# macOS, the undefined symbols will get resolved by the dynamic linker (the
# symbols will be picked up in the Python executable).
if(WIN32)
  list(GET python_linking_data 0 python_libdir)
  list(GET python_linking_data 1 python_lib)
  find_library(
    python_link_flags ${python_lib}
    PATHS ${python_libdir}
    HINTS ${python_libdir})
  target_link_libraries(${LIBNAME} PRIVATE ${python_link_flags})
endif()

set(windows_shiboken_shared_libraries)

if(WIN32)
  # =========================================================================================
  # !!! (The section below is deployment related, so in a real world application
  # you will want to take care of this properly (this is simply to eliminate
  # errors that users usually encounter.
  # =========================================================================================
  # Circumvent some "#pragma comment(lib)"s in "include/pyconfig.h" which might
  # force to link against a wrong python shared library.

  set(python_versions_list
      3
      32
      33
      34
      35
      36
      37
      38
      39
      310
      311)
  set(python_additional_link_flags "")
  foreach(ver ${python_versions_list})
    set(python_additional_link_flags
        "${python_additional_link_flags} /NODEFAULTLIB:\"python${ver}_d.lib\"")
    set(python_additional_link_flags
        "${python_additional_link_flags} /NODEFAULTLIB:\"python${ver}.lib\"")
  endforeach()

  set_target_properties(${LIBNAME} PROPERTIES LINK_FLAGS
                                              "${python_additional_link_flags}")

  # Compile a list of shiboken shared libraries to be installed, so that the
  # user doesn't have to set the PATH manually to point to the PySide2 package.
  foreach(library_path ${shiboken_shared_libraries})
    string(REGEX REPLACE ".lib$" ".dll" library_path ${library_path})
    file(TO_CMAKE_PATH ${library_path} library_path)
    list(APPEND windows_shiboken_shared_libraries "${library_path}")
  endforeach()
  # =========================================================================================
  # !!! End of dubious section.
  # =========================================================================================
endif()

set(LIBEXT "*")
if(CMAKE_HOST_WIN32)
  set(LIBEXT "pyd")
endif()

add_custom_target(
  ${PROJECT_NAME}COPY ALL
  COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_INSTALL_PREFIX}/PySide2/"
  COMMAND
    ${CMAKE_COMMAND} -E copy
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/QLiteHtmlWidget.${LIBEXT}"
    "${CMAKE_INSTALL_PREFIX}/PySide2/"
  DEPENDS ${LIBNAME})
