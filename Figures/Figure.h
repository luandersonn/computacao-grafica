#include <GL/glut.h>

class Figure
{    
    public:        
        void paint();
        void setColor(double red, double green, double blue);
        void setPoints(int x, int y, int size);
        double color[3];
        int x, y, size;
};