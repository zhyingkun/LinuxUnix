cmake_minimum_required(VERSION 3.0)
project(ExpertCProgramming
	VERSION 1.0.0
	LANGUAGES C)

add_subdirectory(./linklist)
add_subdirectory(./cdecl)
add_subdirectory(./newcdecl)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET linklist PROPERTY FOLDER "ExpertCProgramming")
set_property(TARGET cdecl PROPERTY FOLDER "ExpertCProgramming")
set_property(TARGET newcdecl PROPERTY FOLDER "ExpertCProgramming")
