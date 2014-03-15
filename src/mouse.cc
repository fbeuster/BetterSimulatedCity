/**
\file
\brief implementation the of all mouse functions defined in mouse.h
*/
#include <GL/glut.h>
#include "mouse.h"
#include "game.h"

/**
 * This function handles mouse events, such as key presses. It is called via
 * a glut event, therefore all parameters coming from that.
 *
 * \note
 * The position parameters have (0,0) in the top left corner.
 *
 * \param btn	The button that triggered the event.
 * \param state	The state of that button.
 * \param x		Horizontal position of the mouse.
 * \param y		Vertical position of the mouse.
 */
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

/**
 * In this function mouse movements were handled. It is called from glut,
 * therefore both parameters are coming from there.
 *
 * \note
 * The position parameters have (0,0) in the top left corner.
 *
 * \param x		Horizontal position of the mouse.
 * \param y		Vertical position of the mouse.
 */
void mouseMove(int x, int y) {
	if(x >= 0 && x <= windowWidth &&
		y >= 0 && y <= windowHeight - hudHeight) {
		mouseX = x;
		mouseY = windowHeight - hudHeight - y;
	} else {
		mouseX = 0;
		mouseY = 0;
	}
}

/**
 * This function handles leaving/entering of the mouse in the window.
 *
 * \param state The GLUT state (_ENTERED or _LEFT)
 */
void mouseLeaveEnter(int state) {
	mouseOverWindow = state;
}

/*int getMouseX() {
	return mouseX;
}

int getMouseY() {
	return mouseY;
}*/