# CMake version required
cmake_minimum_required(VERSION 3.14)

# Project
project(GameEngine)

# Flags
set(CMAKE_CXX_STANDARD 14)

# Variables
set(SRCDIR Src/)
set(INCDIR Include/)

set(SRC
  ${SRCDIR}Main.cpp
  ${SRCDIR}ACore.cpp
  ${SRCDIR}Entity.cpp
  ${SRCDIR}HaveId.cpp
  )

set(INCLUDE
  ${INCDIR}ACore.hpp
  ${INCDIR}Entity.hpp
  ${INCDIR}HaveId.hpp
  )

# Includes directories
include_directories(${INCDIR})

# Conan libraries includes
include(../../build/conanbuildinfo.cmake)
conan_basic_setup()

# Compiled files
add_library(libGameEngine.a ${SRC} ${INCLUDE})

# specify which libraries to connect
target_link_libraries(GameEngine ${CONAN_LIBS})
