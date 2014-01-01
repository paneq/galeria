/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>

#include <math.h>

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "sciana.h"
#include "szescian.h"
#include "kula.h"
#include "tekstury.h"
#include "swiat.h"
#include "spodek.h"
#include "okrag.h"
#include "walec.h"
#include "fotel.h"
#include "obraz.h"
#include "szafa.h"
#include "kolumna.h"
#include "kufer.h"
#include "studzienka.h"

using namespace std;

void scena(void);
void anim(void);
void init(void);
void klawiatura(unsigned char kod_klawisza, int x, int y);
void klawiaturaSpec(int kodKlawisza, int X, int Y);
void mysz(int przycisk, int stan, int x, int y);
void myszRuchPrzycisk(int x, int y);
void myszRuchBezPrzycisku(int x, int y);


void tworzenieSwiata();
void texturesSetup();
void odrysujMenu();


const float delta_alfa=0.5;
float licznik = 0;
float alfa=0.0;

float skadX=-5;
float skadY=-5;
float skadZ=10;

float naCoX=-1;
float naCoY=-1;
float naCoZ=0;

const float PI = 3.1415926535897;
const float STALA_BOK = 0.25;
const float PRZESUN = 1;
int buttonDown;
float mouseX;
float mouseY;
bool lightON = true;
bool kuferON = false;
bool szafaON = false;
bool swiatlo1ON = true;
bool swiatlo2ON = true;
bool swiatlo3ON = false;


#define ESCAPE 27

int window; 

bool up = true;


float E_d[4] = {1, 1, 1, 1.0};//wektor energii diffuse
float E_s[4] = {0.0, 0.0, 0.0, 1.0};//wektor energii specular
float E_a[4] = {0, 0, 0, 1.0};//wektor energii ambient

float E_d2[4] = {1.0, 1.0, 1.0, 1.0};//wektor energii diffuse
float E_s2[4] = {0.0, 0.0, 0.0, 1.0};//wektor energii specular
float E_a2[4] = {1, 1, 1, 1.0};//wektor energii ambient

//tekstury
const int LICZBA_TEKSTUR = 24;
GLuint textures[LICZBA_TEKSTUR];
char* texturesPathes[LICZBA_TEKSTUR]={
    "../../src/menu.bmp",       //0
    "../../src/inne.bmp",       //1
    "../../src/kafelek.bmp",    //2
    "../../src/obraz_2.bmp",    //3
    "../../src/leweDrzwi.bmp",  //4
    "../../src/crate.bmp",      //5
    "../../src/ziemia.bmp",     //6
    "../../src/woda.bmp",       //7
    "../../src/sur02.bmp",      //8
    "../../src/drewno.bmp",     //9
    "../../src/lava.bmp",       //10
    "../../src/stars.bmp",      //11
    "../../src/praweDrzwi.bmp", //12
    "../../src/srodekSzafa.bmp",//13
    "../../src/szafaGora.bmp",  //14
    "../../src/woda_mala.bmp",   //15
    "../../src/obraz1.bmp",   //16
    "../../src/obraz2.bmp",   //17
    "../../src/obraz3.bmp",   //18
    "../../src/obraz4.bmp",   //19
    "../../src/obraz5.bmp",   //20
    "../../src/obraz6.bmp",   //21
    "../../src/obraz7.bmp",   //22
    "../../src/obraz8.bmp"   //23
};



//swiat
Swiat *swiat;


int main(int argc, char *argv[]){
  
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH );
    glutInitWindowSize(800,600);
    glutInitWindowPosition(300,30);
    window = glutCreateWindow("Galeria");
    glutDisplayFunc(scena);
    glutFullScreen();
    glutIdleFunc(anim);
    glutKeyboardFunc(klawiatura);
    glutSpecialFunc(klawiaturaSpec);
    glutMouseFunc(mysz);
    glutMotionFunc(myszRuchPrzycisk);
    glutPassiveMotionFunc(myszRuchBezPrzycisku);
    init();

    glutMainLoop();
}


void init(){
  texturesSetup();
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_LIGHTING);
    glClearColor(0.0,0.0,0.0,1.0);
    glClearDepth(1.0);             
    glDepthFunc(GL_LESS);          
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_NORMALIZE);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    skadX= -50.0f;
    skadY= -0.0f;
    skadZ= 15.0f;

    naCoX=0.0f;
    naCoY=0.0f;
    naCoZ=0.0f;


    tworzenieSwiata(); // dzien 1
 
}

void texturesSetup(){
  
  glGenTextures(LICZBA_TEKSTUR,&textures[0]);    //generowanie tekstur, wszystkich od razu

  for(int licz = 0; licz < LICZBA_TEKSTUR; licz++){
    loadTexture(texturesPathes[licz], textures[licz]); //wczytywanie tekstur z plikudo pamieci, oraz wywolanie glTexImage2D(..)
  }
  
}



void tworzenieSwiata(){
    swiat = new Swiat();
    
    
    Szescian* sze = new Szescian(/*0.2*/);
    swiat->addToSwiat(1,sze);
    

    Kula* kula = new Kula();
    swiat->addToSwiat(3,kula);
    
    Sciana *podloga = new Sciana(new Punkt(-100, -100, 0),
                                   new Punkt(100, -100, 0),
                                   new Punkt(100, 100, 0),
                                   new Punkt(-100, 100, 0)
                                  );
   
    podloga->setNormalny(new Punkt(0.0f, 0.0f, 1.0f));
    podloga->setUseTexture(true, textures[2]);
    podloga->setTextureScale(new Punkt(0.0f, 0.0f, 0.0f),
                             new Punkt(20.0f, 20.0f, 0.0f)
                            );
    
    swiat->addToSwiat(8, podloga);

    
    
    Obraz *dzielo = new Obraz(16.0f, 16.0f, 1.0f);
    dzielo->getGornaRama()->setUseTexture(true, textures[9]);
    dzielo->getDolnaRama()->setUseTexture(true, textures[9]);
    dzielo->getLewaRama()->setUseTexture(true, textures[9]);
    dzielo->getPrawaRama()->setUseTexture(true, textures[9]);
    dzielo->getObrazek()->getGora()->setUseTexture(true, textures[3]);
    swiat->addToSwiat(9, dzielo);

    
    Szafa *szafa = new Szafa(2.0f, 4.0f, 4.0f, 10.0f, 0.5f);
    szafa->getLeweDrzwi()
        ->setUseTexture(true, textures[4])
        ->setTextureScale( new Punkt(0.0f, 0.25f, 0.0f), new Punkt(0.9296875f, 1.0f, 0.0f) );
    szafa->getPraweDrzwi()->setUseTexture(true, textures[12] );
    szafa->getLewo()->setUseTexture(true, textures[13] );
    szafa->getPrawo()->setUseTexture(true, textures[13] );
    szafa->getTyl()->setUseTexture(true, textures[13] );
    szafa->getGora()->setUseTexture(true, textures[13] );
    szafa->getDol()->setUseTexture(true, textures[13] );
    szafa->getDolneWyniesienie()->setUseTexture(true, textures[14] );
    szafa->getGorneWyniesienie()->setUseTexture(true, textures[14] );
    swiat->addToSwiat(10, szafa);
    
    

    
    Kolumna *kolumna = new Kolumna(6,30);
    swiat->addToSwiat(13,kolumna);


    Kufer  *kufer = new Kufer();
    swiat->addToSwiat(14,kufer);
    
    Studzienka *studzienka = new Studzienka();
    studzienka->getDno()->getGora()->setUseTexture(true, textures[15]);
    swiat->addToSwiat(15, studzienka);
}



void scena(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f,(GLfloat)1024/(GLfloat)768,0.1f,1000.0f);
    gluLookAt(skadX, skadY, skadZ, naCoX, naCoY, naCoZ, 0.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    float x = (int)alfa % (300);
    float y = 15*sin(2*PI*alfa/60);
    if ((x>=0)&&(x<150)) up = true;
    if ((x>=150)&&(x<300)) up=false;
    if (!up) x = 300 - x;
    float P[4] = {x - 75, 50 + y, 42, 1};
    float P2[4] = {x - 75, -50 + y, 42, 1};
    float P3[4] = {50, 0, 30, 1};

    glLightfv(GL_LIGHT0, GL_POSITION, P);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, E_d);
    glLightfv(GL_LIGHT0, GL_SPECULAR, E_s);
    glLightfv(GL_LIGHT0, GL_AMBIENT, E_a);
    
    glLightfv(GL_LIGHT1, GL_POSITION, P2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, E_d);
    glLightfv(GL_LIGHT1, GL_SPECULAR, E_s);
    glLightfv(GL_LIGHT1, GL_AMBIENT, E_a);
    
    glLightfv(GL_LIGHT2, GL_POSITION, P3);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, E_d2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, E_s2);
    glLightfv(GL_LIGHT2, GL_AMBIENT, E_a2);
    
  
    
  
    
    
    if (swiatlo1ON) 
      glEnable(GL_LIGHT0); 
    else 
      glDisable(GL_LIGHT0);
    
    
    if (swiatlo2ON) 
      glEnable(GL_LIGHT1); 
    else 
      glDisable(GL_LIGHT1);
    
    
    if (swiatlo3ON) 
      glEnable(GL_LIGHT2); 
    else 
      glDisable(GL_LIGHT2);
    
    
    
    Kula* kula = swiat->getKula(3);
    
    
    kula->translate(x - 75, 50 + y, 45);
    kula->scale(5,5,5)  ;
    kula->add();
    
    
    kula->translate(x - 75, -50 + y, 45);
    kula->scale(5,5,5)  ;
    kula->add();
    

    Szescian* sze = swiat->getSzescian(1);
    
      sze->translate(-60.0f, 50.0f, 70.0f);
      sze->scale(2, 2, 2);
      sze->rotate(1.5*alfa, 0, 0, 1);            
      sze->translate(3, 0, 0);
      sze->rotate(0.9*alfa, 0, 0, 1);
      sze->rotate(0.45*alfa, 0, 1, 0);
      sze->rotate(0.6*alfa, 1, 0, 0);
      sze->setUseTexture(true,textures[8]);
      sze->add();                       
    

      sze->setUseTexture(true,textures[5]);
      sze->translate(-50,1,0.1);
      sze->add(); 
      
      sze->setUseTexture(true,textures[5]);
      sze->translate(-50,2,0.1);
      sze->add(); 
      
      
      sze->setUseTexture(true,textures[5]);
      sze->translate(-50,3,0.1);
      sze->add(); 
      
      sze->setUseTexture(true,textures[5]);
      sze->translate(-50,4,0.1);
      sze->add(); 
      
      
      sze->setUseTexture(true,textures[5]);
      sze->translate(-49,1.5,0.1);
      sze->add(); 
      
      sze->setUseTexture(true,textures[5]);
      sze->translate(-49,2.5,0.1);
      sze->add(); 
      
      sze->setUseTexture(true,textures[5]);
      sze->translate(-49,3.5,0.1);
      sze->add(); 
      
      
      sze->setUseTexture(true,textures[5]);
      sze->translate(-49.5,2,1.1);
      sze->add(); 
      
      sze->setUseTexture(true,textures[5]);
      sze->translate(-49.5,3,1.1);
      sze->add(); 
      
      
     sze->setUseTexture(true,textures[5]);
     sze->translate(-49.5,2.5,2.1);
     sze->add(); 
      
      




   
    Kufer *kufer = reinterpret_cast<Kufer *> (swiat->getElement(14));
    if (kuferON) kufer->setKatOtwarcia(-90 - 90*sin(0.05*licznik));
    kufer->translate( -50, 3, 0.1);
    kufer->scale(3,3.5,3);
    kufer->rotate(90,0,0,1);
    kufer->setUseTexture( true, textures[5]);
    kufer->add();


     Obiekt3D *podloga = swiat->getElement(8);
     podloga->add();

    
     Obraz *dzielo = reinterpret_cast<Obraz *> (swiat->getElement(9));

      dzielo->translate(-45.0f, 50.0f, 10.0f);
      dzielo->rotate(0,0,0,1)           ;
      dzielo->getObrazek()->getGora()->setUseTexture(true, textures[16]);
      dzielo->add();
      
      
      dzielo->translate(-45, -50.0f, 10.0f);
      dzielo->rotate(180,0,0,1)           ;
      dzielo->getObrazek()->getGora()->setUseTexture(true, textures[17]);
      dzielo->add();
      
      
      dzielo->translate(-15, 50.0f, 10.0f);
      dzielo->rotate(0,0,0,1)           ;
      dzielo->getObrazek()->getGora()->setUseTexture(true, textures[18]);
      dzielo->add();
      
      
      dzielo->translate(-15, -50.0f, 10.0f);
      dzielo->rotate(180,0,0,1)           ;
      dzielo->getObrazek()->getGora()->setUseTexture(true, textures[19]);
      dzielo->add();
      
      
      dzielo->translate(15, 50.0f, 10.0f);
      dzielo->rotate(0,0,0,1)           ;
      dzielo->getObrazek()->getGora()->setUseTexture(true, textures[20]);
      dzielo->add();
      
      
      dzielo->translate(15, -50.0f, 10.0f);
      dzielo->rotate(180,0,0,1)           ;
      dzielo->getObrazek()->getGora()->setUseTexture(true, textures[21]);
      dzielo->add();
      
      
      dzielo->translate(45, 50.0f, 10.0f);
      dzielo->rotate(0,0,0,1)           ;
      dzielo->getObrazek()->getGora()->setUseTexture(true, textures[22]);
      dzielo->add();
      
      dzielo->translate(45, -50.0f, 10.0f);
      dzielo->rotate(180,0,0,1)           ;
      dzielo->getObrazek()->getGora()->setUseTexture(true, textures[23]);
      dzielo->add();
      
// // 
      Szafa *szafa = reinterpret_cast< Szafa* >(swiat->getElement(10) );
      szafa->translate(60,0,0.2);
      if (szafaON) 
        szafa
            ->setKatOtwarciaL( 45 + 45*sin(0.05*licznik) )
            ->setKatOtwarciaP(90 + 90*sin(0.03*licznik) );
      szafa->rotate(-90,0,0,1);
      szafa->scale(3,3,3);
      szafa->add();

      
     Kolumna *kolumna = reinterpret_cast< Kolumna* >(swiat->getElement(13));   
     
      kolumna->setUseTexture(true, textures[8]);
      kolumna->translate(0, -50, 0.1)    ;
      kolumna->scale(4,4,3);
      kolumna->add();

      kolumna->translate(0, 50, 0.1)    ;
      kolumna->scale(4,4,3);
      kolumna->add();
      
      kolumna->translate(30, 50, 0.1)    ;
      kolumna->scale(4,4,3);
      kolumna->add();
      
      kolumna->translate(30, -50, 0.1)    ;
      kolumna->scale(4,4,3);
      kolumna->add();
      

      kolumna->translate(60, 50, 0.1)    ;
      kolumna->scale(4,4,3);
      kolumna->add();
      
      kolumna->translate(60, -50, 0.1)    ;
      kolumna->scale(4,4,3);
      kolumna->add();
      
      kolumna->translate(-30, 50, 0.1)    ;
      kolumna->scale(4,4,3);
      kolumna->add();
      
      kolumna->translate(-30, -50, 0.1)    ;
      kolumna->scale(4,4,3);
      kolumna->add();
      
      kolumna->translate(-60, 50, 0.1)    ;
      kolumna->scale(4,4,3);
      kolumna->add();
      
      kolumna->translate(-60, -50, 0.1)    ;
      kolumna->scale(4,4,3);
      kolumna->add();
      
      
      Studzienka *studzienka = reinterpret_cast< Studzienka* >( swiat->getElement(15) );
      studzienka->add();

          


      GLUquadricObj *obj;
      obj=gluNewQuadric();
      gluQuadricTexture(obj,GL_TRUE);
      glBindTexture(GL_TEXTURE_2D,textures[11]);
      glMatrixMode(GL_TEXTURE); //przej�cie na stos tekstur
      glPushMatrix();
      glScalef(15,15,1);//skalowanie tekstury    
      glEnable(GL_TEXTURE_2D );
      float kulaInfo[] ={0.7f, 0.7f, 0.9f, 1.0f };
      glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,kulaInfo);
      gluSphere(obj,400,15,7);
      glPopMatrix();
      float kulaInfo2[] ={0.0f, 0.0f, 0.0f, 1.0f };
      glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,kulaInfo2);
      glMatrixMode(GL_MODELVIEW);//powr�t na stos modelview


     odrysujMenu();


    
    glFlush();
    glutSwapBuffers();

}


void anim(){
  alfa+=delta_alfa;
  licznik++;
  glutPostRedisplay();
}


void odrysujMenu() {
        // Na samym koncu rysowania sceny rysujemy menu:
    glMatrixMode(GL_PROJECTION); // przelacz na tryb "edycji" macierzy pojekcji


/* Ponizej - zamiast perspektywy mamy rzut prostokątny - tzn w
    perspektywie wszysto to co jest dalej jest mniejsze - tutaj nie!
    Dzieki czemu nie istotna jest wartość z-ta (oczywiscie gdy kamera jest
    skierowana w kierunku oddatnim lub ujemnym osi z (tak jest np. gdy
    zrobimy glLoadIdentity();   )

    Ustawiamy bryle widzenia na kostke takza ze x,y,z nalezy doprzedzialu
    [-1,1]. Czyli srodek kostki jest w zerze. Uwaga wszystko co zostanie
    narysowane w openGL'u poza tą kostka nie bedize widoczne.
*/
    glPushMatrix();
    glLoadIdentity();
    glOrtho(  -1,1  ,-1,1   ,-1,1 );

    /* Teraz przejdzmy do macierzy widoku*/

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST); // Wylacz test glebokosci - rysuj na wierzchu
    /*
    W TYM MIEJSCU RYSUJEMY KWADRATY PROSTOPADLE DO OSI Z
    OTEXTUROWANE ODPOWIEDNIMI MENUSAMI. PAMIETAJ ZE KWADRATY
    MUSZA LEZEC WEWNOTRZ KOSTKI [-1,1]x[-1,1]x[-1,1] !
    */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
     
   
    glEnable(GL_BLEND);      
    glBegin(GL_QUADS);
     glTexCoord2f(0.0f, 0.0f);
      glVertex3f(0.4, 0.4, 0.0);
     glTexCoord2f(1.0f, 0.0f);
      glVertex3f(0.9, 0.4, 0.0);
     glTexCoord2f(1.0f, 1.0f);
      glVertex3f(0.9, 0.9, 0.0);
     glTexCoord2f(0.0f, 1.0f);
      glVertex3f(0.4, 0.9, 0.0);
    glEnd();
    glDisable(GL_BLEND);
   

    glEnable(GL_DEPTH_TEST); // Wlacz spowrotem test glebokosci
    glPopMatrix(); // Przywroc stara macierz widoku

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();     // Przywroc stara macierz projekcji

    glMatrixMode(GL_MODELVIEW);   // ustaw na tryb pracy na macierzy
}

void klawiatura(unsigned char kodKlawisza, int x, int y){
    
    switch (kodKlawisza){
        case 'q' :
            skadX+= 0.1;
            break;
        case 'w' :
            skadX-= 0.1;
            break;

        case 'a' :
            skadY+= 0.1;
            break;
        case 's' :
            skadY-= 0.1;
            break;

        case 'z' :
            skadZ+= 0.1;
            break;
            
        case 'x' :
            skadZ-= 0.1;
            break;
        case 'l' : {
            if (!lightON)
            {
              glDisable(GL_LIGHTING);
              
            }
            else
            {
              glEnable(GL_LIGHTING);
            }
            lightON=!lightON;
            } break;
            
        case 'k' : kuferON=!kuferON; break;
        case 'i' : szafaON=!szafaON; break;
        
        case '1': swiatlo1ON=!swiatlo1ON; break;
        case '2': swiatlo2ON=!swiatlo2ON; break;
        case '3': swiatlo3ON=!swiatlo3ON; break;
        
        case ESCAPE:   { 
          glutDestroyWindow(window); 
          exit(0);                   
        } break;
        
            
        case 'o' :
        case 'p' :
            float x1 ;
            float y1 ;

            float x2;
            float y2;

            float dlugosc;
            float sinAlfa;
            float arcus;

            float przesuniecie;
            float nowyKat;
            x1 = skadX;
            y1 = skadY;

            x2 = naCoX;
            y2 = naCoY;

            dlugosc = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
            sinAlfa = (y2-y1) / dlugosc;
            arcus = asin(sinAlfa);

            przesuniecie = M_PI / 36 ; //5 stopni;
            if (kodKlawisza == 'o')
                if (x2 >= x1)
                    nowyKat = arcus + przesuniecie;
                else
                    nowyKat = M_PI - arcus + przesuniecie;
            else
                if (x2 > x1)
                    nowyKat = arcus - przesuniecie;
                else
                    nowyKat = M_PI - arcus - przesuniecie;
            
            x2 = cos(nowyKat)*dlugosc + x1;
            y2 = sin(nowyKat)*dlugosc + y1;
            
            naCoX = x2;
            naCoY = y2;

            std::cout << "dlugosc:  " << dlugosc << std::endl;
            std::cout << "sinAlfa:  " << sinAlfa << std::endl;
            std::cout << "arcus:  " << arcus << std::endl << std::endl;
            
            std::cout << "skadX:  " << skadX << std::endl;
            std::cout << "skadY:  " << skadY << std::endl;
            std::cout << "naCoX:  " << naCoX << std::endl;
            std::cout << "naCoY:  " << naCoY << std::endl << std::endl;
            break;
        

    }
}



void klawiaturaSpec(int kodKlawisza, int X, int Y){
    float x1 = skadX;
    float y1 = skadY;

    float x2 = naCoX;
    float y2 = naCoY;

    float ax = x2-x1;
    float ay = y2-y1;
    float bx = -ay;
    float by = ax;


    float k = 1.0; //wspolczynik szybkosci przemieszczania :-)
    switch (kodKlawisza) {
        case GLUT_KEY_LEFT:{
            float b_len = sqrt(bx*bx + by*by);
            skadX = x1 + (bx / b_len)*k;
            skadY = y1 + (by / b_len)*k;
            break;
            }
        case GLUT_KEY_RIGHT:{
            float b_len = sqrt(bx*bx + by*by);
            skadX = x1 + (-bx / b_len)*k;
            skadY = y1 + (-by / b_len)*k;
            break;
            }
        case GLUT_KEY_UP: {
            float a_len = sqrt(ax*ax + ay*ay);
            skadX = x1 + (ax / a_len)*k;
            skadY = y1 + (ay / a_len)*k;
            break;
        }
        case GLUT_KEY_DOWN: {
            float a_len = sqrt(ax*ax + ay*ay);
            skadX = x1 + (-ax / a_len)*k;
            skadY = y1 + (-ay / a_len)*k;
            break;
        }

        
        default:
            return;
    }

    naCoX = skadX + ax;
    naCoY = skadY + ay;
    return;
}

void mysz(int przycisk, int stan, int x, int y) {
    mouseX=x;
    mouseY=y;
    if (stan == GLUT_DOWN) {
        switch (przycisk) {
            case GLUT_LEFT_BUTTON:
                buttonDown=GLUT_LEFT_BUTTON;
                break;
            case GLUT_MIDDLE_BUTTON:
                skadX = 5;
                skadY = 5;
                skadZ = 5;
                naCoX = 0;
                naCoY = 0;
                naCoZ = 0;
                break;
            case GLUT_RIGHT_BUTTON:
                buttonDown=GLUT_RIGHT_BUTTON;
                break;
        }
    }
    else if (stan == GLUT_UP){
        buttonDown=0;
        switch (przycisk) {
            case GLUT_LEFT_BUTTON:
                break;
            case GLUT_MIDDLE_BUTTON:
                break;
            case GLUT_RIGHT_BUTTON:
                break;
        }
    }
}

void myszRuchPrzycisk(int x, int y){
    switch (buttonDown){
    
        case GLUT_LEFT_BUTTON :
            float x1 ;
            float y1 ;

            float x2;
            float y2;

            float dlugosc;
            float sinAlfa;
            float arcus;

            float przesuniecie;
            float nowyKat;
            x1 = skadX;
            y1 = skadY;

            x2 = naCoX;
            y2 = naCoY;

            dlugosc = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
            sinAlfa = (y2-y1) / dlugosc;
            arcus = asin(sinAlfa);

            przesuniecie = (M_PI / 180)*2*(mouseX - x) ; //2 stopnie na piksel obraca;
            if (x2 > x1)
                nowyKat = arcus + przesuniecie;
            else
                nowyKat = M_PI - arcus + przesuniecie;

            x2 = cos(nowyKat)*dlugosc + x1;
            y2 = sin(nowyKat)*dlugosc + y1;
            naCoX = x2;
            naCoY = y2;
            
            mouseX=x;
            mouseY=y;
            #ifdef GALERIA_DEBUG 
            std::cout << "dlugosc:  " << dlugosc << std::endl;
            std::cout << "sinAlfa:  " << sinAlfa << std::endl;
            std::cout << "arcus:  " << arcus << std::endl << std::endl;
            
            std::cout << "skadX:  " << skadX << std::endl;
            std::cout << "skadY:  " << skadY << std::endl;
            std::cout << "naCoX:  " << naCoX << std::endl;
            std::cout << "naCoY:  " << naCoY << std::endl << std::endl;
            #endif // GALERIA_DEBUG
            break;

        case GLUT_RIGHT_BUTTON :

            if ((y-mouseY)<0) skadZ -= 0.1 ;
            else if ((y-mouseY)>0) skadZ += 0.1 ;
            
            mouseX=x;
            mouseY=y;
            
            break;

        case GLUT_MIDDLE_BUTTON :
            mouseX=x;
            mouseY=y;
            break;
/*
        default:
            if ((y-mouseY)<0) naCoZ -= 0.1 ;
            else if ((y-mouseY)>0) naCoZ += 0.1 ;
            */
    };

}

void myszRuchBezPrzycisku(int x, int y) {
    if ((y-mouseY)<0) naCoZ -= -0.5 ;
    else if ((y-mouseY)>0) naCoZ += -0.5 ;
    mouseX=x;
    mouseY=y;

}



