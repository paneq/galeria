/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "punkt.h"


Punkt::Punkt(float x,float y,float z){
    this->x=x;
    this->y=y;
    this->z=z;
}

Punkt::Punkt(){
  this->x=0;
  this->y=0;
  this->z=0;
}



Punkt* Punkt::setZ(const float& theValue)
{
    z = theValue;
    return this;
}


float Punkt::getZ() const
{
    return z;
}

Punkt* Punkt::setY(const float& theValue)
{
    y = theValue;
    return this;
}


float Punkt::getY() const
{
    return y;
}

Punkt* Punkt::setX(const float& theValue)
{
    x = theValue;
    return this;
}


float Punkt::getX() const
{
    return x;
}

Punkt::~Punkt()
{
  
}

Punkt* Punkt::normalize (Punkt *v)
{
    // calculate the length of the vector
    float len = (float)(sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));

    // avoid division by 0
    if (len == 0.0f)
        len = 1.0f;

    // reduce to unit size
    Punkt *znormalizowany = new Punkt();

    znormalizowany->x = v->x / len;
    znormalizowany->y = v->y / len;
    znormalizowany->z = v->z / len;

    return znormalizowany;
}

// normal(); - finds a normal vector and normalizes it
Punkt* Punkt::normal (Punkt *v0, Punkt *v1, Punkt *v2/*vertex_t v[3], vector_t *normal*/)
{
    Punkt* a = new Punkt();
    Punkt* b = new Punkt();

    Punkt* normal = new Punkt();
    // calculate the vectors A and B
    // note that v[3] is defined with counterclockwise winding in mind
    // a
    a->x = v0->x - v1->x;
    a->y = v0->y - v1->y;
    a->z = v0->z - v1->z;
    // b
    b->x = v1->x - v2->x;
    b->y = v1->y - v2->y;
    b->z = v1->z - v2->z;

    // calculate the cross product and place the resulting vector
    // into the address specified by vector_t *normal
    normal->x = (a->y * b->z) - (a->z * b->y);
    normal->y = (a->z * b->x) - (a->x * b->z);
    normal->z = (a->x * b->y) - (a->y * b->x);

    // normalize
    return normalize(normal);
}
