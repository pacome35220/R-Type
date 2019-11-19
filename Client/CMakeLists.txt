# CMake version required
cmake_minimum_required(VERSION 3.14)

# Project
project(RTypeClient)

# Flags
set(CMAKE_CXX_STANDARD 14)

# Variables
set(SRCDIR Src/)
set(INCDIR Include/)

set(SRC
        Main.cpp
  )

set(INCLUDE
  # TODO
  )

# Includes directories
include_directories(${INCDIR}
                    ../GameEngine/${INCDIR}
                    ../Entity/${INCDIR}
                    )

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
add_executable(r-type_client ${SRC} ${INCLUDE})

# specify which libraries to connect
target_link_libraries(r-type_client ${CONAN_LIBS})
