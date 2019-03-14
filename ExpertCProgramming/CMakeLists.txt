cmake_minimum_required(VERSION 3.0)
project(ExpertCProgramming
	VERSION 1.0.0
	LANGUAGES C)

add_subdirectory(./linklist)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET linklist PROPERTY FOLDER "ExpertCProgramming")
