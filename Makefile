CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -m64
LDFLAGS = -Llib -lsimulation

# Source files
SRC = src/integration.c src/simulation_objects.c src/simulation.c src/utils.c
OBJ = $(SRC:.c=.o)

# Library
LIB = lib/libsimulation.a
LIB_WIN = lib/libsimulation.lib

# Main application
MAIN = main

all: $(LIB) $(LIB_WIN) $(MAIN)

$(LIB): $(OBJ)
	mkdir -p lib
	ar rcs $@ $^

$(LIB_WIN): $(OBJ)
	mkdir -p lib
	ar rcs $@ $^

$(MAIN): main.o $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f src/*.o main.o $(MAIN) $(LIB) $(LIB_WIN)
	rm -rf lib

rebuild: clean all

.PHONY: all clean rebuild