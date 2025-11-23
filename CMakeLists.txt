cmake_minimum_required(VERSION 4.0)
project(EndangeredSpeciesBSTforStudents)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(EndangeredSpeciesBSTforStudents
        EndangeredSpeciesmain.cpp
        Interface.cpp
        Interface.hpp
        Species.cpp
        Species.hpp
        TNode.hpp
        BST.hpp
        TNode.cpp
        BST.cpp)
