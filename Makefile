.PHONY: clean

OBJECTS := src/main.o src/mouse.o src/game.o src/graphics.o

all: BetterSimCity

BetterSimCity: $(OBJECTS)
	$(CC) $(LDFLAGS) -lGL -lGLU -lglut -ansi -pedantic $^ -o $@

mouse.o: game.h
game.o: graphics.h
main.o: mouse.h game.h

clean:
	$(RM) $(OBJECTS)
