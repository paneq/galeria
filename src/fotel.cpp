/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "fotel.h"

Fotel::Fotel() : Obiekt3D() {
    A = new Szescian(0.3);
    B = new Szescian(0.2);
    C = new Szescian(0.1);
    D = new Szescian(0.5);
}


Fotel::~Fotel()
{
}


Obiekt3D* Fotel::add()
{
//     A->scale(7,2,5);
//     A->translate( -4,2,0);
//     A->translate( 0.5f, 0.5f, 0.0f );
//     A->add();
//     
//     B->scale(7,2,5);
//     B->translate( -4,-3,0);
//     B->translate( 0.5f, 0.5f, 0.0f );
//     B->add();
//     
//     C->scale(4,4,2);
//     C->translate(0,-2,0);
//     C->translate( 0.5f, 0.5f, 0.0f );
//     C->add();
//     
//     D->scale(5*M_SQRT2, 4, 2*M_SQRT2);
//     D->translate(0, -2, 0);
//     D->rotate( (3/4)*M_PI, 0, 1, 0);
//     D->translate(0, 2, 0);
//     D->translate( 0.5f, 0.5f, 0.0f );
//     D->add();



    
    C->translate( 1.5f, 0.0f, 0.0f );
    C->scale( 3.0f, 4.0f, 2.0f );
    C->add();

    A->translate( 0.5f, 3.0f, 0.0f );
    A->scale( 5.0f, 2.0f, 3.0f );
    A->add();

    B->translate( 0.5f, -3.0f, 0.0f );
    B->scale( 5.0f, 2.0f, 3.0f );
    B->add();

    D->translate( 0.0f, 0.0f, 1.0f );
    D->rotate( -45, 0.0f, 1.0f, 0.0f );
    D->scale( 2*M_SQRT2, 4.0f, 4*M_SQRT2 );
    D->add();

    finishDrawing();
    return this;
  
}

