/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "kolumna.h"

Kolumna::Kolumna(int ile, int wysokosc, float r0, float r1)
 : Obiekt3D()
{

  n = ile;
  this->wysokosc = wysokosc;
  sciany = new Sciana* [ile*4];
  float x;
  float y;
  float d=2*M_PI/(n);
  gora = new Walec();
  dol = new Walec();
  
  for (int i = 0; i<n; i+=1){
    
    sciany[4*i+0] = new Sciana(new Punkt(r1*cos(d*i),r1*sin(d*i),0),
                           new Punkt(r0*cos(d*i),r0*sin(d*i),0),
                           new Punkt(r0*cos(d*i),r0*sin(d*i),wysokosc),
                           new Punkt(r1*cos(d*i),r1*sin(d*i),wysokosc));
    
    
    sciany[4*i+1] = new Sciana(new Punkt(r0*cos(d*i),r0*sin(d*i),0),
                               new Punkt(r0*cos(d*(i+0.5)),r0*sin(d*(i+0.5)),0),
                               new Punkt(r0*cos(d*(i+0.5)),r0*sin(d*(i+0.5)),wysokosc),
                               new Punkt(r0*cos(d*i),r0*sin(d*i),wysokosc)); 
    
    sciany[4*i+2] = new Sciana(new Punkt(r1*cos(d*(i+0.5)),r1*sin(d*(i+0.5)),0),
                               new Punkt(r0*cos(d*(i+0.5)),r0*sin(d*(i+0.5)),0),
                               new Punkt(r0*cos(d*(i+0.5)),r0*sin(d*(i+0.5)),wysokosc),
                               new Punkt(r1*cos(d*(i+0.5)),r1*sin(d*(i+0.5)),wysokosc));
   
    sciany[4*i+3] = new Sciana(new Punkt(r1*cos(d*(i+0.5)),r1*sin(d*(i+0.5)),0),
                             new Punkt(r1*cos(d*(i+1)),r1*sin(d*(i+1)),0),
                             new Punkt(r1*cos(d*(i+1)),r1*sin(d*(i+1)),wysokosc),
                             new Punkt(r1*cos(d*(i+0.5)),r1*sin(d*(i+0.5)),wysokosc)); 
    
    
    
    
  }
}


Kolumna::~Kolumna()
{
}


Kolumna* Kolumna::setUseTexture(bool useTexture, GLuint textureID){
  this->useTexture = useTexture;
  gora->setUseTexture(useTexture, textureID);
  dol->setUseTexture(useTexture, textureID);
  for (int i = 0; i<4*n; i++){
    sciany[i]->setUseTexture(useTexture, textureID);
    sciany[i]->setTextureScale(new Punkt(0,0,0), new Punkt(0.5, 3*wysokosc, 0));
  }
  return this;
};

Obiekt3D* Kolumna::add()
{
  
  gora->translate( 0, 0, wysokosc);
  gora->scale(1.7,1.7,0.5);
  gora->add();
  dol->scale(1.7,1.7,0.5);
  dol->add();
  for (int i = 0; i<4*n; i++)
     sciany[i]->add();
  
  finishDrawing();
  return this;
}

