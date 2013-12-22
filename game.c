#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include "graphics.h"
#include "game.h"

/*** interaction ***/

void speedUp() {
	if(speed < 5.0f) {
		speed += 1.0f;
	}	
}

void speedDown() {
	if(speed > 1.0f) {
		speed -= 1.0f;
	}
}

void directionChange() {
	dir = dir * -1;
}

/*** game ***/

void colorCell(int x, int y) {
	int cellX = x / 25;
	int cellY = (500 - y) / 25;
	cells[cellX][cellY] = "10000";
}

void gameSetup(int gc, int gr) {
	// setup game field
	gameCols = gc;
	gameRows = gr;

	// size up window
	hudHeight = 80.0;
	windowWidth = (25 + 1) * gameCols + 1;
	windowHeight = (25 + 1) * gameRows + 1 + hudHeight;

	speed = 1;
	dir = 1;
	deg = 1.0f;

	// field
	int m,n;
	for(m = 0; m < gameCols; m++) {
		for(n = 0; n < gameRows; n++) {
			cells[m][n] = "00000";
		}
	}

	// 378a27
	cellColors[0][0] = 55;
	cellColors[0][1] = 138;
	cellColors[0][2] = 39;
	// ff0000
	cellColors[1][0] = 255;
	cellColors[1][1] = 0;
	cellColors[1][2] = 0;
}

void gameText() {

	// text area background
	colorFromRGB(244, 244, 244);
	rectangle(0.0,0.0,windowWidth,hudHeight);

	// text
	colorFromRGB(16, 16, 16);

    char speedBuff[8];
    sprintf(speedBuff, "Speed: %d",speed);

    char dirBuff[16];
    if(dir == 1) {
    	sprintf(dirBuff, "Direction: %s", "left");
    } else {
    	sprintf(dirBuff, "Direction: %s", "right");
    }

    glRasterPos2i(10, hudHeight/2);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, speedBuff);
    glRasterPos2i(10, 10);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, dirBuff);
}

void gameLoop() {
	// init
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
 
	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_INDEX_ARRAY );

    // game field
	colorFromRGB(27.0, 27.0, 27.0);
	rectangle(0.0,hudHeight,windowWidth,windowHeight);

	int m,n;
	for(m = 0; m < gameCols; m++) {
		for(n = 0; n < gameRows; n++) {
			colorFromRGB(
				cellColors[ cells[m][n][0] - 48 ][0],
				cellColors[ cells[m][n][0] - 48 ][1],
				cellColors[ cells[m][n][0] - 48 ][2]);
			rectangle(
				m * 26.0 + 1, n * 26.0 + 1 + hudHeight,
				m * 26.0 + 1 + 25, n * 26.0 + 1 + 25 + hudHeight);
		}
	}

    gameText();

	glFlush();
}