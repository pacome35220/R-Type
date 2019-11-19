set(ENTITY_DIR Entity/Src/)
set(BULLET_DIR ${ENTITY_DIR}Bullet/)
set(MONSTER_DIR ${ENTITY_DIR}Monster/)

list(APPEND SRC
        ${ENTITY_DIR}ABullet.cpp
        ${ENTITY_DIR}AMonster.cpp
        ${ENTITY_DIR}Asteroid.cpp
        ${ENTITY_DIR}DeathStar.cpp
        ${ENTITY_DIR}Parallax.cpp
        ${ENTITY_DIR}Player.cpp
        ${ENTITY_DIR}PowerUp.cpp

        ${BULLET_DIR}DeathStar.cpp
        ${BULLET_DIR}Monster.cpp
        ${BULLET_DIR}Player.cpp

        ${MONSTER_DIR}Angry.cpp
        ${MONSTER_DIR}Classic.cpp
        ${MONSTER_DIR}Dolley.cpp
        ${MONSTER_DIR}Dumb.cpp
        ${MONSTER_DIR}Speed.cpp
)
