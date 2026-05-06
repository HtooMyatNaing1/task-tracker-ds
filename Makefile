CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

TARGET = task_tracker.exe

SRC = src/main.c \
      src/bst.c \
      src/linear.c \
      src/queue.c \
      src/linkedlist.c \
      src/stack.c

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

rebuild: clean all