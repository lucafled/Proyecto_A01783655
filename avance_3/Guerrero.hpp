#ifndef GUERRERO_HPP
#define GUERRERO_HPP

#include "Unidad.hpp"

using namespace std;

class Guerrero : public Unidad // hereda todo lo de la clase Unidad
{
private:
    int fuerza; 

public:

    Guerrero();
    Guerrero(int v, int a, int n, int f);

    // sobre escribiendo los metodos
    int calculaAtaque(Unidad &objetivo) override; // & para evitar crear copia
    void recibeAtaque(int ptosAtaque) override;
    void imprimir() override;
    void revive() override; 
};

#endif