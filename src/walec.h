/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef WALEC_H
#define WALEC_H

#include <obiekt3d.h>
#include "kula.h"
#include "sciana.h"
#include "okrag.h"

/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Walec : public Obiekt3D
{
public:
    Walec(int ile = 100);

    ~Walec();

    virtual Obiekt3D* add();
    
    Walec* setTextureID(GLuint textureID);
    GLuint   getTextureID();

    Walec* setUseTexture(bool useTexture, GLuint textureID);
    Walec* setUseTexture(bool useTexture);
    bool    getUseTexture();
    
private:
  int n; 
  
  Sciana** sciany;
  Okrag *gora;
  Okrag *dol;
  
  GLuint textureID;
  bool useTexture;
};

#endif
