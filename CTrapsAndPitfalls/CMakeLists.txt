cmake_minimum_required(VERSION 3.0)
project(CTrapsAndPitfalls
	VERSION 1.0.0
	LANGUAGES C)

add_subdirectory(./carray)
add_subdirectory(./lexical)
add_subdirectory(./macro)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET carray PROPERTY FOLDER "CTrapsAndPitfalls")
set_property(TARGET lexical PROPERTY FOLDER "CTrapsAndPitfalls")
set_property(TARGET macro PROPERTY FOLDER "CTrapsAndPitfalls")
