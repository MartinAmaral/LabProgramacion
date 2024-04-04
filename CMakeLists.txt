cmake_minimum_required(VERSION 3.0)
project(C++lab)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_COMPILER cl.exe)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD")


add_executable(C++Lab main.cpp directorio.cpp sistema.cpp lista.cpp archivo.cpp )

