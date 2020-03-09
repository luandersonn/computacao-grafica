// g++ main.cpp -lGL -lglut
// ./a.out

#include <GL/glut.h>
float vertices[4][3]{{-50, -50, 0}, {50, -50, 0}, {0, 50, 0}, {75, 10, 0}};
float color[3]{0.2, 0.36, 0.83};

/* callbacks */
void init();
void display();
void keyboard(unsigned char, int, int);

void triangle(float[3], float[3], float[3], float[3]);
void rectangle(float[3], float[3], float[3], float[3], float[3]);

int main(int argSize, char **argsValues)
{
	glutInit(&argSize, argsValues);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello World!");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.60, 0.29, 0.45, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	rectangle(color, vertices[0], vertices[1], vertices[2], vertices[3]);	
	glFlush();
}

void triangle(float color[3], float x[3], float y[3], float z[3])
{
	glBegin(GL_TRIANGLES);
	glColor3fv(color);
	glVertex3fv(x);
	glVertex3fv(y);
	glVertex3fv(z);
	glEnd();
}

void rectangle(float color[3], float p1[3], float p2[3], float p3[3], float p4[3])
{
	triangle(color, p1, p2, p3);
	color[0] = .20;
	color[1] = .20;
	color[2] = .20;
	triangle(color, p2, p3, p4);
}

void keyboard(unsigned char key, int x, int y)
{	
	//glutPostRedisplay();
}