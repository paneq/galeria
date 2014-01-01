/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef OBIEKT3D_H
#define OBIEKT3D_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/

class Obiekt3D{
public:
    Obiekt3D();

    ~Obiekt3D();
    
    virtual Obiekt3D* add() = 0;
    Obiekt3D* translate(float dx, float dy, float dz);
    Obiekt3D* rotate(float alfa, float dx, float dy, float dz);
    Obiekt3D* scale(float sx, float sy, float sz);
  
protected:
    bool uzylStos;

    void setUzylStos(bool uzylStos);
    bool getUzylStos() const;
    void finishDrawing();
};

#endif
