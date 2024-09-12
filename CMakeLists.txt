cmake_minimum_required(VERSION 3.30)
project(Mnemoc VERSION 1.0 DESCRIPTION "Fiches de révision")
 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 20)

# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(PkgConfig REQUIRED)
find_package(SQLite3 REQUIRED)

pkg_check_modules(GTKMM gtkmm-4.0)

add_subdirectory(src) 
