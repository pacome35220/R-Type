set(CMSRCDIR ${COMMON_DIR}Src/)
set(CMINCDIR ${COMMON_DIR}Include/)

# Includes common directories
include_directories(${COMMON_DIR}Include/)

# Append common source file to SRC
list(APPEND SRC
  ${CMSRCDIR}Error.cpp
  )

# Append common include file to INCLUDE
list(APPEND INCLUDE
  ${CMINCDIR}Error.hpp
  )