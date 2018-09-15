cmake_minimum_required(VERSION 3.0)

project(proc)

add_compile_options(-std=c99)

add_executable(pid pid.c)
add_executable(mem_segments mem_segments.c)
add_executable(necho necho.c)
add_executable(display_env display_env.c)
add_executable(t_getenv t_getenv.c)
add_executable(ProcMemAddr ProcMemAddr.c)
add_executable(goto goto.c)
add_executable(testsig testsig.c)
add_executable(errorcode errorcode.c)
add_executable(fork fork.c)
