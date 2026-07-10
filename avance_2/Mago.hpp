#ifndef MAGO_HPP
#define MAGO_HPP

#include "Unidad.hpp"

class Mago : public Unidad {
private:
    int mana;

public:
    Mago();
    Mago(int v, int a, int n, int m);

    int calculaAtaque(Unidad &objetivo);
    void atacar(Unidad &objetivo); 
    void imprimir();
};

#endif