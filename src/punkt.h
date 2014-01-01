/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef PUNKT_H
#define PUNKT_H

#include <math.h>

/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Punkt{
public:
    Punkt(float x,float y,float z);
    Punkt();
    ~Punkt();
    
    Punkt* setZ(const float& theValue);
    float getZ() const;
    
    Punkt* setY(const float& theValue);
    float getY() const;
    
    Punkt* setX(const float& theValue);
    float getX() const;

    static Punkt* normalize (Punkt *v)  ;
    static Punkt* normal (Punkt *v0, Punkt *v1, Punkt *v2);

private:
    float x;
    float y;
    float z;

};

#endif
