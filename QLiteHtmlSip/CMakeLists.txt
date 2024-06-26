cmake_minimum_required(VERSION 3.12)

project(QLiteHtmlSip)

if(CMAKE_HOST_WIN32)
  set(PYTHON python)
  set(VER 1)
else()
  set(PYTHON python3)
endif()

get_filename_component(BINARY_DIR ${CMAKE_BINARY_DIR} ABSOLUTE)
set(QLITEHTMLLIBDIR "${BINARY_DIR}/qlitehtml/src")
message(STATUS "QLITEHTMLLIBDIR Directory: ${QLITEHTMLLIBDIR}")

execute_process(
  COMMAND
    ${PYTHON} -c
    "import os,PyQt5;print(os.path.dirname(PyQt5.__file__).replace('\\\\', '/'),end='')"
  OUTPUT_VARIABLE PYQTPATH)
message("PYQTPATH: ${PYQTPATH}")

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/pyproject.toml.in"
               "${CMAKE_CURRENT_SOURCE_DIR}/pyproject.toml")

add_custom_target(
  ${PROJECT_NAME} ALL
  COMMAND
    sip-install --verbose --tracing --qmake="${QT_QMAKE_EXECUTABLE}"
    --target-dir="${CMAKE_INSTALL_PREFIX}"
    --api-dir="${CMAKE_INSTALL_PREFIX}/PyQt5"
    --scripts-dir="${CMAKE_INSTALL_PREFIX}"
  DEPENDS qlitehtml
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_custom_target(
  ${PROJECT_NAME}COPY ALL
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_INSTALL_PREFIX}/QLiteHtmlWidget.*"
          "${CMAKE_INSTALL_PREFIX}/PyQt5/"
  COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_INSTALL_PREFIX}/QLiteHtmlWidget.*"
  DEPENDS ${PROJECT_NAME})
