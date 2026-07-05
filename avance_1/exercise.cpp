#include <iostream>
#include "Unidad.hpp"

using namespace std;

int main() {
    cout << "=== Creando las unidades de combate ===" << endl;
    
    // asignando valores al objeto creado 
    Unidad jugador(120, 30, 2);  // nivel 2
    Unidad boss(200, 40, 5);     // boss nivel 5

    cout << "\n--- Estado Inicial del Soldado ---" << endl;
    jugador.imprimir();

    cout << "\n--- Estado Inicial del Jefe ---" << endl;
    boss.imprimir();

    // prints del combate 
    cout << "\n=== ¡El Soldado ataca! ===" << endl;
    jugador.atacar(boss);
    boss.imprimir();

    cout << "\n=== ¡El enemigo contraataca! ===" << endl;
    boss.atacar(jugador);
    jugador.imprimir();

    return 0;
}