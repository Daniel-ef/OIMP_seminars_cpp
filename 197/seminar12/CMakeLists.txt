cmake_minimum_required(VERSION 3.15)
project(seminar_12)

set(Cmake_CXX_Flags "O2 fno-elide-constructors")
set(CMAKE_CXX_STANDARD 17)

add_executable(seminar_12 vector.cpp)