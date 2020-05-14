CC := g++
CCFLAGS := -Wall -O3 -std=c++17

.PHONY = all clean


all: main.x

main.x: main.o reading.o cards.o
main.o: main.cc

reading.o: reading.cc

cards.o: cards.cc

%.x: %.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $^ -o $@ $(CCFLAGS)

clean:
	$(RM) $(wildcard *.[ox])