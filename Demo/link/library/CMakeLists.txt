cmake_minimum_required(VERSION 3.0)

project(library)

add_library(vectorShared SHARED addvec.c multvec.c)#dynamic link library  .dylib
# set_target_properties(vectorShared PROPERTIES
#     FRAMEWORK TRUE
    # FRAMEWORK_VERSION C
    # MACOSX_FRAMEWORK_IDENTIFIER com.zhyingkun.vectorShared
    # MACOSX_FRAMEWORK_INFO_PLIST Info.plist
    # VERSION 1.0.0
    #compatibility version
    # SOVERSION 1.0.0
    # PUBLIC_HEADER vectorShared.h
    # XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "zhyingkun.com"
# )

add_library(vectorModule MODULE addvec.c multvec.c)#dynamic load library  .so .bundle
add_library(vectorStatic STATIC addvec.c multvec.c)
