#ifndef KULA_H
#define KULA_H

#include <GL/glut.h>
#include <math.h>
#include "obiekt3d.h"

/**
@author Robert Pankowecki, Jarosław Plebański
*/
class Kula :public Obiekt3D {
public:
    Kula();

    ~Kula();

    Kula* add();
    //Kula* rotate(float alfa, float dx, float dy, float dz);
    //Kula* translate(float dx, float dy, float dz);
    //Kula* scale(float sx, float sy, float sz);


    static const float Pi;
private:
    //bool uzylStos;

    //void setUzylStos(bool uzylStos) {
    //    this->uzylStos = uzylStos;
    //}
    

    //bool getUzylStos() const {
    //    return uzylStos;
    //}
        
};

#endif
