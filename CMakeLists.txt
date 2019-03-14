cmake_minimum_required(VERSION 3.0)
project(LinuxUnix
	VERSION 1.0.0
	LANGUAGES C CXX)

message(STATUS "CMakeLists.txt for ${PROJECT_NAME}")
message(STATUS "Current OS is ${CMAKE_SYSTEM}")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# add_subdirectory(ComputerLab)
# add_subdirectory(Cstdlib)
# add_subdirectory(Demo)
add_subdirectory(ExpertCProgramming)
# add_subdirectory(FlexBison)
# add_subdirectory(SelfCultivation)
