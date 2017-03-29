cmake_minimum_required(VERSION 3.7)
project(sbb)

add_executable(sbb main.c)

install(TARGETS sbb RUNTIME DESTINATION bin)
