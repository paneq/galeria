/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef FOTEL_H
#define FOTEL_H

#include <obiekt3d.h>
#include "szescian.h"
#include <math.h>

/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Fotel : public Obiekt3D
{
public:
    Fotel();

    ~Fotel();

    virtual Obiekt3D* add();
private: 
  Szescian *A,*B,*C,*D;

};

#endif
