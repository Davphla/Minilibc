# Commands
LD := ar rcs
ASM := nasm

# Flags
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -m64 

# Directories
INC_DIR := inc
SRC_DIR := src
BUILD_DIR := build
TEST_DIR := tests

# Binary names
LIB_NAME := libasm.a
TEST_OUT := unit_test

# ASM files
ASM_SRC := $(wildcard src/*.asm)
ASM_OBJ := $(ASM_SRC:$(SRC_DIR)/%.asm=$(BUILD_DIR)/%.o)

# C test files
TEST_SRC := $(wildcard tests/*.c)
TEST_OBJ := $(TEST_SRC:$(TEST_DIR)/%.c=$(BUILD_DIR)/%.o)

.DELETE_ON_ERROR:
all: $(LIB_NAME)

$(LIB_NAME): $(ASM_OBJ)
	$(LD) $^ -o $@

$(ASM_OBJ): $(ASM_SRC)
	$(ASM) -f elf64 $< -o $@

$(TEST_OBJ): $(TEST_SRC)
	$(CC) -c $< -o $@

$(ASM_OBJ) $(TEST_OBJ): | $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

test: $(ASM_OBJ)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(LIB_NAME)

.PHONY: all clean test