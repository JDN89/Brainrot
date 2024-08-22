CC = gcc
CFLAGS = -Wall -Wextra -g
SOURCES = main.c 
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = brainrot

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
