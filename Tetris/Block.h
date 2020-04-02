#include <GL/glut.h>
#include <vector>
#include "../util/Point.h"
#include "BlockType.h"

class Block
{
    private:
        void insertPoint(int x, int y);
    public:
        // Constructor
        Block(TetrisBlockType type, int x, int y);
        
        std::vector<Point> points;
        double color[3];
        TetrisBlockType type;

        // Methods
        void drawBlock();
        void setColor(double red, double green, double blue);        
        void moveLeft(int points);
        void moveRight(int points);
        void moveDown(int points);
        void moveUp(int points);
        void rotate();
};