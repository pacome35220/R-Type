set(ENTITY_SRC Entity/Src/)
set(ENTITY_INC Entity/Include/)
# Includes common directories

include_directories(${ENTITY_INC})
include_directories(${ENTITY_INC}/Monster/)
include_directories(${ENTITY_INC}/Bullet/)

# Append common include file to INCLUDE
list(APPEND SRC
        ${ENTITY_SRC}Player.cpp
)

include_directories(Entity/Include/)
include_directories()
# Append common include file to INCLUDE
list(APPEND SRC
        Entity/Src/Player.cpp
)

