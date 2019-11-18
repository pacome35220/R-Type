set(ENTITY_INC ${ENTITY_DIR}Include/)

# Includes common directories
include_directories(${ENTITY_DIR}Include/)

# Append common include file to INCLUDE
list(APPEND INCLUDE
        ${ENTITY_INC}EntityList.hpp
)
