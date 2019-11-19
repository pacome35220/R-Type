##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

BUILD_DIR       =       build/
BIN_DIR		=       bin/

DOC_DIR         =       Doc/html

DOXYFILE        =       Doxyfile

all:	fclean
		conan install .  --build=missing --install-folder $(BUILD_DIR)
		cmake . -G "Unix Makefiles" -B $(BUILD_DIR)
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
