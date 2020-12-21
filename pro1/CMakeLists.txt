cmake_minimum_required(VERSION 3.18)
project(demp)

aux_source_directory(src SRC)

include_directories(include)

add_executable(demo ${SRC})