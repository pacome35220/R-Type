cmake_minimum_required(VERSION 3.14)
project(CPP_rtype_2019)

set(CMAKE_CXX_STANDARD 14)

if (NOT WIN32)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif (NOT WIN32)

# Include folders

include_directories(Common/)

include_directories(GameEngine/Include/)
include_directories(Entity/Include/)
include_directories(Common/Include/)

include(GameEngine/GameEngine.cmake)
include(Common/Common.cmake)
include(Entity/Entity.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_COMPILER clang++)

# Client
add_executable(r-type_client
        ${SRC}
        Client/Main.cpp
        )

# Server
add_executable(r-type_server
        ${SRC}
        Server/Main.cpp
        Server/Server.cpp
        )

if (NOT WIN32)
    target_link_libraries(r-type_server ${CONAN_LIBS} -lm)
    target_link_libraries(r-type_client ${CONAN_LIBS} -lm)
endif (NOT WIN32)
