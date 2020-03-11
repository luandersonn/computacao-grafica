#include "Figure.h"

void Figure::setPoints(int x, int y, int size)
{
    this->x = x;
    this->y = y;
    this->size = size;
}

void Figure::setColor(double red, double green, double blue)
{
    this->color[0] = red;
    this->color[1] = green;
    this->color[2] = blue;
}

void Figure::paint()
{
    glBegin(GL_POLYGON);    
    glColor3dv(this->color);
    glVertex2d(this->x, this->y);
    glVertex2d(this->x + size, this->y);
    glVertex2d(this->x + size, this->y + size);
    glVertex2d(this->x, this->y + size);
    glEnd();
}