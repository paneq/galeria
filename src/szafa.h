#ifndef SZAFA_H
#define SZAFA_H

#include "obiekt3d.h"
#include "sciana.h"
/**
 * @author Robert Pankowecki, Jarosław Plebański <d287544@atos.amu.edu.pl , d287548@atos.amu.edu.pl>
*/
class Szafa : public Obiekt3D
{
public:
    Szafa();
    Szafa(float szerLewychDrzwi,
         float szerPrawychDrzwi,
         float glebokosc,
         float wysDrzwi,
         float wysWyniesienia);

    ~Szafa();

    virtual Szafa* add();

    Szafa* setKatOtwarciaP(float theValue);
    float getKatOtwarciaP() const;

    Szafa* setKatOtwarciaL(float theValue);
    float getKatOtwarciaL() const;

    Sciana* getGora() const;
    Sciana* getDol() const;

    Sciana* getLewo() const ;
    Sciana* getPrawo() const ;

    Sciana* getLeweDrzwi() const ;
    Sciana* getPraweDrzwi() const;
    
    Sciana* getTyl() const;
    Sciana* getDolneWyniesienie() const;
    Sciana* getGorneWyniesienie() const;
    
    
    
private:

    void inicjalizujKaty();

    float szerLewychDrzwi;
    float szerPrawychDrzwi;
    float wysDrzwi;
    float wysWyniesienia;
    float glebokosc;

    float katOtwarciaL;
    float katOtwarciaP;

    Sciana* gora;
    Sciana* dol;
    Sciana* lewo;
    Sciana* prawo;
    Sciana* tyl;
    Sciana* dolneWyniesienie;
    Sciana* gorneWyniesienie;
    Sciana* leweDrzwi;
    Sciana* praweDrzwi;
};

#endif
