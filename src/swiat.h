/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef SWIAT_H
#define SWIAT_H

#include "szescian.h"
#include "kula.h"
#include "spodek.h"

/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Swiat{
public:
    Swiat();

    ~Swiat();
    Sciana* getSciana(int numer);
    Szescian* getSzescian(int numer);
    Kula* getKula(int numer);
    Spodek* getSpodek(int numer);
    Obiekt3D* getElement(int numer);
    
    Swiat* addToSwiat(int numer, Obiekt3D *element);
    //Swiat* addToSwiat(int numer, Sciana *element);
    //Swiat* addToSwiat(int numer, Szescian *element);
    //Swiat* addToSwiat(int numer, Kula *element);
    //Swiat* addToSwiat(int numer, Spodek *element);

private:
    Obiekt3D* elementy[100];
};
/*
template <class klasa>
Swiat* Swiat::addToSwiat(int numer, klasa *element){
  elementy[numer] = reinterpret_cast< void* >(element);
  return this;
}
*/
#endif
