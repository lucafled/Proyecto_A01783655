#ifndef MAGO_HPP
#define MAGO_HPP

#include "Unidad.hpp"

using namespace std;

class Mago : public Unidad 
{
private:
    int mana;

public:
    Mago();
    Mago(int v, int a, int n, int m);

    int calculaAtaque(Unidad &objetivo) override;
    void recibeAtaque(int ptosAtaque) override;
    void atacar(Unidad &objetivo) override; 
    void imprimir() override;
    void revive() override; 
};

#endif