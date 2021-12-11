cmake_minimum_required(VERSION 3.20)
project(videoRent)

set(CMAKE_CXX_STANDARD 14)

add_executable(videoRent main.cpp LinkedList.cpp LinkedList.h VideoOnline.cpp VideoOnline.h)
