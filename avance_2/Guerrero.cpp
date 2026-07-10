#include "Guerrero.hpp"

Guerrero::Guerrero() : Unidad() {
    fuerza = 10;
}

Guerrero::Guerrero(int v, int a, int n, int f) : Unidad(v, a, n) {
    fuerza = f;
}

int Guerrero::calculaAtaque(Unidad &objetivo) {
    return Unidad::calculaAtaque(objetivo) + fuerza;
}

void Guerrero::recibeAtaque(int ptosAtaque) {
    int dañoReducido = ptosAtaque - (fuerza / 2);
    if (dañoReducido < 1) dañoReducido = 1;
    Unidad::recibeAtaque(dañoReducido);
}

void Guerrero::imprimir() {
    Unidad::imprimir();
    cout << "Clase: Guerrero | Fuerza Extra: " << fuerza << endl;
    cout << "-------------------------" << endl;
}