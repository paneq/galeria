/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#include "swiat.h"

Swiat::Swiat()
{
}


Swiat::~Swiat()
{
}

Sciana* Swiat::getSciana(int numer){
      return reinterpret_cast< Sciana* >( elementy[numer] ); 
}

Szescian* Swiat::getSzescian(int numer){
  return reinterpret_cast< Szescian* >( elementy[numer] ); 
}

Kula* Swiat::getKula(int numer){
  return reinterpret_cast< Kula* >( elementy[numer] ); 
}

Spodek* Swiat::getSpodek(int numer){
  return reinterpret_cast< Spodek* >( elementy[numer] ); 
}


Obiekt3D* Swiat::getElement(int numer){
  return elementy[numer]; 
}



Swiat* Swiat::addToSwiat(int numer, Obiekt3D *element){
    elementy[numer] = element;
    return this;
}
/*
Swiat* Swiat::addToSwiat(int numer, Sciana *element){
  elementy[numer] = element;
  return this;
}

Swiat* Swiat::addToSwiat(int numer, Szescian *element){
  elementy[numer] = element;
  return this;
}

Swiat* Swiat::addToSwiat(int numer, Kula *element){
  elementy[numer] = element;
  return this;
}


Swiat* Swiat::addToSwiat(int numer, Spodek *element){
  elementy[numer] = element;
  return this;
}
*/