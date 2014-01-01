/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef OKRAG_H
#define OKRAG_H

#include <obiekt3d.h>
#include "kula.h"
#include <math.h>
#include "punkt.h"


/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Okrag : public Obiekt3D
{
public:
    Okrag(int ile = 100);

    ~Okrag();
    Okrag* reverseNormal();
    virtual Okrag* add();
    Okrag* setTextureID(GLuint textureID);
    GLuint   getTextureID();

    Okrag* setUseTexture(bool useTexture, GLuint textureID);
    Okrag* setUseTexture(bool useTexture);
    bool    getUseTexture();
    
private:
  int ile; /* z ilu odcinkow bedzie zbudowane kolo*/
  Punkt *n;
  GLuint textureID;
  bool useTexture;
    
  Okrag* defaultTextureUse();
};

#endif
