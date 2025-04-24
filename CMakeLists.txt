cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Reto VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable from your source files
add_executable(index main.cpp utils.cpp utils.h clases/Media.h clases/Controller.cpp clases/User.cpp)