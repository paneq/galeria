/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "kolor.h"

Kolor::Kolor() {
    r = 0.0;
    g = 0.6;
    b = 0.0;
}

Kolor::Kolor(float r, float g, float b, float alfa) {
    this->r = r;
    this->b = b;
    this->g = g;
    this->alfa = alfa;
};
    
    


Kolor::~Kolor() {
}

float Kolor::getR() const{
    return r;
};

float Kolor::getG() const {
    return g;
};

float Kolor::getB() const {
    return b;
};

float Kolor::getAlfa() const {
    return alfa;
}

Kolor* Kolor::setR(float const r){
    this->r = r;
    return this;
};

Kolor* Kolor::setG(float const g){
    this->g = g;
    return this;
};

Kolor* Kolor::setB(float const b){
    this->b = b;
    return this;
};

Kolor* Kolor::setAlfa( float const alfa ){
    this->alfa = alfa;
    return this;
}
