#ifndef OBRAZ_H
#define OBRAZ_H

#include "obiekt3d.h"
#include "szescian.h"
#include <math.h>

/**
	@author Robert Pankowecki, Jarosław Plebański <d287544@atos.amu.edu.pl , d287548@atos.amu.edu.pl>
*/
class Obraz : public Obiekt3D
{
public:
    Obraz(float x = 10, float y = 10, float ramka = 1);
    ~Obraz();

    virtual Obraz* add();

    Szescian* getObrazek() const;
    Szescian* getGornaRama() const;
    Szescian* getDolnaRama() const;
    Szescian* getLewaRama() const;
    Szescian* getPrawaRama() const;

private:
    Szescian* obrazek;
    Szescian* gornaRama;
    Szescian* dolnaRama;
    Szescian* lewaRama;
    Szescian* prawaRama;
    float szerokoscX;
    float szerokoscY;
    float szerokoscRamka;
};

#endif
