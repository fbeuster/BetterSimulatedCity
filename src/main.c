/**
\file
\brief implementation the main function of Better Simulated City
*/
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

/**
 * \brief The game timer.
 *
 * This function is the timing function for glutTimerFunc().
 *
 * \param extra
 */
void timer(int extra) {
	glutPostRedisplay();
	glutTimerFunc(delay, timer, 0);
}

/**
 * \brief The game main function.
 *
 * This is the entering function for the program/game with the well known
 * parameters. Some basic glut functions are called from here.
 *
 * \param argc The number of arguments.
 * \param argv An array of arguments itself.
 */
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