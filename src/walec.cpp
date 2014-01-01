/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "walec.h"
#include <math.h>

Walec::Walec(int ile)
{
    this->setUzylStos(false);
    n = ile;
    sciany = new Sciana* [ile];
    float d=2*M_PI/n;
    for (int i = 0; i<n; i++){
        sciany[i] = new Sciana(new Punkt(cos(d*i),sin(d*i),0),
                            new Punkt(cos(d*(i+1)),sin(d*(i+1)),0),
                            new Punkt(cos(d*(i+1)),sin(d*(i+1)),1),
                            new Punkt(cos(d*i),sin(d*i),1));
    }
    
    gora = new Okrag(n);
    dol = new Okrag(n);
    dol->reverseNormal();

}

    
Walec::~Walec()
{
}



Obiekt3D* Walec::add()
{
  
  if (useTexture){
    
    dol->add();
    for (int i = 0; i<n; i++)
        sciany[i]->add();
    gora->translate(0,0,1);
    gora->add();
    finishDrawing();
  }else{
    dol->add();
    for (int i = 0; i<n; i++){
      sciany[i]->add();
    }
    gora->translate(0,0,1);
    gora->add();
    finishDrawing();
  }
    return this;
}


Walec* Walec::setTextureID(GLuint textureID){
  this->textureID = textureID;
  return this;
};

GLuint Walec::getTextureID(){
  return textureID;
};

Walec* Walec::setUseTexture(bool useTexture){
  this->useTexture = useTexture;
  return this;
};

bool Walec::getUseTexture(){
  return useTexture;
};

Walec* Walec::setUseTexture(bool useTexture, GLuint textureID){
  this->useTexture = useTexture;
  this->textureID = textureID;
  for (int i = 0; i<n; i++)    sciany[i]->setUseTexture( useTexture,  textureID);
  gora->setUseTexture( useTexture,  textureID);
  dol->setUseTexture( useTexture,  textureID);
  return this;
};


