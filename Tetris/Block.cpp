#include "Block.h"

Block::Block(TetrisBlockType type, int x, int y)
{

    switch (this->type)
    {
    case TETRIS_BLOCK_TYPE_I:
        this->insertPoint(x, y - 40);
        this->insertPoint(x + 10, y - 40);
        this->insertPoint(x + 10, y);
        this->insertPoint(x, y);
        break;

    case TETRIS_BLOCK_TYPE_L:
        break;

    case TETRIS_BLOCK_TYPE_T:
        break;

    case TETRIS_BLOCK_TYPE_Z:
        break;

    case TETRIS_BLOCK_TYPE_O:
        break;
    }
}

void Block::drawBlock()
{
    glBegin(GL_POLYGON);
    glColor3dv(this->color);
    for (auto &&point : this->points)
    {
        glVertex2i(point.x, point.y);
    }
    glEnd();
    glFlush();
}
void Block::setColor(double red, double green, double blue)
{
    this->color[0] = red;
    this->color[1] = green;
    this->color[2] = blue;
}
void Block::insertPoint(int x, int y)
{
    Point point = {x, y};
    this->points.push_back(point);
}
void Block::moveLeft(int points)
{
    for (auto &&point : this->points)
    {
        point.x -= points;
    }
}
void Block::moveRight(int points)
{
    for (auto &&point : this->points)
    {
        point.x += points;
    }
}
void Block::moveDown(int points)
{
    for (auto &&point : this->points)
    {
        point.y += points;
    }
}
void Block::moveUp(int points)
{
    for (auto &&point : this->points)
    {
        point.y -= points;
    }
}

void Block::rotate()
{
    switch (this->type)
    {
    case TETRIS_BLOCK_TYPE_I:
        break;

    case TETRIS_BLOCK_TYPE_L:
        break;

    case TETRIS_BLOCK_TYPE_T:
        break;

    case TETRIS_BLOCK_TYPE_Z:
        break;

    case TETRIS_BLOCK_TYPE_O:
        break;
    }
}