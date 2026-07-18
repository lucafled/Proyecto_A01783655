// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <iostream>
#include <string>

using namespace std;


// clase Unidad 
class Unidad 
{
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








// clases hijas o derivadas de Unidad 


// clase guerrero
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



// clase arquero
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

// clase mago
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
