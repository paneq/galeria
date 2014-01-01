/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "okrag.h"
#include <math.h>

Okrag::Okrag(int ile)
{
  this->ile = ile;
  this->n = new Punkt(0,0,1);
  this->setUzylStos(false);
}


Okrag::~Okrag()
{
}


Okrag* Okrag::reverseNormal(){

 n->setZ(-n->getZ());

 return this;
}

Okrag* Okrag::add(){

  if (useTexture){
      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, textureID);
      glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,  GL_EYE_LINEAR);
      static GLfloat mapowanie[] = {1, 0, 0, 0};
      glTexGenfv(GL_S, GL_OBJECT_PLANE, mapowanie);
      glTexGeni(GL_T, GL_TEXTURE_GEN_MODE,  GL_EYE_LINEAR);
      static GLfloat mapowanie2[] = {1, 0, 0, 0};
      glTexGenfv(GL_T, GL_OBJECT_PLANE, mapowanie2);
      glEnable(GL_TEXTURE_GEN_S);
      glEnable(GL_TEXTURE_GEN_T);
      glBegin(GL_POLYGON);
      
      
      glNormal3f( n->getX(), n->getY(), n->getZ());
      float d=2*M_PI/ile;
      for (int i = 0; i<ile; i++){
        glVertex3f(cos(d*i),sin(d*i),0);
      }
      glEnd();
      
      glDisable(GL_TEXTURE_2D);
      glDisable(GL_TEXTURE_GEN_S);
      glDisable(GL_TEXTURE_GEN_T);
      
      
      finishDrawing();
      
      
  }
  
  else
  {
    glBegin(GL_POLYGON);
    glNormal3f( n->getX(), n->getY(), n->getZ());
    float d=2*M_PI/ile;
    for (int i = 0; i<ile; i++){
      glVertex3f(cos(d*i),sin(d*i),0);
    }
    glEnd();
    finishDrawing();
  }
  return this;
}


Okrag* Okrag::defaultTextureUse(){
  this->setUseTexture(false);
  this->textureID = 0 ;
  return this;
}


Okrag* Okrag::setTextureID(GLuint textureID){
  this->textureID = textureID;
  return this;
};

GLuint Okrag::getTextureID(){
  return textureID;
};

Okrag* Okrag::setUseTexture(bool useTexture){
  this->useTexture = useTexture;
  return this;
};

bool Okrag::getUseTexture(){
  return useTexture;
};

Okrag* Okrag::setUseTexture(bool useTexture, GLuint textureID){
  this->useTexture = useTexture;
  this->textureID = textureID;
  return this;
};
