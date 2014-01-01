/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "obiekt3d.h"


Obiekt3D::Obiekt3D()
{
  this->setUzylStos(false);
}


Obiekt3D::~Obiekt3D()
{
}


Obiekt3D* Obiekt3D::rotate(float alfa, float dx, float dy, float dz){
  
  if ( !getUzylStos() ){
    glPushMatrix();
  };
  glRotatef(alfa, dx , dy, dz);
  setUzylStos(true);
  return this;
}

Obiekt3D* Obiekt3D::translate(float dx, float dy, float dz){
  if ( !getUzylStos() ){
    glPushMatrix();
  };
  glTranslatef(dx , dy, dz);
  setUzylStos(true);
  return this;
};

Obiekt3D* Obiekt3D::scale(float sx, float sy, float sz){
    
  if ( !getUzylStos() ){
    glPushMatrix();
  };
  glScalef(sx, sy, sz);
  setUzylStos(true);
  return this;
}

void Obiekt3D::finishDrawing(){
    if ( getUzylStos() ) {
        glPopMatrix();
        setUzylStos(false);
    }
}

void Obiekt3D::setUzylStos(bool uzylStos) {
    this->uzylStos = uzylStos;
}


bool Obiekt3D::getUzylStos() const {
    return uzylStos;
}
