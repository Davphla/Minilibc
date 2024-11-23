# Default shell
SHELL = /bin/sh

# Directories
LIB_DIR := ./libasm
BUILD_DIR := ./build
TEST_DIR := ./tests
TEST_BUILD_DIR := $(BUILD_DIR)/tests
INC_DIR := ./include

# Compiler, assembler and archiver
CC := cc
AS := nasm
AR := ar

# Flags
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -m64 
CPPFLAGS := -I $(INC_DIR)
ARFLAGS := rcs

# Output archive and binary name 
LIBASM := libasm.a
TEST_OUT := unit_test

# ASM files
ASM_SRC := $(wildcard $(LIB_DIR)/*.asm)
ASM_OBJ := $(ASM_SRC:$(LIB_DIR)/%.asm=$(BUILD_DIR)/%.o)

# C test files
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ := $(TEST_SRC:$(TEST_DIR)/%.c=$(TEST_BUILD_DIR)/%.o)

# Phony targets
.PHONY: all test run clean fclean re

.DELETE_ON_ERROR:
all: $(LIBASM)

test: $(TEST_OUT)

run: test
	@./$(TEST_OUT)

# Build library
$(LIBASM): $(ASM_OBJ)
	$(AR) $(ARFLAGS) $@ $^ 

# Compile asm file
$(BUILD_DIR)/%.o: $(LIB_DIR)/%.asm
	$(AS) -f elf64 $< -o $@

# Compile c file
$(TEST_BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Check BUILD_DIR and TEST_BUILD_DIR existance
$(ASM_OBJ): | $(BUILD_DIR)
$(TEST_OBJ): | $(TEST_BUILD_DIR)

# And create them if not
$(BUILD_DIR) $(TEST_BUILD_DIR):
	@mkdir -p $@

# Create test binary
$(TEST_OUT): $(LIBASM) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TEST_OBJ) -o $(TEST_OUT) -L. -lasm

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(LIBASM) $(TEST_OUT)

re: fclean all
