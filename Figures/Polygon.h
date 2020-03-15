#include <GL/glut.h>
#include <vector>

struct Point
{
    int x, y, z;
};


class Polygon
{    
    private:
        /* fields */

        std::vector<Point> points;
        double color[3];
        
        /* methods */

        /* Obtem o indíce no vetor do ponto mais próximo dentro do índice de tolerancia.
        caso não exista, retorna -1 */
        int getNearestPointIndex(int x, int y, int tolerance);
        
    public:
        void drawPoint(int x, int y);        
        void setColor(double red, double green, double blue);
};