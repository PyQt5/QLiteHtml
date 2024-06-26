cmake_minimum_required(VERSION 3.12)

project(QLiteHtml)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/dist")
set(CMAKE_BUILD_TYPE Release)
set(QLITEHTML_LIBRARY_TYPE STATIC)

add_subdirectory(qlitehtml)
add_subdirectory(QLiteHtmlSip)
