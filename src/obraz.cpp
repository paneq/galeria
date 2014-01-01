#include "obraz.h"

Obraz::Obraz(float x, float y, float ramka): Obiekt3D()
{
     obrazek = new Szescian(0.3);
     gornaRama = new Szescian(0.0);
     dolnaRama = new Szescian(0.1);
     lewaRama = new Szescian(0.4);
     prawaRama = new Szescian(0.5);
     this->szerokoscRamka = ramka;
     this->szerokoscX = x;
     this->szerokoscY = y;
     
     gornaRama->getGora()->setTextureScale(new Punkt(0,0,0), new Punkt(18,1,1));
     dolnaRama->getGora()->setTextureScale(new Punkt(0,0,0), new Punkt(18,1,1));
}


Obraz::~Obraz()
{
}

Obraz* Obraz::add(){
    obrazek->translate( 0.0f, 0.0f, szerokoscY / 2 + szerokoscRamka / 2);
    obrazek->rotate( 90, 1.0f, 0.0f, 0.0f );
    obrazek->scale( szerokoscX, szerokoscY, 0.5f );
    obrazek->add();

    gornaRama->translate( 0.0f, 0.0f, szerokoscY  + szerokoscRamka);
    gornaRama->rotate( 90, 1.0f, 0.0f, 0.0f );
    gornaRama->scale( szerokoscX + szerokoscRamka * 2, szerokoscRamka, 1.0f);
    gornaRama->add();

    dolnaRama->translate( 0.0f, 0.0f, szerokoscRamka * 0.5 );
    dolnaRama->rotate( 90, 1.0f, 0.0f, 0.0f );
    dolnaRama->scale( szerokoscX + szerokoscRamka * 2, szerokoscRamka, 1.0f);
    dolnaRama->add();

    lewaRama->translate( -szerokoscX / 2 -szerokoscRamka * 0.5, 0.0f, szerokoscRamka + szerokoscY / 2 );
    lewaRama->rotate( 90, 1.0f, 0.0f, 0.0f );
    lewaRama->scale( szerokoscRamka, szerokoscY, 1.0f);
    lewaRama->add();

    prawaRama->translate( szerokoscX / 2 + szerokoscRamka * 0.5, 0.0f, szerokoscRamka + szerokoscY / 2 );
    prawaRama->rotate( 90, 1.0f, 0.0f, 0.0f );
    prawaRama->scale( szerokoscRamka, szerokoscY, 1.0f);
    prawaRama->add();

    finishDrawing();
    return this;
}


Szescian* Obraz::getObrazek() const {
    return obrazek;
}

Szescian* Obraz::getGornaRama() const {
    return gornaRama;
}

Szescian* Obraz::getDolnaRama() const {
    return dolnaRama;
}

Szescian* Obraz::getLewaRama() const {
    return lewaRama;
}

Szescian* Obraz::getPrawaRama() const {
    return prawaRama;
}


