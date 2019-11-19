set(ENTITY_INC ${ENTITY_DIR}Include/)
set(ENTITY_SRC ${ENTITY_DIR}Src/)

# Includes common directories
include_directories(${ENTITY_DIR}Include/)

# Append common include file to INCLUDE
list(APPEND INCLUDE
        ${ENTITY_INC}EntityList.hpp
)

list(APPEND SRC
        ${ENTITY_SRC}Player.cpp
)
