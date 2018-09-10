cmake_minimum_required(VERSION 3.0)

project(link)

add_library(vectorShared SHARED addvec.c multvec.c)#dynamic link library  .dylib
add_library(vectorModule MODULE addvec.c multvec.c)#dynamic load library  .so .bundle
add_library(vectorStatic STATIC addvec.c multvec.c)

add_executable(StaticLink StaticLink.c)
target_link_libraries(StaticLink vectorStatic)

add_executable(DynamicLink DynamicLink.c)
target_link_libraries(DynamicLink vectorShared)