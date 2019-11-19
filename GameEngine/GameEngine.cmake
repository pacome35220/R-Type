set(GAME_ENGINE_DIR GameEngine/Src/)
set(CORE_DIR ${GAME_ENGINE_DIR}Core/)
set(MANAGER_DIR ${GAME_ENGINE_DIR}Manager/)

list(APPEND SRC
        ${GAME_ENGINE_DIR}AEntity.cpp
        ${GAME_ENGINE_DIR}EntityFactory.cpp
        ${GAME_ENGINE_DIR}Id.cpp

        ${CORE_DIR}ACore.cpp
        ${CORE_DIR}Client.cpp
        ${CORE_DIR}Server.cpp

        ${MANAGER_DIR}Audio.cpp
        ${MANAGER_DIR}Action.cpp
        ${MANAGER_DIR}Collision.cpp
        ${MANAGER_DIR}Network.cpp
)
