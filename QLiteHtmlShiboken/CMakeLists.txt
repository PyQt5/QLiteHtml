cmake_minimum_required(VERSION 3.12)

project(QLiteHtmlShiboken)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

if(CMAKE_HOST_WIN32)
  set(PYTHON python)
  set(VER 1)
else()
  set(PYTHON python3)
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  set(SHIBOKEN shiboken6)
  execute_process(
    COMMAND
      ${PYTHON} -c
      "import os,PySide6;print(os.path.dirname(PySide6.__file__).replace('\\\\', '/'),end='')"
    OUTPUT_VARIABLE PYSIDEPATH)
else()
  set(SHIBOKEN shiboken2)
  execute_process(
    COMMAND
      ${PYTHON} -c
      "import os,PySide2;print(os.path.dirname(PySide2.__file__).replace('\\\\', '/'),end='')"
    OUTPUT_VARIABLE PYSIDEPATH)
endif()

message("PYSIDEPATH: ${PYSIDEPATH}")

string(REPLACE ";" ":" QtWidgets_INCLUDE_DIRS
               "${Qt${QT_VERSION_MAJOR}Widgets_INCLUDE_DIRS}")
string(REPLACE ";" ":" QtGui_INCLUDE_DIRS
               "${Qt${QT_VERSION_MAJOR}Gui_INCLUDE_DIRS}")
string(REPLACE ";" ":" QtCore_INCLUDE_DIRS
               "${Qt${QT_VERSION_MAJOR}Core_INCLUDE_DIRS}")

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/project.toml.in"
               "${CMAKE_CURRENT_SOURCE_DIR}/project.toml")
