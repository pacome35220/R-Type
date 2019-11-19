# Includes common directories
include_directories(GameEngine/Include/)

# Append common source file to SRC
list(APPEND SRC
        GameEngine/Src/Manager/Collision.cpp
        GameEngine/Src/Manager/Action.cpp
        GameEngine/Src/Manager/Network.cpp
        GameEngine/Src/Manager/Audio.cpp
        GameEngine/Src/AEntity.cpp
        GameEngine/Src/EntityFactory.cpp
        GameEngine/Src/Id.cpp
        GameEngine/Src/Core/ACore.cpp
        GameEngine/Src/Core/CoreServer.cpp
        GameEngine/Src/Core/CoreClient.cpp
)
