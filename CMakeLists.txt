cmake_minimum_required(VERSION 3.29)
project(MathTutorV5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MathTutorV5
    main.cpp
    MathTutor.cpp
    MathTutor.h)
