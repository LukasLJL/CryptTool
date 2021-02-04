cmake_minimum_required(VERSION 3.17)

project(crypt_tool C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(tests)
add_subdirectory(src)

add_executable(cryptlib cryptlib/cryptlib.c)