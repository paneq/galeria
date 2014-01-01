/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef SZESCIAN_H
#define SZESCIAN_H

#include "sciana.h"
#include "obiekt3d.h"

/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Szescian : public Obiekt3D {
public:
    Szescian();
    Szescian(     Sciana *gora,
                    Sciana *dol,
                    Sciana *lewo,
                    Sciana *prawo,
                    Sciana *przod,
                    Sciana *tyl);

    Szescian(float kolorSzarosci);
    ~Szescian();
    Szescian* add();
    
    Szescian* setTextureID(GLuint textureID);
    GLuint   getTextureID();

    Szescian* setUseTexture(bool useTexture, GLuint textureID);
    Szescian* setUseTexture(bool useTexture);
    bool    getUseTexture();

    Sciana* getGora() const;
    Sciana* getDol() const;
    Sciana* getLewo() const;
    Sciana* getPrawo() const;
    Sciana* getPrzod() const;
    Sciana* getTyl() const;
    Szescian* setGora(Sciana *gora);

private:
  Sciana *gora;
  Sciana *dol;
  Sciana *lewo;
  Sciana *prawo;
  Sciana *przod;
  Sciana *tyl;
  
  GLuint textureID;
  bool useTexture;
};

#endif
