cmake_minimum_required(VERSION 3.14)
project(CPP_rtype_2019)

set(CMAKE_CXX_STANDARD 14)

if (NOT WIN32)
	include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
	conan_basic_setup()
endif(NOT WIN32)

include(Common/Common.cmake)
include(Entity/Entity.cmake)
include(GameEngine/GameEngine.cmake)

# Client

include_directories(Client/Include/)

add_executable(r-type_client
    ${SRC}
    Client/Main.cpp
)

# Server

include_directories(Server/Include/)

add_executable(r-type_server
    ${SRC}
    Server/Main.cpp
    Server/Server.cpp
)

if (NOT WIN32)
	target_link_libraries(r-type_server ${CONAN_LIBS})
	target_link_libraries(r-type_client ${CONAN_LIBS})
endif(NOT WIN32)
