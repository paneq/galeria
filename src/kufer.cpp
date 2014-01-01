/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "kufer.h"



Kufer::Kufer(int ile)
 : Obiekt3D()
{
this->ile = ile;
pudlo = new Szescian();
pudlo->setGora(0);

sciany = new Sciana* [ile];
    float d=M_PI/ile;
    for (int i = 0; i<ile; i++){
        sciany[i] = new Sciana(new Punkt(cos(d*i),sin(d*i),0),
                            new Punkt(cos(d*(i+1)),sin(d*(i+1)),0),
                            new Punkt(cos(d*(i+1)),sin(d*(i+1)),1),
                            new Punkt(cos(d*i),sin(d*i),1));
    }


}


Kufer::~Kufer()
{
}


Kufer* Kufer::setKatOtwarcia(float x){
  
  katOtwarcia = x;
  
  return this; 
}

Kufer* Kufer::add()
{

  
  
 pudlo->scale(2, 2, 1);

 pudlo->add();

 //lewy polokrag
 if (useTexture){
   
   
 glPushMatrix();
 glTranslatef(-1, 0 , 1);
 glTranslatef(0,1,0);
 glRotatef(katOtwarcia, 1, 0, 0);
 glTranslatef(0,-1,0);
 glRotatef(-90, 0, 0, 1);
 glRotatef(90, 1, 0, 0);
 
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
 glNormal3f( 0, 0, 1);
 float d=M_PI/ile;
 for (int i = 0; i<ile; i++) glVertex3f(cos(d*i),sin(d*i),0);
 glEnd();
 glPopMatrix();
 


//prawy polokrag
 glPushMatrix();
 glTranslatef(1, 0 , 1);
 glTranslatef(0,1,0);
     glRotatef(katOtwarcia, 1, 0, 0);
     glTranslatef(0,-1,0);
// glRotatef(katOtwarcia, 1, 0, 0);
 glRotatef(90, 0, 0, 1);
 glRotatef(90, 1, 0, 0);
 glBegin(GL_POLYGON);
 glNormal3f( 0, 0, 1);
 for (int i = 0; i<ile; i++) glVertex3f(cos(d*i),sin(d*i),0);
 glEnd();
 glPopMatrix();
 
 glDisable(GL_TEXTURE_2D);
 glDisable(GL_TEXTURE_GEN_S);
 glDisable(GL_TEXTURE_GEN_T);
 
 }else{
   glPushMatrix();
   glTranslatef(-1, 0 , 1);
   glTranslatef(0,1,0);
   glRotatef(katOtwarcia, 1, 0, 0);
   glTranslatef(0,-1,0);
   glRotatef(-90, 0, 0, 1);
   glRotatef(90, 1, 0, 0);
   glBegin(GL_POLYGON);
   glNormal3f( 0, 0, 1);
   float d=M_PI/ile;
   for (int i = 0; i<ile; i++) glVertex3f(cos(d*i),sin(d*i),0);
   glEnd();
   glPopMatrix();


//prawy polokrag
   glPushMatrix();
   glTranslatef(1, 0 , 1);
   glTranslatef(0,1,0);
   glRotatef(katOtwarcia, 1, 0, 0);
   glTranslatef(0,-1,0);
// glRotatef(katOtwarcia, 1, 0, 0);
   glRotatef(90, 0, 0, 1);
   glRotatef(90, 1, 0, 0);
   glBegin(GL_POLYGON);
   glNormal3f( 0, 0, 1);
   for (int i = 0; i<ile; i++) glVertex3f(cos(d*i),sin(d*i),0);
   glEnd();
   glPopMatrix();
   
 }
   
//'polwalec'
 glPushMatrix();
 glTranslatef(-1, 0 , 1);
 glTranslatef(0,1,0);
     glRotatef(katOtwarcia, 1, 0, 0);
     glTranslatef(0,-1,0);
// glRotatef(katOtwarcia, 1, 0, 0);
 glRotatef(90, 0, 0, 1);
 glRotatef(90, 1, 0, 0);
 glScalef(1, 1, 2);
 for (int i = 0; i<ile; i++)  sciany[i]->add(); 
 glPopMatrix();


   finishDrawing();
   return this;
}


Kufer* Kufer::setTextureID(GLuint textureID){
  this->textureID = textureID;
  return this;
};

GLuint Kufer::getTextureID(){
  return textureID;
};

Kufer* Kufer::setUseTexture(bool useTexture){
  this->useTexture = useTexture;
  return this;
};

bool Kufer::getUseTexture(){
  return useTexture;
};

Kufer* Kufer::setUseTexture(bool useTexture, GLuint textureID){
  this->useTexture = useTexture;
  this->textureID = textureID;
  
  pudlo->setUseTexture( true, textureID);
  for (int i = 0; i<ile; i++) sciany[i]->setUseTexture( true, textureID);
  return this;
};



// Kufer* Kufer::defaultTextureUse(){
//   this->setUseTexture(false);
//   this->textureID = 0 ;
//   return this;
// }
