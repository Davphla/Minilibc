
CC=gcc
LD=gcc
ASM=nasm

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -m64

SRC := $(wildcard src/*.asm)
OBJ := $(SRC:.asm=.o)

OUT := run
TEST_OUT := test_program


all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $^ -o $@

%.o: %.asm
	$(ASM) -f elf64 $< -o $@

clean:

.PHONY: all clean