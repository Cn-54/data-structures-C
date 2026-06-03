CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET) libds.a

LIB_SRC = src/linkedList.c src/stack.c src/queue.c src/minHeap.c src/hashMap.c src/binaryTree.c
LIB_OBJ = $(LIB_SRC:src/%.c=build/%.o)

lib: $(LIB_OBJ)
	ar rcs libds.a $(LIB_OBJ)