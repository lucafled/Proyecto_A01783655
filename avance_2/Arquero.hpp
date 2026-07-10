#ifndef ARQUERO_HPP
#define ARQUERO_HPP

#include "Unidad.hpp"

class Arquero : public Unidad {
private:
    int precision; 

public:
    Arquero();
    Arquero(int v, int a, int n, int p);

    int calculaAtaque(Unidad &objetivo);
    void imprimir();
};

#endif