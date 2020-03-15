#include "Polygon.h"
#include <stdio.h>
#include <math.h>

void Polygon::drawPoint(int x, int y)
{
    /*  Verifica se há um ponto do poligono muito próximo.
        1. Se houver, então:
            1.1 Caso seja o primeiro ponto (index = 0) e haja outro pontos adicionado além do inicial,
            fecha o poligono o desenha
            
            1.2 Caso seja o primeiro e não haja outros pontos adicionados, não
            fecha o poligono e nem desenha o ponto
            
            1.3 Caso não seja o primeiro ponto (index > 0), não desenha o ponto
        
        2. Se não houver pontos próximos, desenha o novo ponto
    */
    int index = getNearestPointIndex(x, y, 10);

    glColor3dv(this->color);
    switch (index)
    {            
        case -1: /* 2. Desenha o novo ponto */
        {
            /* Desenha o quadrado em volta do ponto clicado */
            glBegin(GL_POLYGON);            
            glVertex2i(x - 2, y - 2);
            glVertex2i(x + 2, y - 2);
            glVertex2i(x + 2, y + 2);
            glVertex2i(x - 2, y + 2);
            glEnd();            

            
            glBegin(GL_LINES);    
            /* Caso já exista um ponto no poligono, cria uma reta entre
            o último ponto clicado e o novo */
            if(this->points.size() > 0)            
                glVertex2i(this->points.back().x, this->points.back().y);                        
            glVertex2i(x, y);
            
            /* Adiciona o novo ponto no vetor */  
            Point point;
            point.x = x;
            point.y = y;
            this->points.push_back(point);    
                        
            glEnd();
            glFlush();        
        }
        break;

        case 0: /* Clicou próximo ao ponto inicial do Poligono, verifica se está no caso 1.1 */        
        {
            if(this->points.size() >= 2)
            {                
                glBegin(GL_POLYGON);
                for (auto &&point : this->points)                
                    glVertex2i(point.x, point.y);                
                glEnd();
                glFlush();
                this->points.clear();
            }
        }
        break;
    }
    
}

int Polygon::getNearestPointIndex(int x, int y, int tolerance)
{    
    int index = 0;
    for (Point point : this->points)
    {         
        bool condition1 = abs(x - point.x) <= tolerance;
        bool condition2 = abs(y - point.y) <= tolerance;        
        if(condition1 && condition2)  
        {        
            return index;
        }
        index++;
    }
    return -1;
}

void Polygon::setColor(double red, double green, double blue)
{
    this->color[0] = red;
    this->color[1] = green;
    this->color[2] = blue;
}