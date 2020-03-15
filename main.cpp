// g++ main.cpp -lGL -lglut
// g++ *.cpp */*.cpp -O -lGL -lglut
// ./a.out
#include <stdio.h>
#include "Figures/Figure.h"
#include "Figures/Polygon.h"


/* callbacks */
void init();
void display();
void keyboard(unsigned char, int, int);
void pointer(int, int, int, int);

Polygon* polygon = new Polygon();		


int main(int argSize, char **argsValues)
{
	glutInit(&argSize, argsValues);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Polygon");
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
	switch (key)
	{
		case 'r':
		case 'R':
			polygon->setColor(6.0, 0.2, 0.2);		
			break;

		case 'g':
		case 'G':
			polygon->setColor(0.2, 6.0, 0.2);
			break;

		case 'b':
		case 'B':
			polygon->setColor(0.2, 0.2, 6.0);
			break;

		case 's':
		case 'S':
			polygon->setColor(0.2, 0.2, 0.2);
			break;
	}
	
}

void pointer(int button, int state, int x, int y)
{		
	if(state == GLUT_DOWN)
	{		
		switch (button)
		{
			case GLUT_LEFT_BUTTON:						
				polygon->drawPoint(x, y);
				break;
			case GLUT_MIDDLE_BUTTON:
			case GLUT_RIGHT_BUTTON:
				break;
		}
	}
}