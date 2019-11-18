set(ENTITY_SRC Src/)
set(ENTITY_INC Include/)

# Includes common directories
include_directories(${ENTITY_DIR}Include/)

# Append common source file to SRC
list(APPEND SRC

        )

# Append common include file to INCLUDE
list(APPEND INCLUDE
        ${ENTITY_INC}EntityList.hpp
        )
