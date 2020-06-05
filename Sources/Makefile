CC := g++
CCFLAGS := -Wall -O3 -std=c++17
LDFLAGS := -lsfml-system -lsfml-graphics -lsfml-window

.PHONY = all clean

all: gwint.x

window.o: window.cc

card.o: card.cc

game.o: game.cc

gwint.x: gwint.o game.o card.o window.o
gwint.o: test.cc


%.x: %.o
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $^ -o $@ $(CCFLAGS)

clean:
	$(RM) $(wildcard *.[ox])
