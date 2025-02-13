# Compiler and flags
CC = gcc
CFLAGS = -g -Wall

# Source files
SRCS = Lecture_31.c foo.c

# Output executable
TARGET = program

# Object files (generated from source files)
OBJS = $(SRCS:.c=.o)

# The default target, which builds the program
all: $(TARGET)

# How to create the target executable from object files
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule to create .o files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all clean