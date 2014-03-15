.PHONY: clean

CXXFLAGS = -g -Wall -ansi -pedantic
LIBS = -lGL -lglut -lGLU
CXX = g++
LDFLAGS = -lm

OBJECTS = src/graphics.o src/text.o src/game.o src/mouse.o src/main.o

all: BetterSimCity

BetterSimCity: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBS) $^ $(LDFLAGS) -o $@

mouse.o: mouse.h game.h
game.o: game.h graphics.h text.h
main.o: mouse.h game.h

clean:
	$(RM) $(OBJECTS) BetterSimCity