cmake_minimum_required(VERSION 3.0)

project(stdalign)

set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )      # 生成 compile_commands.json供vim c++插件语义补全使用

add_executable(stdalignTest stdalignTest.c)
