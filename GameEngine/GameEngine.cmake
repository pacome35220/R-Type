set(CMSRCDIR ${GE_DIR}Src/)
set(CMINCDIR ${GE_DIR}Include/)
set(MNTDIR Manager/)

# Includes common directories
include_directories(${GE_DIR}Include/)

# Append common source file to SRC
list(APPEND SRC
        ${CMSRCDIR}${MNTDIR}CollisionManager.cpp
        ${CMSRCDIR}${MNTDIR}ActionManager.cpp
        ${CMSRCDIR}${MNTDIR}NetworkManager.cpp
        ${CMSRCDIR}${MNTDIR}AudioManager.cpp
        ${CMSRCDIR}AEntity.cpp
        ${CMSRCDIR}EntityFactory.cpp
        ${CMSRCDIR}Id.cpp
        ${CMSRCDIR}Core/ACore.cpp
        ${CMSRCDIR}Core/CoreServer.cpp
        ${CMSRCDIR}Core/CoreClient.cpp
        ${CMSRCDIR}Clock.cpp
        )

# Append common include file to INCLUDE
list(APPEND INCLUDE
        ${CMINCDIR}${MNTDIR}CollisionManager.hpp
        ${CMINCDIR}${MNTDIR}ActionManager.hpp
        ${CMINCDIR}${MNTDIR}NetworkManager.hpp
        ${CMINCDIR}${MNTDIR}AudioManager.hpp
        ${CMINCDIR}AEntity.hpp
        ${CMINCDIR}EntityFactory.hpp
        ${CMINCDIR}Id.hpp
        ${CMINCDIR}Core/ACore.hpp
        ${CMINCDIR}Core/CoreServer.hpp
        ${CMINCDIR}Core/CoreClient.hpp
        ${CMINCDIR}Clock.hpp
        )
