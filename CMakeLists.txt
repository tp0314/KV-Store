cmake_minimum_required(VERSION 3.16)
project(kvstore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(kvcore src/kv_store.cpp)
target_include_directories(kvcore PUBLIC src)

add_executable(kvstore src/main.cpp)
target_link_libraries(kvstore PRIVATE kvcore)
