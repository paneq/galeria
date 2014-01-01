/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "szescian.h"
#define SZESCIAN_STALA_SZAROSCI     0.08

Szescian::Szescian(){
    this->dol= new Sciana();
    this->dol->setNormalny(new Punkt(0.0f, 0.0f, -1.0f ) );
    
    this->gora = this->dol->clone(0,0,1);
    this->gora->setNormalny(new Punkt(0.0f, 0.0f, 1.0f ) );
    
    Sciana *srodek = new Sciana(new Punkt(0, -0.5, 0),
                               new Punkt(0, -0.5, 1),
                               new Punkt(0, 0.5, 1),
                               new Punkt(0, 0.5, 0) );
    
    
    this->lewo = srodek->clone(-0.5, 0, 0);
    this->lewo->setNormalny(new Punkt(-1.0f, 0.0f, 0.0f ) );
    this->prawo = srodek->clone(0.5, 0, 0);
    this->prawo->setNormalny(new Punkt(1.0f, 0.0f, 0.0f ) );
    delete srodek;
    
    
    srodek = new Sciana(new Punkt(0.5, 0, 0),
                        new Punkt(0.5, 0, 1),
                        new Punkt(-0.5, 0, 1),
                        new Punkt(-0.5, 0, 0) );
    this->przod = srodek->clone(0, -0.5, 0);
    this->przod->setNormalny(new Punkt(0.0f, -1.0f, 0.0f ) );
    this->tyl = srodek->clone(0, 0.5, 0);
    this->tyl->setNormalny(new Punkt(0.0f, 1.0f, 0.0f ) );

    
    delete srodek;
}

Szescian::Szescian(float kolorSzarosci){
    

    this->dol= new Sciana();
    dol->setKolor(new Kolor(kolorSzarosci, kolorSzarosci, kolorSzarosci) );
    
    this->gora = this->dol->clone(0,0,1);
    gora->setKolor(new Kolor(kolorSzarosci + SZESCIAN_STALA_SZAROSCI,
                            kolorSzarosci + SZESCIAN_STALA_SZAROSCI,
                            kolorSzarosci + SZESCIAN_STALA_SZAROSCI) );
    
    Sciana *srodek = new Sciana(new Punkt(0, -0.5, 0),
                                new Punkt(0, -0.5, 1),
                                new Punkt(0, 0.5, 1),
                                new Punkt(0, 0.5, 0) );
    this->lewo = srodek->clone(-0.5, 0, 0);
    this->prawo = srodek->clone(0.5, 0, 0);

    lewo->setKolor(new Kolor(kolorSzarosci + 2*SZESCIAN_STALA_SZAROSCI,
                   kolorSzarosci + 2*SZESCIAN_STALA_SZAROSCI,
                   kolorSzarosci + 2*SZESCIAN_STALA_SZAROSCI) );

    prawo->setKolor(new Kolor(kolorSzarosci + 3*SZESCIAN_STALA_SZAROSCI,
                   kolorSzarosci + 3*SZESCIAN_STALA_SZAROSCI,
                   kolorSzarosci + 3*SZESCIAN_STALA_SZAROSCI) );
    
    delete srodek;
    
    
    srodek = new Sciana(new Punkt(0.5, 0, 0),
                        new Punkt(0.5, 0, 1),
                        new Punkt(-0.5, 0, 1),
                        new Punkt(-0.5, 0, 0) );
    this->przod = srodek->clone(0, -0.5, 0);
    this->tyl = srodek->clone(0, 0.5, 0);

    przod->setKolor(new Kolor(kolorSzarosci + 4*SZESCIAN_STALA_SZAROSCI,
                   kolorSzarosci + 4*SZESCIAN_STALA_SZAROSCI,
                   kolorSzarosci + 4*SZESCIAN_STALA_SZAROSCI) );

    tyl->setKolor(new Kolor(kolorSzarosci + 5*SZESCIAN_STALA_SZAROSCI,
                   kolorSzarosci + 5*SZESCIAN_STALA_SZAROSCI,
                   kolorSzarosci + 5*SZESCIAN_STALA_SZAROSCI) );

    
    this->dol->setNormalny(new Punkt(0.0f, 0.0f, -1.0f ) );
    this->gora->setNormalny(new Punkt(0.0f, 0.0f, 1.0f ) );
    this->lewo->setNormalny(new Punkt(-1.0f, 0.0f, 0.0f ) );
    this->prawo->setNormalny(new Punkt(1.0f, 0.0f, 0.0f ) );
    this->przod->setNormalny(new Punkt(0.0f, -1.0f, 0.0f ) );
    this->tyl->setNormalny(new Punkt(0.0f, 1.0f, 0.0f ) );
    
    delete srodek;
}

Szescian::Szescian(     Sciana *gora,
                        Sciana *dol,
                        Sciana *lewo,
                        Sciana *prawo,
                        Sciana *przod,
                        Sciana *tyl) {

  this->gora=gora;
  this->dol=dol;
  this->lewo=lewo;
  this->prawo=prawo;
  this->przod=przod;
  this->tyl=tyl;

}

Szescian* Szescian::add(){
  if (gora) gora->add();
  if (dol) dol->add();
  if (lewo) lewo->add();
  if (prawo) prawo->add();
  if (przod) przod->add();
  if (tyl) tyl->add();
  finishDrawing();
  return this;
}

Szescian* Szescian::setTextureID(GLuint textureID){
  this->textureID = textureID;
  gora->setTextureID( textureID);
  dol->setTextureID( textureID);
  lewo->setTextureID( textureID);
  prawo->setTextureID( textureID);
  przod->setTextureID( textureID);
  tyl->setTextureID( textureID);
  return this;
};

GLuint Szescian::getTextureID(){
  return textureID;
};

Szescian* Szescian::setUseTexture(bool useTexture){
  this->useTexture = useTexture;
  if (gora) gora->setUseTexture( useTexture);
  if (dol) dol->setUseTexture( useTexture);
  if (lewo) lewo->setUseTexture( useTexture);
  if (prawo) prawo->setUseTexture( useTexture);
  if (przod) przod->setUseTexture( useTexture);
  if (tyl) tyl->setUseTexture( useTexture);
  return this;
};

bool Szescian::getUseTexture(){
  return useTexture;
};

Szescian* Szescian::setUseTexture(bool useTexture, GLuint textureID){
  this->useTexture = useTexture;
  this->textureID = textureID;
  if (gora) gora->setUseTexture( useTexture,  textureID);
  if (dol) dol->setUseTexture( useTexture,  textureID);
  if (lewo) lewo->setUseTexture( useTexture,  textureID);
  if (prawo) prawo->setUseTexture( useTexture,  textureID);
  if (przod) przod->setUseTexture( useTexture,  textureID);
  if (tyl) tyl->setUseTexture( useTexture,  textureID);
  return this;
};

Szescian::~Szescian()
{     
// delete dol;
// delete gora;
// delete lewo;
// delete prawo;
// delete przod;
// delete tyl;
        
}

    Sciana* Szescian::getGora() const
    {
      return gora;
    }

    Sciana* Szescian::getDol() const
    {
      return dol;
    }

    Sciana* Szescian::getLewo() const
    {
      return lewo;
    }

    Sciana* Szescian::getPrawo() const
    {
      return prawo;
    }

    Sciana* Szescian::getPrzod() const
    {
      return przod;
    }

    Sciana* Szescian::getTyl() const
    {
      return tyl;
    }



    Szescian* Szescian::setGora(Sciana *gora){
      this->gora = gora;
      return this;
    }
