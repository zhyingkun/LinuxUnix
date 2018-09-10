cmake_minimum_required(VERSION 3.0)

project(proc)

add_executable(pid pid.c)
add_executable(mem_segments mem_segments.c)
add_executable(necho necho.c)
add_executable(display_env display_env.c)
add_executable(t_getenv t_getenv.c)
add_executable(ProcMemAddr ProcMemAddr.c)
add_executable(goto goto.c)
