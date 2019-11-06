# CMake version required
cmake_minimum_required(VERSION 3.14)

# Project
project(RTypeServer)

# Flags
set(CMAKE_CXX_STANDARD 14)

# Variables
set(SRCDIR Src/)
set(INCDIR Include/)

set(SRC
    ${SRCDIR}Main.cpp
    ${SRCDIR}Server.cpp
  )

set(INCLUDE
    ${INCDIR}Server.hpp
)

# Includes directories
include_directories(${INCDIR} ../GameEngine/${INCDIR})

# Conan libraries includes
include(../build/conanbuildinfo.cmake)
conan_basic_setup()

#Common includes
set(GE_DIR ../GameEngine/)
set(COMMON_DIR ../Common/)
include(${GE_DIR}GameEngine.cmake)
include(${COMMON_DIR}Common.cmake)

# Compiled files
add_executable(r-type_server ${SRC} ${INCLUDE})

# specify which libraries to connect
target_link_libraries(r-type_server ${CONAN_LIBS})
