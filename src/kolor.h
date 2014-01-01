/**
 *@author Robert Pankowecki
 *@author Jaroslaw Plebanski
 */
#ifndef KOLOR_H
#define KOLOR_H

/**
	@author Jarosaw Plebanski, Robert Pankowecki, informatyka <d287548@atos.amu.edu.pl, d287544@atos.amu.edu.pl>
*/
class Kolor{

public:
    Kolor();
    Kolor(float r, float g, float b, float alfa = 1);
    
    ~Kolor();
    
    float getR() const;
    float getG() const;
    float getB() const;
    float getAlfa() const;
    Kolor* setR(float const r);
    Kolor* setG(float const g);
    Kolor* setB(float const b);
    Kolor* setAlfa(float const alfa);

private:
   float r;
   float g;
   float b;
   float alfa;

};

#endif

