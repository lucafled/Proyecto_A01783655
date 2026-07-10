#include "Mago.hpp"

Mago::Mago() : Unidad() {
    mana = 50;
}

Mago::Mago(int v, int a, int n, int m) : Unidad(v, a, n) {
    mana = m;
}

int Mago::calculaAtaque(Unidad &objetivo) {
    int dañoBase = Unidad::calculaAtaque(objetivo);
    
    if (mana >= 20) {
        mana -= 20; 
        cout << "¡El Mago lanza un Hechizo! (Maná consumido)" << endl;
        return dañoBase + 15; 
    } else {
        cout << "¡El Mago no tiene suficiente maná! Ataque debilitado." << endl;
        return dañoBase / 2;
    }
}

void Mago::atacar(Unidad &objetivo) {
    int daño = calculaAtaque(objetivo);
    objetivo.recibeAtaque(daño);
    cout << "Ataque de " << daño << " de daño" << endl;

    if (objetivo.getSalud() <= 0) {
        mana += 30;
        cout << "¡El enemigo ha caído! El Mago absorbe energía y recupera 30 de maná." << endl;
    }
}

void Mago::imprimir() {
    Unidad::imprimir();
    cout << "Clase: Mago | Maná Actual: " << mana << endl;
    cout << "-------------------------" << endl;
}