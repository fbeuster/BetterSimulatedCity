/**
\file
\brief implementation of all gaming function defined in game.h
*/
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include "graphics.h"
#include "text.h"
#include "game.h"

int windowWidth;
int windowHeight;	
int hudHeight;
int gameCols;
int gameRows;
int cellWidth;
int cellHeight;
char cells[20][20][5];
int cellColors[10][3];
int mouseX;
int mouseY;
int mouseOverWindow;

int speed;
int dir;
int deg;

/*** interaction ***/

/**
 * This function increases the rotation speed an check against a limit.
 */
void speedUp() {
	if(speed < 5.0f) {
		speed += 1.0f;
	}	
}

/**
 * This function decreases the rotation speed an check against a limit.
 */
void speedDown() {
	if(speed > 1.0f) {
		speed -= 1.0f;
	}
}

/**
 * This function flips the rotation direction.
 */
void directionChange() {
	dir = dir * -1;
}

/*** game ***/

/**
 * This function checks, wether the mouse in in the given cell or not.
 *
 * \param cx cell column
 * \param cy cell row
 *
 * \returns 1 if it is in cell, else 0
 */
int isInCell(int cx, int cy) {
	if(mouseX > 0 && mouseY > 0) {
		if(mouseX > (cellWidth + 1) * cx && mouseX <= (cellWidth + 1) * (cx + 1) &&
			mouseY > (cellHeight + 1) * cy && mouseY <= (cellHeight + 1) * (cy + 1)) {
			if(mouseOverWindow) {
				return 1;
			}
		}
	}
	return 0;
}

/**
 * This function set the color of a cell.
 *
 * \note
 * Mouse (0,0) is the the top left corner, while render (0,0) is in
 * the bottom left corner.
 *
 * \param x horizontal position of the mouse
 * \param y vertical position of the mouse
 */
void colorCell(int x, int y, char c) {
	int cellX = x / (cellWidth + 1);
	int cellY = (windowHeight - hudHeight - y) / (cellHeight + 1);
	cells[cellX][cellY][0] = c;
}

/**
 * This function realizes the basic game setup. Such as size calculation and
 * generating the game field data.
 *
 * \param gc game field columns
 * \param gr game field rows
 */
void gameSetup(int gc, int gr) {
	// setup game field
	gameCols = gc;
	gameRows = gr;
	cellWidth = 25;
	cellHeight = 25;
	mouseX = 0;
	mouseY = 0;
	mouseOverWindow = 0;

	// size up window
	hudHeight = 80.0;
	windowWidth = (cellWidth + 1) * gameCols + 1;
	windowHeight = (cellHeight + 1) * gameRows + 1 + hudHeight;

	speed = 1;
	dir = 1;
	deg = 1.0f;

	// field
	int m,n;
	for(m = 0; m < gameCols; m++) {
		for(n = 0; n < gameRows; n++) {
			strcpy(cells[m][n], "00000");
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

/**
 * This function is rendering the HUD area and filling it with text information.
 */
void gameHUD() {

	// text area background
	colorFromRGB(244, 244, 244);
	rectangle(0.0,0.0,windowWidth,hudHeight);

	// text
	colorFromRGB(16, 16, 16);

    char speedBuff[30];
    sprintf(speedBuff, "Speed: %i", speed);

    char dirBuff[16];
    if(dir == 1) {
    	sprintf(dirBuff, "Direction: %s", "left");
    } else {
    	sprintf(dirBuff, "Direction: %s", "right");
    }

    bscString2d(10, hudHeight / 2, GLUT_BITMAP_HELVETICA_18, dirBuff);
    bscString2d(10, 10, GLUT_BITMAP_HELVETICA_18, speedBuff);
}

/**
 * The basic game loop for drawing all elements on the game field and
 * calling the HUD.
 */
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
	int cx,cy;
	for(m = 0; m < gameCols; m++) {
		for(n = 0; n < gameRows; n++) {
			if(!isInCell(m, n)) {
				cells[m][n][0] = '0';
			} else {
				cells[m][n][0] = '1';
				cx = m;
				cy = n;
			}
			colorFromRGB(
				cellColors[ cells[m][n][0] - 48 ][0],
				cellColors[ cells[m][n][0] - 48 ][1],
				cellColors[ cells[m][n][0] - 48 ][2]);
			rectangle(
				m * 26.0 + 1, n * 26.0 + 1 + hudHeight,
				m * 26.0 + 1 + 25, n * 26.0 + 1 + 25 + hudHeight);
		}
	}

	// hover text
	if(isInCell(cx,cy)) {
		colorFromRGB(255,255,255);

		int cHb = cellHeight + 1; // cellHeight + border
		int xl = cx * cHb;
		int yl = (cy-1) * cHb + 1 + hudHeight;
		int xr = xl + 120;
		int yr = yl + 25;

		int diffX = windowWidth - xr;
		if(diffX < 0) {
			xl = xl + diffX;
			xr = xr + diffX;
		}
		if(yl < hudHeight) {
			yl = yl + 2 * cHb;
			yr = yr + 2 * cHb;
		}
		
		rectangle(xl, yl, xr, yr);

		colorFromRGB(16,16,16);

    	char str[16];
		sprintf(str, "X: %d - Y: %d", cx, cy);
		bscString2d(xl, yl + 5, GLUT_BITMAP_HELVETICA_18, str);
	}

    gameHUD();

	glFlush();
}