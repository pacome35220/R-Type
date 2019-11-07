# CMake version required
cmake_minimum_required(VERSION 3.14)

# Project
project(GameEngine)

# Flags
set(CMAKE_CXX_STANDARD 14)

# Variables
set(SRCDIR Src/)
set(INCDIR Include/)
set(CORDIR Core/)

set(SRC
        ${SRCDIR}${CORDIR}ACore.cpp
        ${SRCDIR}${CORDIR}CoreClient.cpp
        ${SRCDIR}${CORDIR}CoreServer.cpp
        ${SRCDIR}CollisionManager.cpp
        ${SRCDIR}EntityFactory.cpp
        ${SRCDIR}AEntity.cpp
        ${SRCDIR}Id.cpp
        ${SRCDIR}ActionManager.cpp
        ${SRCDIR}AudioManager.cpp
        ${SRCDIR}NetworkManager.cpp
        )

set(INCLUDE
        ${INCDIR}${CORDIR}ICore.hpp
        ${INCDIR}${CORDIR}ACore.hpp
        ${INCDIR}${CORDIR}CoreClient.hpp
        ${INCDIR}${CORDIR}CoreServer.hpp
        ${INCDIR}CollisionManager.hpp
        ${INCDIR}EntityFactory.hpp
        ${INCDIR}AEntity.hpp
        ${INCDIR}Id.hpp
        ${INCDIR}ActionManager.hpp
        ${INCDIR}AudioManager.hpp
        ${INCDIR}Client.hpp
        ${INCDIR}NetworkManager.hpp)

# Includes directories
include_directories(${INCDIR} ../Common/${INCDIR})

# Conan libraries includes
include(../build/conanbuildinfo.cmake)
conan_basic_setup()

# Compiled files
add_library(GameEngine STATIC ${SRC} ${INCLUDE})

# specify which libraries to connect
target_link_libraries(GameEngine ${CONAN_LIBS})
target_link_libraries(GameEngine -l m)

#common includes
set(COMMON_DIR ../Common/)
include(${COMMON_DIR}Common.cmake)

# Compiled Options
target_compile_options(GameEngine PRIVATE -W -Wall -Wextra -pedantic)
