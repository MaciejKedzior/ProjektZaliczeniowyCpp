CC := g++
CCFLAGS := -Wall -O3 -std=c++17
LDFLAGS := -lsfml-system -lsfml-graphics -lsfml-window
.PHONY = all clean


all: sfml.x test.x

test.x: test.o game.o card.o window.o
test.o: test.cc 

sfml.x: sfml.o game.o card.o 
sfml.o: sfml.cc 

window.o: window.cc

game.o: game.cc

card.o: card.cc

%.x: %.o
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $^ -o $@ $(CCFLAGS)

clean:
	$(RM) $(wildcard *.[ox])
