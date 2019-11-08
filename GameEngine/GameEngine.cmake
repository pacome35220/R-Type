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
    ${CMSRCDIR}NetworkManager.cpp
    ${CMSRCDIR}Id.cpp
    ${CMSRCDIR}Core/ACore.cpp
    ${CMSRCDIR}Core/CoreServer.cpp
    ${CMSRCDIR}Core/CoreClient.cpp
    ${CMSRCDIR}Clock.cpp
    )

# Append common include file to INCLUDE
list(APPEND INCLUDE
    ${CMINCDIR}CollisionManager.hpp
    ${CMINCDIR}AEntity.hpp
    ${CMINCDIR}EntityFactory.hpp
    ${CMINCDIR}ActionManager.hpp
    ${CMINCDIR}NetworkManager.hpp
    ${CMINCDIR}Id.hpp
    ${CMINCDIR}Core/ACore.hpp
    ${CMINCDIR}Core/CoreServer.hpp
    ${CMINCDIR}Core/CoreClient.hpp
    ${CMINCDIR}Clock.hpp
  )
