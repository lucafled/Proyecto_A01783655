#ifndef GUERRERO_HPP
#define GUERRERO_HPP

#include "Unidad.hpp"

class Guerrero : public Unidad {
private:
    int fuerza;

public:
    Guerrero();
    Guerrero(int v, int a, int n, int f);

    int calculaAtaque(Unidad &objetivo);
    void recibeAtaque(int ptosAtaque);
    void imprimir();
};

#endif