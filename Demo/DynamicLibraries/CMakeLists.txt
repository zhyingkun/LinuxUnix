cmake_minimum_required(VERSION 3.0)
project(DynamicLibraries
	VERSION 1.0
	# DESCRIPTION "Dynamic libraries"
	# HOMEPAGE_URL "www.zhyingkun.com"
	LANGUAGES C CXX)

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
	set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "CMakeLists.txt for ${PROJECT_NAME}")
message(STATUS "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

if(APPLE)
	set(CMAKE_C_FLAGS         "-std=c11 -Wall -Wextra")
	set(CMAKE_C_FLAGS_DEBUG   "-g")
	set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
	set(CMAKE_C_FLAGS         "-std=c11 -Wall -Wextra -Wno-unknown-pragmas")
	set(CMAKE_C_FLAGS_DEBUG   "-g")
	set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
elseif(WIN32)
	set(CMAKE_C_FLAGS         "-Wall -DHELLO_BUILD_AS_DLL -DHELLO_CORE")
	# set(CMAKE_C_FLAGS_DEBUG   "-g")
	set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
endif()

include_directories(./include)

aux_source_directory(./src HELLO_SRC)
file(GLOB HELLO_HEADERS "./include/*.h")

source_group(src FILES ${HELLO_SRC})
source_group(include FILES ${HELLO_HEADERS})

add_library(hello_so SHARED 
	${HELLO_SRC}
	${HELLO_HEADERS})
set_target_properties(hello_so PROPERTIES
	# FOLDER "DynamicLibraries"
	OUTPUT_NAME "hello"
	VERSION ${PROJECT_VERSION}
	SOVERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
	POSITION_INDEPENDENT_CODE ON)

add_library(hello_a STATIC 
	${HELLO_SRC}
	${HELLO_HEADERS})

if(APPLE)
	add_library(hello_mod MODULE 
		${HELLO_SRC}
		${HELLO_HEADERS})
	set_target_properties(hello_mod PROPERTIES
		# FOLDER "DynamicLibraries"
		OUTPUT_NAME "hello"
		VERSION ${PROJECT_VERSION}
		SOVERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
		POSITION_INDEPENDENT_CODE ON)
	add_library(hello_framework SHARED 
		${HELLO_SRC}
		${HELLO_HEADERS})
	set_target_properties(hello_framework PROPERTIES
		# FOLDER "DynamicLibraries"
		OUTPUT_NAME "hello"
		VERSION ${PROJECT_VERSION}
		SOVERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
		POSITION_INDEPENDENT_CODE ON
		FRAMEWORK TRUE
		FRAMEWORK_VERSION A
		PUBLIC_HEADER ${HELLO_HEADERS}
		MACOSX_FRAMEWORK_IDENTIFIER com.zhyingkun.hello)
	add_library(hello_a_framework STATIC 
		${HELLO_SRC}
		${HELLO_HEADERS})
	set_target_properties(hello_a_framework PROPERTIES
		# FOLDER "DynamicLibraries"
		OUTPUT_NAME "hello_a"
		VERSION ${PROJECT_VERSION}
		SOVERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
		POSITION_INDEPENDENT_CODE ON
		FRAMEWORK TRUE
		FRAMEWORK_VERSION A
		PUBLIC_HEADER ${HELLO_HEADERS}
		MACOSX_FRAMEWORK_IDENTIFIER com.zhyingkun.hello)
	add_library(hello_bundle MODULE 
		${HELLO_SRC}
		${HELLO_HEADERS})
	set_target_properties(hello_bundle PROPERTIES
		# FOLDER "DynamicLibraries"
		OUTPUT_NAME "hello"
		VERSION ${PROJECT_VERSION}
		SOVERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
		POSITION_INDEPENDENT_CODE ON
		BUNDLE TRUE)

endif(APPLE)
