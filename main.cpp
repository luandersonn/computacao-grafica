// g++ main.cpp -lGL -lglut
// g++ *.cpp */*.cpp -O -lGL -lglut
// ./a.out
#include <stdio.h>
#include <unistd.h>
#include <algorithm>
#include "Tetris/Block.h"


/* callback prototypes */
void display();
void keyboardTyped(unsigned char, int, int);
void pointerClicked(int, int, int, int);
void blockDown(int);
void desenharLinhas();

/* functions prototypes */
void init();
Block* createBlock();

Block* activeBlock;
bool onPause;

int main(int argSize, char **argsValues)
{
	activeBlock = createBlock();	
	glutInit(&argSize, argsValues);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tetris");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardTyped);
	glutMouseFunc(pointerClicked);	
	glutTimerFunc(1000, blockDown, 0);
	init();	
	glutMainLoop();
	return 0;
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	desenharLinhas();
	activeBlock->drawBlock();	
	glFlush();
}
void keyboardTyped(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		activeBlock->rotate();
		onPause = false;
		printf("MOVER PARA CIMA\n");
		break;

	case 'a':
	case 'A':
		activeBlock->moveLeft(10);
		onPause = false;
		printf("MOVER PARA ESQUERDA\n");
		break;

	case 's':
	case 'S':
		activeBlock->moveDown(10);
		onPause = false;
		printf("MOVER PARA BAIXO\n");
		break;

	case 'd':
	case 'D':
		activeBlock->moveRight(10);
		onPause = false;
		printf("MOVER PARA DIREITA\n");
		break;

	case 'p':
	case 'P':		
		onPause = !onPause;		
		break;
	}	
	glutPostRedisplay();
}

void pointerClicked(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			break;
		case GLUT_MIDDLE_BUTTON:
		case GLUT_RIGHT_BUTTON:
			break;
		}
	}
}

void blockDown(int value)
{
	if(!onPause)	
	{
		activeBlock->moveDown(20);
		glutPostRedisplay();		
	}		
	glutTimerFunc(1000, blockDown, 0);	
}

void init()
{
	glClearColor(0, 0, 0.2, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, 500, 500, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void desenharLinhas()
{
	glBegin(GL_LINES);
	glColor4f(0.2, 0.2, 0.2, 0.1);		
	for (int i = 0; i < 500; i+= 10)
	{
		glVertex2d(200, i);
		glVertex2d(300, i);
		
		glVertex2d(std::min(i + 200, 300), 0);
		glVertex2d(std::min(i + 200, 300), 500);
	}
	glEnd();
	glFlush();	
}

Block* createBlock()
{
	Block* block = new Block(TETRIS_BLOCK_TYPE_I, 250, 0);
	block->setColor(1, 0.2, 0.5);	
	return block;
}