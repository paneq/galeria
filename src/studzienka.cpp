/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "studzienka.h"
#include <math.h>

float Studzienka::przesuniecie = 0;

Studzienka::Studzienka(float x, float y, float ramka, float wysokoscMurka,
                      int liczbaCykliFal, int dokladnoscNaCykl, float wysokoscFali, float poziomWody) : Obiekt3D(){
     dno = new Szescian(0.3);
     gornyMurek = new Szescian(0.0);
     dolnyMurek = new Szescian(0.1);
     lewyMurek = new Szescian(0.4);
     prawyMurek = new Szescian(0.5);
     this->szerokoscRamka = ramka;
     this->szerokoscX = x;
     this->szerokoscY = y;
     this->wysokoscMurka = wysokoscMurka;
     this->liczbaCykliFal = liczbaCykliFal;
     this->dokladnoscNaCykl = dokladnoscNaCykl;
     this->wysokoscFali =  wysokoscFali;
     this->poziomWody = poziomWody;
}


Studzienka::~Studzienka()
{
}

Szescian* Studzienka::getDno() const {
    return dno;
}

Szescian* Studzienka::getGornyMurek() const {
    return gornyMurek;
}

Szescian* Studzienka::getDolnyMurek() const {
    return dolnyMurek;
}

Szescian* Studzienka::getLewyMurek() const {
    return lewyMurek;
}

Szescian* Studzienka::getPrawyMurek() const {
    return prawyMurek;
}

Studzienka* Studzienka::add() {
    dno->scale( szerokoscX, szerokoscY, 0.5f );
    dno->add();
    
    gornyMurek->translate( 0.0f, 0.5*szerokoscY  + 0.5*szerokoscRamka, 0.0f );
    gornyMurek->scale( szerokoscX + szerokoscRamka * 2, szerokoscRamka, wysokoscMurka);
    gornyMurek->add();
    
    dolnyMurek->translate( 0.0f, -0.5*szerokoscY  - 0.5*szerokoscRamka, 0.0f );
    dolnyMurek->scale( szerokoscX + szerokoscRamka * 2, szerokoscRamka, wysokoscMurka);
    dolnyMurek->add();
    
    lewyMurek->translate( -0.5*szerokoscX - 0.5*szerokoscRamka, 0.0f, 0.0f );
    //lewyMurek->rotate(90, 0.0f, 0.0f, 1.0f); 
    lewyMurek->scale(szerokoscRamka, szerokoscY, wysokoscMurka);
    lewyMurek->add();
    
    prawyMurek->translate( 0.5*szerokoscX + 0.5*szerokoscRamka, 0.0f, 0.0f );
    //prawyMurek->rotate(90, 0.0f, 0.0f, 1.0f); 
    prawyMurek->scale(szerokoscRamka, szerokoscY, wysokoscMurka);
    prawyMurek->add();
    
    //Sciana *pedzelSciany = new Sciana();
    int a = liczbaCykliFal;
    int b= dokladnoscNaCykl;
    int c= a*b;
    float pr = przesuniecie;
    float pw = poziomWody;
    float wf = wysokoscFali;
    float sc = szerokoscX / c;
    float dc = szerokoscY / c;

    glPushMatrix();
    glTranslatef(-0.5*szerokoscX, -0.5*szerokoscY,0);
    //glColor4f(0.0f, 0.0f, 0.4f, 0.2f);
  //  glColorMaterial(GL_FRONT_AND_BACK,GL_EMISSION);
  //  glEnable( GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++) {
            Punkt *a1 = new Punkt(sc*i, dc *j, pw +  wf* (sin(sc*i + pr) + sin(dc * j + pr) ) );
            Punkt *b1 = new Punkt(sc*(i+1), dc *j, pw +  wf*(sin(sc* (i+1) +pr) + sin(dc * j +pr) ) );
            Punkt *c1 = new Punkt(sc*(i+1), dc *(j+1), pw +  wf*(sin(sc*(i+1) +pr) + sin(dc * (j+1) +pr) ) );
            Punkt *d1 = Punkt::normal( a1, b1, c1);
            glBegin(GL_QUADS);
            
             
               // glColor4f(0.0f, 0.0f, 0.4f, 0.2f);
                //glColor3f(0.0f, 0.0f, 0.4f);
                glNormal3f(d1->getX(), d1->getY(), d1->getZ());
                glVertex3f(a1->getX(), a1->getY(), a1->getZ());
                glVertex3f(b1->getX(), b1->getY(), b1->getZ());
                glVertex3f(c1->getX(), c1->getY(), c1->getZ());
                //glVertex3f(sc*i, dc *j, pw +  wf* (sin(sc*i + pr) + sin(dc * j + pr) ) );
                //glVertex3f(sc*(i+1), dc *j, pw +  wf*(sin(sc* (i+1) +pr) + sin(dc * j +pr) ) );
                //glVertex3f(sc*(i+1), dc *(j+1), pw +  wf*(sin(sc*(i+1) +pr) + sin(dc * (j+1) +pr) ) );
                glVertex3f(sc*i, dc *(j+1), pw +  wf*(sin(sc*i +pr) + sin(dc * (j+1) +pr) ) );
                
            glEnd();
            delete a1;
            delete b1;
            delete c1;
            delete d1;
        }
    }
 //   glDisable( GL_COLOR_MATERIAL);
  //  glColor4f(1.0f, 1.0f, 1.f, 0.0f);
   glDisable(GL_BLEND);
    glPopMatrix();
    finishDrawing();
    przesuniecie += 0.03;
    return this;
}

void Studzienka::setPrzesuniecie(float theValue)
{
  przesuniecie = theValue;
}
