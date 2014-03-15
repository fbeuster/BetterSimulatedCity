
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include "mouse.h"
#include "cell.h"

BscCell::BscCell(int x, int y) {
	cx = x;
	cy = y;
}

int BscCell::isActive() {
	int mx = getMouseX();
	int my = getMouseY();
	return 0;
}