CC := g++
CCFLAGS := -Wall -O3 -std=c++17
LDFLAGS := -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
.PHONY = all clean


all: sfml.x 

sfml.x: sfml.o game.o reading.o cards.o 
sfml.o: sfml.cc 

game.o: game.cc

reading.o: reading.cc

cards.o: cards.cc

%.x: %.o
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $^ -o $@ $(CCFLAGS)

clean:
	$(RM) $(wildcard *.[ox])