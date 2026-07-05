#ifndef UNIDAD_HPP
#define UNIDAD_HPP

#include <iostream>
#include <string>

using namespace std;

class Unidad {
private:
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    // constructore
    Unidad();
    Unidad(int v, int a, int n);

    // getters
    int getVida();
    int getSalud();
    int getAtaque();
    int getNivel();

    // setters
    void setVida(int v);
    void setSalud(int s);
    void setAtaque(int a);
    void setNivel(int n);

    // metodos a implementar 
    int porcentajeSalud();
    void imprimeBarra();
    int calculaAtaque(Unidad &objetivo);
    void recibeAtaque(int ptosAtaque);
    void atacar(Unidad &objetivo);
    void imprimir();
};

#endif