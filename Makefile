##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SERVER_DIR      =       Server/
CLIENT_DIR      =       Client/
GAME_ENGINE_DIR =       GameEngine/ # ?

BUILD_DIR       =       build/
BIN_DIR		=       bin/

DOC_DIR         =       doc/

DOXYFILE        =       Doxyfile

all:	fclean
		conan install . --build=missing --install-folder $(BUILD_DIR)
		cmake . -G "Unix Makefiles" -B $(BUILD_DIR)
		cmake --build $(BUILD_DIR)
		mkdir -p $(BIN_DIR)
		mv $(BUILD_DIR)$(CLIENT_DIR)$(BIN_DIR)* $(BIN_DIR)
		mv $(BUILD_DIR)$(SERVER_DIR)$(BIN_DIR)* $(BIN_DIR)

client:	fclean
		conan install . --build=missing --install-folder $(BUILD_DIR)
		cmake $(CLIENT_DIR) -G "Unix Makefiles" -B $(BUILD_DIR)
		cmake --build $(BUILD_DIR)
		mkdir -p $(BIN_DIR)
		mv $(BUILD_DIR)$(BIN_DIR)* $(BIN_DIR)

server:	fclean
		conan install . --build=missing --install-folder $(BUILD_DIR)
		cmake $(SERVER_DIR) -G "Unix Makefiles" -B $(BUILD_DIR)
		cmake --build $(BUILD_DIR)
		mkdir -p $(BIN_DIR)
		mv $(BUILD_DIR)$(BIN_DIR)* $(BIN_DIR)

doc:
		@doxygen $(DOXYFILE)

fclean:
		@$(RM) -r $(BUILD_DIR)
		@$(RM) -r $(BIN_DIR)
		@$(RM) -r $(DOC_DIR)

.PHONY: client server game_engine doc fclean
