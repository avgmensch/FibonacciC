# https://github.com/avgmensch/Makefiles/blob/98005defa383dc6cdc76a4aa262630ee4d46d66d/Simple_Astyle.mk

# Filenames
MAKEFILE = Makefile
EXECUTABLE = fibonacci

# Compiler and linker
CC = gcc
CFLAGS = -Wall -Wextra -Os -MMD -MP -c
LD = gcc
LDFLAGS = -s

# Code formatter
FMT = astyle
FMT_FLAGS = --style=allman --max-code-length=100 --suffix=none

# Define direcories
INC_DIR = include/
SRC_DIR = source/
OBJ_DIR = .build/

# Add get source files and include flag
INC_FILES = $(wildcard $(INC_DIR)*.h)
SRC_FILES = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))
CFLAGS += -I$(INC_DIR)

# Compile executable
bin: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(LD) $(LDFLAGS) -o $@ $^

-include $(wildcard $(OBJ_DIR)*.d)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MAKEFILE) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

# Phony rules
run: $(EXECUTABLE)
	@./$<

format:
	$(FMT) $(FMT_FLAGS) $(INC_FILES) $(SRC_FILES)

clean:
	rm -vrf $(OBJ_DIR)
	rm -vf $(EXECUTABLE)

.PHONY: run format clean