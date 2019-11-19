# CMake version required
cmake_minimum_required(VERSION 3.14)

# Project
project(Entity)

# Flags
set(CMAKE_CXX_STANDARD 14)

# Variables
set(SRCDIR Src/)
set(INCDIR Include/)
set(BULLETDIR Bullet/)
set(MONSTERDIR Monster/)

set(SRC
        ${SRCDIR}ABullet.cpp
        ${SRCDIR}Asteroid.cpp
        ${SRCDIR}Monster.cpp
        ${SRCDIR}Parallax.cpp
        ${SRCDIR}Player.cpp
        ${SRCDIR}PowerUp.cpp
        ${SRCDIR}${BULLETDIR}BlackStarBullet.cpp
        ${SRCDIR}${BULLETDIR}MonsterBullet.cpp
        ${SRCDIR}${BULLETDIR}PlayerBullet.cpp
        ${SRCDIR}${MONSTERDIR}ClassicMonster.cpp
        ${SRCDIR}${MONSTERDIR}DolleyMonster.cpp
        ${SRCDIR}${MONSTERDIR}DumbMonster.cpp
        ${SRCDIR}${MONSTERDIR}SpeedMonster.cpp
        ${SRCDIR}${MONSTERDIR}VenerMonster.cpp
        )

set(INCLUDE
        ${INCDIR}ABullet.hpp
        ${INCDIR}Asteroid.hpp
        ${INCDIR}Monster.hpp
        ${INCDIR}Parallax.hpp
        ${INCDIR}Player.hpp
        ${INCDIR}PowerUp.hpp
        ${INCDIR}EntityList.hpp
        ${INCDIR}${BULLETDIR}BlackStarBullet.hpp
        ${INCDIR}${BULLETDIR}MonsterBullet.hpp
        ${INCDIR}${BULLETDIR}PlayerBullet.hpp
        ${INCDIR}${MONSTERDIR}ClassicMonster.hpp
        ${INCDIR}${MONSTERDIR}DolleyMonster.hpp
        ${INCDIR}${MONSTERDIR}DumbMonster.hpp
        ${INCDIR}${MONSTERDIR}SpeedMonster.hpp
        ${INCDIR}${MONSTERDIR}VenerMonster.hpp
        )

# Includes directories
include_directories(${INCDIR})

# Conan libraries includes
include(../build/conanbuildinfo.cmake)
conan_basic_setup()

#Common includes
set(GE_DIR ../GameEngine/)
set(COMMON_DIR ../Common/)
set(ENTITY_DIR ../Entity/)
include(${GE_DIR}GameEngine.cmake)
include(${COMMON_DIR}Common.cmake)
include(${ENTITY_DIR}Entity.cmake)

# Compiled files
add_library(Entity STATIC ${SRC} ${INCLUDE})

# specify which libraries to connect
target_link_libraries(Entity ${CONAN_LIBS})
target_link_libraries(Entity -l m)

# Compiled Options
target_compile_options(Entity PRIVATE -W -Wall -Wextra -pedantic)
