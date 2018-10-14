cmake_minimum_required(VERSION 3.0)

project(thundering-herd)

add_executable(client client.c)

add_executable(acceptsrv acceptsrv.c)
add_executable(selectsrv selectsrv.c)
add_executable(pollsrv pollsrv.c)

# only for macos and linux, Not windows now
if(APPLE)
    add_executable(kqueuesrv kqueuesrv.c)
else(APPLE)
    add_executable(epollsrv epollsrv.c)
endif(APPLE)
