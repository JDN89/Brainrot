# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source files for the main program
SOURCES = main.c interpreter.c

# Object files for the main program
OBJECTS = $(SOURCES:.c=.o)

# Executable name for the main program
EXECUTABLE = brainrot

# Test source file
TEST_SOURCES = test_interpreter.c interpreter.c

# Test object files
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)

# Test executable name
TEST_EXECUTABLE = test_interpreter

# Build the main executable
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up build artifacts
clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(TEST_OBJECTS) $(TEST_EXECUTABLE)

# Build and run tests
test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJECTS)

# Mark targets as phony
# Ensures that make doesn't confuse these targets with files of the same name
.PHONY: all clean test
