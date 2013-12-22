#include <GL/glut.h>
#include <stdio.h>
#include "game.h"
#include "mouse.h"

/*** some setup variables ***/

// desired frames per second
int fps = 60;

// window title
char* gameTitle = "Better Sim City";

/*** program ***/
int delay = 1;

void timer(int extra) {
	glutPostRedisplay();
	glutTimerFunc(delay, timer, 0);
}

int main(int argc, char **argv) {
	// setup
	delay = 1000 / fps;
    gameSetup(20,20);

  	glutInit(&argc, argv);
    glutInitWindowSize(windowWidth,windowHeight);
	glutCreateWindow(gameTitle);
	glutDisplayFunc(gameLoop);
	glutTimerFunc(delay, timer, 0);
	glutMouseFunc(mouse);
    glutPassiveMotionFunc(mouseMove);
	glutMainLoop();
}