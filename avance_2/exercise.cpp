#include <iostream>
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

using namespace std;

int main() {
    cout << "=== Creando las Unidades de Combate Especializadas ===" << endl;
    
    Guerrero conan(150, 35, 3, 12);  // vida, ataque, nivel, fuerza
    Arquero legolas(110, 30, 3, 35); // vida, ataque, nivel, precision
    Mago gandalf(100, 25, 3, 60);    // vida, ataque, nivel, mana

    cout << "\n=== ESTADO INICIAL ===" << endl;
    conan.imprimir();
    legolas.imprimir();
    gandalf.imprimir();

    cout << "\n=== RONDA 1: Guerrero vs Arquero ===" << endl;
    conan.atacar(legolas);
    legolas.imprimir();

    cout << "\n=== RONDA 2: Arquero vs Mago ===" << endl;
    legolas.atacar(gandalf);
    gandalf.imprimir();

    cout << "\n=== RONDA 3: Mago vs Guerrero ===" << endl;
    gandalf.atacar(conan);
    conan.imprimir();

    return 0;
}