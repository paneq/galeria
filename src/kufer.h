/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef KUFER_H
#define KUFER_H

#include "obiekt3d.h"
#include "szescian.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Kufer : public Obiekt3D
{
public:
    Kufer(int ile = 20);

    ~Kufer();

    virtual Kufer* add();

    Szescian* pudlo;
    Kufer* setTextureID(GLuint textureID);
    GLuint   getTextureID();

    Kufer* setUseTexture(bool useTexture, GLuint textureID);
    Kufer* setUseTexture(bool useTexture);
    bool    getUseTexture();
    Kufer* setKatOtwarcia(float x = 0);
private:
Sciana** sciany;
 int ile;
 float katOtwarcia;
 GLuint textureID;
 bool useTexture;
};

#endif
