#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

void bscString2d(float x, float y, void *font, char *str) {
	int i;
	//glPushMatrix();
	//glTranslatef(x,y,0);
	//glLineWidth(2);
	//glScalef(0.5,0.5,1);
	glRasterPos2i(x,y);
	//glutBitmapString(GLUT_BITMAP_HELVETICA_18, str);
	for(i = 0; str[i] != '\0'; i++) {
		//glutStrokeCharacter(font, str[i]);
		glutBitmapCharacter(font, str[i]);
	}
	//glPopMatrix();
}