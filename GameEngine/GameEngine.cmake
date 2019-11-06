set(CMSRCDIR ${COMMOM_DIR}Src/)
set(CMINCDIR ${COMMOM_DIR}Include/)

# Includes common directories
include_directories(${COMMOM_DIR}Include/)

# Append common source file to SRC
list(APPEND SRC
    ${CMSRCDIR}Core/ACore.cpp
)

# Append common include file to INCLUDE
list(APPEND INCLUDE
  ${CMINCDIR}Core/ACore.hpp
  )