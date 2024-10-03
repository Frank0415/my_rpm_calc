# Compiler
CC = gcc
CFLAGS = -Wall -g

# Source files
SRC = main.c calc.c stack.c stringvar.c

# Object files (replace .c with .o for all sources)
OBJ = $(SRC:.c=.o)

# Output binary
TARGET = rp_calc

# Default target: build the program
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and the binary
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

format:
	clang-format -i *.c *.h