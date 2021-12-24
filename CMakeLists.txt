cmake_minimum_required(VERSION 3.20)
project(videoRent)

set(CMAKE_CXX_STANDARD 14)

add_executable(videoRent main.cpp Function/VideoCustomer.cpp Function/VideoCustomer.h ADT/LinkedList.cpp ADT/LinkedList.h ADT/ItemsList.cpp ADT/ItemsList.h Function/CustomerItems.cpp Function/CustomerItems.h)
