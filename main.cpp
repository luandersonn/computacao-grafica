// g++ main.cpp -lGL -lglut
// g++ *.cpp */*.cpp -O -lGL -lglut
// ./a.out
#include <stdio.h>
#include "Figures/Figure.h"


/* callbacks */
void init();
void display();
void keyboard(unsigned char, int, int);
void pointer(int, int, int, int);

Figure* figure = new Figure();		


int main(int argSize, char **argsValues)
{
	glutInit(&argSize, argsValues);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Figures");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(pointer);
	init();
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.60, 0.29, 0.45, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, 500, 500, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{	
	
}

void pointer(int button, int state, int x, int y)
{	
	switch (button)
	{
		case GLUT_LEFT_BUTTON:	
		case GLUT_MIDDLE_BUTTON:
		case GLUT_RIGHT_BUTTON:
			break;
	}

	printf("Click na coordenada %dx%d\n", x, y);		
	figure->setColor(0.6, 0.9, 0);	
	figure->setPoints(x - 25, y - 25, 50);
	figure->paint();
	glFlush();
}