set(CMSRCDIR ${GE_DIR}Src/)
set(CMINCDIR ${GE_DIR}Include/)

# Includes common directories
include_directories(${GE_DIR}Include/)

# Append common source file to SRC
list(APPEND SRC
    ${CMSRCDIR}Core/ACore.cpp
    ${CMSRCDIR}Core/CoreServer.cpp
)

# Append common include file to INCLUDE
list(APPEND INCLUDE
  ${CMINCDIR}Core/ACore.hpp
  ${CMINCDIR}Core/CoreServer.hpp
  )