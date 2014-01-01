/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef SCIANA_H
#define SCIANA_H

#include "punkt.h"
#include "kolor.h"
#include "obiekt3d.h"

#include <GL/glut.h>
/**
	@author Jaroslaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Sciana : public Obiekt3D{
public:
    Sciana::Sciana();
    Sciana::Sciana(Punkt *a, Punkt *b, Punkt *c, Punkt *d);
    Sciana::Sciana(Punkt *a, Punkt *b, Punkt *c, Punkt *d, Kolor *kolor);
    
    Sciana* add();
    Sciana* clone(float dx, float dy, float dz);
    Sciana* setKolor(Kolor *kolor);

    Sciana* setTextureID(GLuint textureID);
    GLuint   getTextureID();

    Sciana* setUseTexture(bool useTexture, GLuint textureID);
    Sciana* setUseTexture(bool useTexture);
    bool    getUseTexture();

    Sciana* getTextureScale(Punkt &teksturaLewyDol, Punkt &teksturaPrawaGora);
    Sciana* setTextureScale(Punkt *teksturaLewyDol, Punkt *teksturaPrawaGora);

    Sciana* setAlfa(float const alfa);
    float getAlfa();
    Sciana* reverse();
    Punkt *obliczNormalny();
    
    Sciana* setNormalny(Punkt* punkt);
    ~Sciana();

    
    
    
private: 
    Punkt *a;
    Punkt *b;
    Punkt *c;
    Punkt *d;
    
    Punkt *n; //wektor normalny
    
    Punkt *teksturaLewyDol;
    Punkt *teksturaPrawaGora;
    Kolor *kolor;
    //bool uzylaStos;
    GLuint textureID;
    bool useTexture;
    
    Sciana* defaultTextureScale();
    Sciana* defaultTextureUse();
    
};

#endif

