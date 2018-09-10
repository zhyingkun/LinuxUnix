cmake_minimum_required(VERSION 3.0)

project(library)

add_library(vectorShared SHARED addvec.c multvec.c)#dynamic link library  .dylib
# set_target_properties(vectorShared PROPERTIES FRAMEWORK TRUE)

add_library(vectorModule MODULE addvec.c multvec.c)#dynamic load library  .so .bundle
add_library(vectorStatic STATIC addvec.c multvec.c)
