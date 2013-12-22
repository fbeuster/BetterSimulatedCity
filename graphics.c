#include <GL/glut.h>
#include <stdio.h>

void colorFromRGB(float r, float g, float b) {
    glColor3f(r / 255, g / 255, b / 255);	
}

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