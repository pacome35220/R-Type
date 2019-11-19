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
set(MNTDIR Manager/)

set(ENTITY_DIR ../Entity/)
include(${ENTITY_DIR}Entity.cmake)


set(SRC
        ${SRCDIR}EntityFactory.cpp
        ${SRCDIR}AEntity.cpp
        ${SRCDIR}Id.cpp
        ${SRCDIR}${CORDIR}ACore.cpp
        ${SRCDIR}${CORDIR}CoreClient.cpp
        ${SRCDIR}${CORDIR}CoreServer.cpp
        ${SRCDIR}${MNTDIR}Collision.cpp
        ${SRCDIR}${MNTDIR}Action.cpp
        ${SRCDIR}${MNTDIR}Audio.cpp
        ${SRCDIR}${MNTDIR}Network.cpp
        )

set(INCLUDE
        ${INCDIR}EntityFactory.hpp
        ${INCDIR}AEntity.hpp
        ${INCDIR}Id.hpp
        ${INCDIR}Client.hpp
        ${INCDIR}${CORDIR}ICore.hpp
        ${INCDIR}${CORDIR}ACore.hpp
        ${INCDIR}${CORDIR}CoreClient.hpp
        ${INCDIR}${CORDIR}CoreServer.hpp
        ${INCDIR}${MNTDIR}Collision.hpp
        ${INCDIR}${MNTDIR}Network.hpp
        ${INCDIR}${MNTDIR}Action.hpp
        ${INCDIR}${MNTDIR}Audio.hpp
        )

# Includes directories
include_directories(${INCDIR} ../Common/${INCDIR})
include_directories(../Entity/${INCDIR})

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
