cmake_minimum_required(VERSION 4.1)
project(n)

set(CMAKE_CXX_STANDARD 20)

add_executable(n main.cpp
        " BankAccount.h"
        BankAccount.cpp)
