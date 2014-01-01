#include "szafa.h"

Szafa::Szafa() : Obiekt3D() {
    inicjalizujKaty();
}


Szafa::Szafa(float szerLewychDrzwi,
             float szerPrawychDrzwi,
             float glebokosc,
             float wysDrzwi,
             float wysWyniesienia) : Obiekt3D() {

    this->szerLewychDrzwi = szerLewychDrzwi;
    this->szerPrawychDrzwi = szerPrawychDrzwi;
    this->glebokosc = glebokosc;
    this->wysDrzwi = wysDrzwi;
    this->wysWyniesienia = wysWyniesienia;
    
    gora = new Sciana();
    dol= new Sciana();
    lewo= new Sciana();
    prawo= new Sciana();
    tyl= new Sciana();
    dolneWyniesienie= new Sciana();
    gorneWyniesienie= new Sciana();
    leweDrzwi= new Sciana();
    praweDrzwi= new Sciana();

    inicjalizujKaty();
}

void Szafa::inicjalizujKaty(){
    katOtwarciaL = 0;
    katOtwarciaP = 0;
}


Szafa::~Szafa()
{
}

Szafa* Szafa::add(){
    float wysokoscSuma = wysDrzwi + 2* wysWyniesienia;
    float szerokoscSuma = szerLewychDrzwi + szerPrawychDrzwi;
    
    dol->scale( szerokoscSuma, glebokosc, 0.0f );
    dol->add();

    gora->translate( 0.0f, 0.0f, wysokoscSuma);
    gora->scale(  szerokoscSuma, glebokosc, 0.0f );
    gora->add();

    lewo->translate( -0.5 *(szerokoscSuma), 0.0f, 0.5 * wysokoscSuma  );
    lewo->rotate( 90.0f, 0.0f, 1.0f, 0.0f );
    lewo->scale( wysDrzwi + 2* wysWyniesienia, glebokosc, 0.0f );
    lewo->add();

    prawo->translate( 0.5 *(szerokoscSuma), 0.0f, 0.5 * wysokoscSuma  );
    prawo->rotate( 90.0f, 0.0f, 1.0f, 0.0f );
    prawo->scale( wysDrzwi + 2* wysWyniesienia, glebokosc, 0.0f );
    prawo->add();

    tyl->translate( 0.0f, 0.5*glebokosc, 0.5*wysokoscSuma);
    tyl->rotate( 90.0f, 1.0f, 0.0f, 0.0f);
    tyl->scale( szerokoscSuma, wysokoscSuma, 0.0f);
    tyl->add();

    dolneWyniesienie->translate( 0.0f, -0.5*glebokosc, 0.5*wysWyniesienia);
    dolneWyniesienie->rotate( 90.0f, 1.0f, 0.0f, 0.0f );
    dolneWyniesienie->scale( szerokoscSuma, wysWyniesienia, 0.0f);
    dolneWyniesienie->add();

    gorneWyniesienie->translate( 0.0f, -0.5*glebokosc, 1.5*wysWyniesienia + wysDrzwi);
    gorneWyniesienie->rotate( 90.0f, 1.0f, 0.0f, 0.0f );
    gorneWyniesienie->scale( szerokoscSuma, wysWyniesienia, 0.0f);
    gorneWyniesienie->add();

    leweDrzwi->translate(-0.5*szerokoscSuma, -0.5*glebokosc, 0.0f);
    leweDrzwi->rotate(-katOtwarciaL, 0.0f, 0.0f, 1.0f );
    leweDrzwi->translate( 0.5*szerLewychDrzwi, 0.0f, 0.5*wysDrzwi +wysWyniesienia );
    leweDrzwi->rotate(90.0f, 1.0f, 0.0f, 0.0f);
    leweDrzwi->scale( szerLewychDrzwi, wysDrzwi, 0.0f);
    leweDrzwi->add();

    praweDrzwi->translate(0.5*szerokoscSuma, -0.5*glebokosc, 0.0f);
    praweDrzwi->rotate(katOtwarciaP, 0.0f, 0.0f, 1.0f );
    praweDrzwi->translate( -0.5*szerPrawychDrzwi, 0.0f, 0.5*wysDrzwi +wysWyniesienia );
    praweDrzwi->rotate(90.0f, 1.0f, 0.0f, 0.0f);
    praweDrzwi->scale( szerPrawychDrzwi, wysDrzwi, 0.0f);
    praweDrzwi->add();
    
    
    finishDrawing();
    return this;
}


float Szafa::getKatOtwarciaP() const {
    return katOtwarciaP;
}


Szafa* Szafa::setKatOtwarciaP(float theValue) {
    katOtwarciaP = theValue;
    return this;
}

float Szafa::getKatOtwarciaL() const {
    return katOtwarciaL;
}


Szafa* Szafa::setKatOtwarciaL(float theValue) {
    katOtwarciaL = theValue;
    return this;
}


Sciana* Szafa::getGora() const {
    return gora;
}

Sciana* Szafa::getDol() const {
    return dol;
}

Sciana* Szafa::getLewo() const {
    return lewo;
}

Sciana* Szafa::getPrawo() const {
    return prawo;
}

Sciana* Szafa::getLeweDrzwi() const {
    return leweDrzwi;
}
Sciana* Szafa::getPraweDrzwi() const {
    return praweDrzwi;
}

Sciana* Szafa::getTyl() const {
    return tyl;
}

Sciana* Szafa::getDolneWyniesienie() const {
    return dolneWyniesienie;
}

Sciana* Szafa::getGorneWyniesienie() const {
    return gorneWyniesienie;
}
