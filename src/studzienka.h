/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef STUDZIENKA_H
#define STUDZIENKA_H

#include "obiekt3d.h"
#include "szescian.h"

/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Studzienka : public Obiekt3D
{
public:
    Studzienka(float x = 10, float y = 10, float ramka = 1, float wysokoscMurka = 4, int liczbaCykliFal = 3, int dokladnoscNaCykl = 10, float wysokoscFali = 0.5, float poziomWody = 2.5);
    ~Studzienka();

    virtual Studzienka* add();

    Szescian* getDno() const;
    Szescian* getGornyMurek() const;
    Szescian* getDolnyMurek() const;
    Szescian* getLewyMurek() const;
    Szescian* getPrawyMurek() const;
    Studzienka* setWysokoscMurka() const;

    void setPrzesuniecie(float theValue);
    

private:
    Szescian* dno;
    Szescian* gornyMurek;
    Szescian* dolnyMurek;
    Szescian* lewyMurek;
    Szescian* prawyMurek;
    
    float szerokoscX;
    float szerokoscY;
    float szerokoscRamka;
    float wysokoscMurka;
    
    
    int liczbaCykliFal;
    int dokladnoscNaCykl;
    float wysokoscFali;
    float poziomWody;
    static float przesuniecie;
    

};

#endif
