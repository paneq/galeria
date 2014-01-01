/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef KOLUMNA_H
#define KOLUMNA_H

#include <obiekt3d.h>
#include "sciana.h"
#include "walec.h"
#include <math.h>

/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Kolumna : public Obiekt3D
{
public:
    Kolumna(int ile = 8, int wysokosc = 20, float r0 = 0.9, float r1 =1 );

    ~Kolumna();

    virtual Obiekt3D* add();
    Kolumna* setUseTexture(bool useTexture, GLuint textureID);
  private:
    int n; 
    int wysokosc;
    bool useTexture;
    Sciana** sciany;
    Walec* gora;
    Walec* dol;
    
};

#endif
