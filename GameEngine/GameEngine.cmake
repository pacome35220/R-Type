set(CMSRCDIR ${GE_DIR}Src/)
set(CMINCDIR ${GE_DIR}Include/)

# Includes common directories
include_directories(${GE_DIR}Include/)

# Append common source file to SRC
list(APPEND SRC
    ${CMSRCDIR}CollisionManager.cpp
    ${CMSRCDIR}AEntity.cpp
    ${CMSRCDIR}EntityFactory.cpp
    ${CMSRCDIR}ActionManager.cpp
    ${CMSRCDIR}networkManager.cpp
    ${CMSRCDIR}Id.cpp
    ${CMSRCDIR}Core/ACore.cpp
    ${CMSRCDIR}Core/CoreServer.cpp
)

# Append common include file to INCLUDE
list(APPEND INCLUDE
    ${CMINCDIR}CollisionManager.hpp
    ${CMINCDIR}AEntity.hpp
    ${CMINCDIR}EntityFactory.hpp
    ${CMINCDIR}ActionManager.hpp
    ${CMINCDIR}networkManager.hpp
    ${CMINCDIR}Id.hpp
    ${CMINCDIR}Core/ACore.hpp
    ${CMINCDIR}Core/CoreServer.hpp
  )
