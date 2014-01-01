/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "sciana.h"
#include "punkt.h"



Sciana::Sciana(){

    this->a = new Punkt(-0.5, -0.5, 0);
    this->b = new Punkt(0.5, -0.5, 0);
    this->c = new Punkt(0.5, 0.5, 0);
    this->d = new Punkt(-0.5, 0.5, 0);
    this->n = new Punkt(0,0,-1);
    this->kolor = new Kolor();
    defaultTextureUse();
    defaultTextureScale();
}

Sciana::Sciana(Punkt *a, Punkt *b, Punkt *c, Punkt *d){
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->n = Punkt::normal(a,b,c);
    this->kolor = new Kolor();

    defaultTextureUse();
    defaultTextureScale();
}

Sciana::Sciana(Punkt *a, Punkt *b, Punkt *c, Punkt *d, Kolor *kolor){
    this->a=a;
    this->b=b;
    this->c=c;
    this->d=d;
    this->n=Punkt::normal(a,b,c);
    this->kolor=kolor;

    defaultTextureUse();
    defaultTextureScale();
}


Sciana* Sciana::add(){

    if (useTexture){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glBegin(GL_QUADS);
            glNormal3f( n->getX(), n->getY(), n->getZ());
            glTexCoord2f(teksturaLewyDol->getX(), teksturaLewyDol->getY() );
              glVertex3f(a->getX(), a->getY(), a->getZ());
            glTexCoord2f(teksturaPrawaGora->getX(), teksturaLewyDol->getY() );
              glVertex3f(b->getX(), b->getY(), b->getZ());
            glTexCoord2f(teksturaPrawaGora->getX(), teksturaPrawaGora->getY() );
              glVertex3f(c->getX(), c->getY(), c->getZ());
            glTexCoord2f(teksturaLewyDol->getX(), teksturaPrawaGora->getY() );
              glVertex3f(d->getX(), d->getY(), d->getZ());
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else {
        glBegin(GL_POLYGON);
        glNormal3f( n->getX(), n->getY(), n->getZ());
        glColor4f(kolor->getR(),kolor->getG(),kolor->getB(), kolor->getAlfa() );
            glVertex3f(a->getX(), a->getY(), a->getZ());
            glVertex3f(b->getX(), b->getY(), b->getZ());
            glVertex3f(c->getX(), c->getY(), c->getZ());
            glVertex3f(d->getX(), d->getY(), d->getZ());
        glEnd();
    }
    
    finishDrawing();
    return this;
}

Sciana* Sciana::clone(float dx, float dy, float dz){
  Sciana *nowa = new Sciana(new Punkt(a->getX()+dx, a->getY()+dy, a->getZ()+dz),
                            new Punkt(b->getX()+dx, b->getY()+dy, b->getZ()+dz),
                            new Punkt(c->getX()+dx, c->getY()+dy, c->getZ()+dz),
                            new Punkt(d->getX()+dx, d->getY()+dy, d->getZ()+dz) );

  nowa->setKolor(kolor);
  nowa->setUseTexture(useTexture, textureID);
  return nowa;
}

Sciana* Sciana::reverse(){
  Punkt *d_cpy = new Punkt(d->getX(), d->getY(), d->getZ());
  Punkt *a_cpy = new Punkt(a->getX(), a->getY(), a->getZ());
  
  delete d;
  delete a;
  
  d=c;
  a=b;
  b=a_cpy;
  c=d_cpy;
  return this;
}

Sciana* Sciana::setKolor(Kolor *kolor){
    delete this->kolor;
    this->kolor=kolor;
    return this;
}

Sciana* Sciana::setTextureID(GLuint textureID){
    this->textureID = textureID;
    return this;
};

GLuint Sciana::getTextureID(){
    return textureID;
};

Sciana* Sciana::setUseTexture(bool useTexture){
    this->useTexture = useTexture;
    return this;
};

bool Sciana::getUseTexture(){
    return useTexture;
};

Sciana* Sciana::setUseTexture(bool useTexture, GLuint textureID){
     this->useTexture = useTexture;
     this->textureID = textureID;
     return this;
};



Sciana* Sciana::defaultTextureUse(){
    this->setUseTexture(false);
    this->textureID = 0 ;
    return this;
}

Sciana* Sciana::defaultTextureScale(){
  this-> teksturaLewyDol = new Punkt(0.0f, 0.0f, 0.0f);
  this-> teksturaPrawaGora = new Punkt(1.0f, 1.0f, 0.0f);
  return this;
}

Sciana* Sciana::getTextureScale(Punkt &teksturaLewyDol, Punkt &teksturaPrawaGora){
    teksturaLewyDol.setX( this->teksturaLewyDol->getX() );
    teksturaLewyDol.setY( this->teksturaLewyDol->getY() );
    
    teksturaPrawaGora.setX( this->teksturaPrawaGora->getX() );
    teksturaPrawaGora.setY( this->teksturaPrawaGora->getY() ); 

    return this;
};


Sciana* Sciana::setTextureScale(Punkt *teksturaLewyDol, Punkt *teksturaPrawaGora){
    this->teksturaLewyDol->setX( teksturaLewyDol->getX() )->setY(teksturaLewyDol->getY() );
    this->teksturaPrawaGora->setX( teksturaPrawaGora->getX() )->setY(teksturaPrawaGora->getY() );
    return this;
};

Sciana* Sciana::setAlfa(float const alfa){
    this->kolor->setAlfa(alfa);
    return this;
};

float Sciana::getAlfa(){
    return this->kolor->getAlfa();
};

Sciana* Sciana::setNormalny(Punkt* punkt){
    n = punkt;
    return this;
}

Sciana::~Sciana(){
    /*
    delete a;
    delete b;
    delete c;
    delete d;
    delete kolor;
  */
};

