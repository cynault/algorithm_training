cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(leetcodeCPP)
set(CMAKE_CXX_STANDARD 17)
aux_source_directory(src SOURCES)
include_directories(inc)
add_executable(leetcodeCPP ${SOURCES})
add_subdirectory(third_party/fmt)
target_link_libraries(leetcodeCPP fmt::fmt)