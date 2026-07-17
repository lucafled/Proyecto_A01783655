#ifndef UNIDAD_HPP
#define UNIDAD_HPP

#include <iostream>
#include <string>

using namespace std;

class Unidad {
protected: 
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    // constructores
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

    // metodos virtuales y normales
    int porcentajeSalud();
    void imprimeBarra();
    
    virtual int calculaAtaque(Unidad &objetivo);
    virtual void recibeAtaque(int ptosAtaque);
    virtual void atacar(Unidad &objetivo);
    virtual void imprimir();
    
    // metodo virtual, esto hace la clase unidad virtual 
    virtual void revive() = 0;

    // destructor virtual para evitar fugas de memoria
    virtual ~Unidad() {}

    // sobrecarga de operador simple donde se compara si  unidad tiene mas salud que la otra
    // para ver si un un personaje tiene mas salud que otro usando el if 
    bool operator>(Unidad &otra) {
        return this->salud > otra.salud;
    }
};

#endif