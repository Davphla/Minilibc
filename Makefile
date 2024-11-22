# Default shell
SHELL = /bin/sh

# Directories
SRC_DIR := libasm
BUILD_DIR := build
TEST_DIR := tests
INC_DIR := include

# Compiler and assembler
ASM := nasm
CC := gcc
AR := ar

# Flags
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -m64 
CPPFLAGS := -I $(INC_DIR)
ARFLAGS := rcs

# Binary names
LIB_NAME := libasm.a
TEST_OUT := unit_test

# ASM files
ASM_SRC := $(wildcard $(SRC_DIR)/*.asm)
ASM_OBJ := $(ASM_SRC:$(SRC_DIR)/%.asm=$(BUILD_DIR)/%.o)

# C test files
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ := $(TEST_SRC:$(TEST_DIR)/%.c=$(BUILD_DIR)/%.o)

# Phony targets
.PHONY: all test run clean fclean re

.DELETE_ON_ERROR:
all: $(LIB_NAME)

test: $(TEST_OUT)

run: test
	@./$(TEST_OUT)

# Build library
$(LIB_NAME): $(ASM_OBJ)
	$(AR) $(ARFLAGS) $@ $^ 

# Compile asm file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm
	$(ASM) -f elf64 $< -o $@

# Compile c file
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Check BUILD_DIR existing
$(ASM_OBJ) $(TEST_OBJ): | $(BUILD_DIR)

# Create BUILD_DIR
$(BUILD_DIR):
	@mkdir -p $@

# Create test binary
$(TEST_OUT): $(LIB_NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TEST_OBJ) -o $(TEST_OUT) -L. -lasm

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(LIB_NAME) $(TEST_OUT)

re: fclean all
