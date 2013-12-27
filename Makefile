.PHONY: clean

OBJECTS := src/main.o src/game.o src/mouse.o src/graphics.o

all: BetterSimCity

BetterSimCity: $(OBJECTS)
	$(CXX) $(LDFLAGS) -lGL -lGLU -lglut -ansi -pedantic $^ -o $@

mouse.o: game.h
game.o: graphics.h
main.o: mouse.h game.h

clean:
	$(RM) $(OBJECTS)
