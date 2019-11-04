# CMake version required
cmake_minimum_required(VERSION 3.14)

# Project
project(GameEngine)

# Flags
set(CMAKE_CXX_STANDARD 14)

# Variables
set(SRCDIR src/)
set(INCDIR include/)
set(CORDIR Core/)

set(SRC
  ${SRCDIR}${CORDIR}ACore.cpp
  ${SRCDIR}${CORDIR}Core.cpp
  ${SRCDIR}${CORDIR}CoreServer.cpp
  ${SRCDIR}EntityFactory.cpp
  ${SRCDIR}Entity.cpp
  ${SRCDIR}HaveId.cpp
  ${SRCDIR}Error.cpp
  )

set(INCLUDE
  ${INCDIR}${CORDIR}ACore.hpp
  ${INCDIR}${CORDIR}Core.hpp
  ${INCDIR}${CORDIR}CoreServer.hpp
  ${INCDIR}EntityFactory.hpp
  ${INCDIR}Entity.hpp
  ${INCDIR}HaveId.hpp
  ${INCDIR}Error.hpp
  )

# Includes directories
include_directories(${INCDIR})

# Conan libraries includes
include(../build/conanbuildinfo.cmake)
conan_basic_setup()

# Compiled files
add_library(GameEngine STATIC ${SRC} ${INCLUDE})

# specify which libraries to connect
target_link_libraries(GameEngine ${CONAN_LIBS})

# Compiled Options
target_compile_options(GameEngine PRIVATE -W -Wall -Wextra -pedantic)
