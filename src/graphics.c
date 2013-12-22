/**
\file
\brief implementing all graphic functions defined in graphics.h
*/
#include <GL/glut.h>
#include <stdio.h>

/**
 * Glut provides (afaik) no rgb function, so here it is.
 *
 * A previous version used a rgb string as parameters but it buggy
 * (maybe to low).
 *
 * \param r red value
 * \param g green value
 * \param b blue value
 */
void colorFromRGB(float r, float g, float b) {
    glColor3f(r / 255, g / 255, b / 255);	
}

/**
 * This function is a shorthand function to draw a rectangle, given the bottom left
 * and the top right coordinate of it.
 *
 * \param lx Horizontal value for the bottom left corner
 * \param ly Verticalal value for the bottom left corner
 * \param rx Horizontal value for the top right corner
 * \param ry Vertical value for the top right corner
 */
void rectangle(float lx, float ly, float rx, float ry) {
    GLfloat vertexs[] = {
    	lx, ly,
        rx, ly,
        rx, ry,
        lx, ry
    };

	GLubyte indices[] = { 0, 1, 2, 3 };
 
	glIndexPointer( GL_UNSIGNED_BYTE, 0, indices );
	glVertexPointer( 2, GL_FLOAT, 0, vertexs );
 
	glDrawElements( GL_QUADS, 4, GL_UNSIGNED_BYTE, indices );
}