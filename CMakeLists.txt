cmake_minimum_required(VERSION 3.12)

project(QLiteHtml)

# Enable policy to not use RPATH settings for install_name on macOS.
if(POLICY CMP0068)
  cmake_policy(SET CMP0068 NEW)
endif()

# Enable policy to run automoc on generated files.
if(POLICY CMP0071)
  cmake_policy(SET CMP0071 NEW)
endif()

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/dist")

set(QLITEHTML_LIBRARY_TYPE STATIC)

add_subdirectory(qlitehtml)
add_subdirectory(QLiteHtmlSip)
add_subdirectory(QLiteHtmlShiboken)
