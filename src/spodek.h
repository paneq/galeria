#ifndef SPODEK_H
#define SPODEK_H

#include <GL/glut.h>
#include <math.h>

#include "obiekt3d.h"
/**
@author Robert Pankowecki, Jarosław Plebański
*/
class Spodek :public Obiekt3D {
public:
    Spodek();

    ~Spodek();

    Spodek* add();
   // Spodek* rotate(float alfa, float dx, float dy, float dz);
    //Spodek* translate(float dx, float dy, float dz);
    //Spodek* scale(float sx, float sy, float sz);

private:
    static const float Pi;

   /* bool uzylStos;

    void setUzylStos(bool uzylStos) {
        this->uzylStos = uzylStos;
    }
    

    bool getUzylStos() const {
        return uzylStos;
}*/
        
};

#endif
