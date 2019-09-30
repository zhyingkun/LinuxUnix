cmake_minimum_required(VERSION 3.0)
project(Cstdlib
	VERSION 1.0.0
	LANGUAGES C CXX)

message(STATUS "CMakeLists.txt for ${PROJECT_NAME}")

add_subdirectory(C11)
add_subdirectory(C89)
add_subdirectory(C99)
add_subdirectory(NA1)
