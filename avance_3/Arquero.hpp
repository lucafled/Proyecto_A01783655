#ifndef ARQUERO_HPP
#define ARQUERO_HPP

#include "Unidad.hpp"

using namespace std;

class Arquero : public Unidad {
private:
    int precision; 

public:
    Arquero();
    Arquero(int v, int a, int n, int p);

    int calculaAtaque(Unidad &objetivo) override;
    void recibeAtaque(int ptosAtaque) override;
    void imprimir() override;
    void revive() override; 
};

#endif