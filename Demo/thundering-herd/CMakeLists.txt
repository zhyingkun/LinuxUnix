cmake_minimum_required(VERSION 3.0)

project(thundering-herd
	VERSION 1.0.0
	LANGUAGES C)

add_subdirectory(./selectsrv)

# only for macos and linux, Not windows now
if(APPLE)
	# add_subdirectory(./kqueuesrv)
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	# add_subdirectory(./epollsrv)
elseif(WIN32)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET selectsrv PROPERTY FOLDER "Demo/thundering-herd")
