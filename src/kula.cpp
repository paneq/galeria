#include "kula.h"

const float Kula::Pi = 3.1415926535897932384626433832795f;

Kula::Kula()
{

}


Kula::~Kula()
{
}

Kula* Kula::add() {
   // void kula(int m,int n, GLfloat r)
    //m (n) jest ilosci segment� na r�noleniku (poowie poudnika), r promieniem kuli 
    
        int m = 10;
        int n = 10;
        GLfloat r = 0.1;
        int i,j;
        GLdouble alpha,beta,r0,r1,z0,z1,x00,x01,x10,x11,y00,y01,y10,y11;

        alpha=0.5*Pi/float(n);
        beta=2*Pi/float(m);
        r0=r;
        z0=0;

        for(j=0;j<n-1;j++)
        {
            r1=r*cos(float((j+1))*alpha);
            z1=r*sin(float((j+1))*alpha);
            x01=r1;y01=0;
            x00=r0;y00=0;
            for(i=1;i<=m;i++)
            {
                x11=r1*cos(float(i)*beta);
                y11=r1*sin(float(i)*beta);
                
                x10=r0*cos(float(i)*beta);
                y10=r0*sin(float(i)*beta);
                
                glBegin(GL_POLYGON);
                      glColor3f(1,0,0);
                glNormal3f(x00,y00,z0);
                glVertex3d(x00,y00,z0);
                
                glNormal3f(x10,y10,z0);
                glVertex3d(x10,y10,z0);
                
                glNormal3f(x11,y11,z1);
                glVertex3d(x11,y11,z1);
                
                glNormal3f(x01,y01,z1);
                glVertex3d(x01,y01,z1);
                
                glEnd();
                glBegin(GL_POLYGON);
                    //  glColor3f(0,0,1);
                glNormal3f(x00,y00,-z0);
                glVertex3d(x00,y00,-z0);
                
                glNormal3f(x01,y01,-z1);
                glVertex3d(x01,y01,-z1);
                
                glNormal3f(x11,y11,-z1);
                glVertex3d(x11,y11,-z1);
                
                glNormal3f(x10,y10,-z0);
                glVertex3d(x10,y10,-z0);
                glEnd();
                x01=x11;y01=y11;
                x00=x10;y00=y10;
            }// end for i
            r0=r1;
            z0=z1;

        }//end for j

        glBegin(GL_TRIANGLE_FAN);
        glNormal3f(0,0,r);
        glVertex3f(0,0,r);
        for(i=0;i<=m;i++)
        {
            x10=r1*cos(float(i)*beta);y10=r1*sin(float(i)*beta);
            glNormal3f(x10,y10,z1);
            glVertex3f(x10,y10,z1);
        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glNormal3f(0,0,-r);
        glVertex3f(0,0,-r);
        for(i=m;i>=0;i--)
        {
            x10=r1*cos(float(i)*beta);y10=r1*sin(float(i)*beta);
            glNormal3f(x10,y10,-z1);
            glVertex3f(x10,y10,-z1);
        }
        glEnd();

        if ( getUzylStos() ) {
            glPopMatrix();
            setUzylStos(false);
        }
        return this;
}
/*
Kula* Kula::rotate(float alfa, float dx, float dy, float dz){
  
    if ( !getUzylStos() ){
        glPushMatrix();
        glLoadIdentity();
    };
    glRotatef(alfa, dx , dy, dz);
    setUzylStos(true);
    return this;
}

Kula* Kula::translate(float dx, float dy, float dz){
    if ( !getUzylStos() ){
        glPushMatrix();
        glLoadIdentity();
    };
    glTranslatef(dx , dy, dz);
    setUzylStos(true);
    return this;
};

Kula* Kula::scale(float sx, float sy, float sz){
    
    if ( !getUzylStos() ){
        glPushMatrix();
        glLoadIdentity();
    };
    glScalef(sx, sy, sz);
    setUzylStos(true);
    return this;
}
*/
