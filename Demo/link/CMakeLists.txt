cmake_minimum_required(VERSION 3.0)

project(link)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(LIBRARY_OUTPUT_PATH "lib")

add_subdirectory(library)

add_executable(StaticLink StaticLink.c)
target_link_libraries(StaticLink vectorStatic)

add_executable(DynamicLink DynamicLink.c)
target_link_libraries(DynamicLink vectorShared)
