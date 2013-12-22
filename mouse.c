#include <GL/glut.h>
#include "mouse.h"
#include "game.h"

void mouse(int btn, int state, int x, int y) {
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		speedUp();
	}
	if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		speedDown();
	}
	if(btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
		directionChange();
	}
}

void mouseMove(int x, int y) {
	if(x < windowWidth &&
		y < windowHeight- hudHeight) {
		colorCell(x,y);
	}
}