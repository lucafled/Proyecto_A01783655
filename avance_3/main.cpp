#include <iostream>
#include "Unidad.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

using namespace std;

int main() {
    cout << "=== Creando Arreglo de Combatientes Polimórficos ===" << endl;
    

    Unidad* ejercito[3];


    ejercito[0] = new Guerrero(150, 40, 3, 15);  // vida, ataque, nivel, fuerza
    ejercito[1] = new Arquero(100, 25, 3, 35);   // vida, ataque, nivel, precision
    ejercito[2] = new Mago(80, 20, 3, 50);       // vida, ataque, nivel, mana

    // imprime los 3 personajes usando polimorfismo
    cout << "\n--- stats iniciales ---" << endl;
    for (int i = 0; i < 3; i++) {
        ejercito[i]->imprimir(); 
    }

    // se prueban las sobrecargas correctamente (usando > con objetos desreferenciados)
    cout << "\n---prueba de sobrecarga ---" << endl;
    if (*ejercito[0] > *ejercito[2]) {
        cout << "El Guerrero tiene mas salud que el Mago" << endl;
    } else {
        cout << "El Mago tiene mas o igual salud que el Guerrero" << endl;
    }

    // combate interactivo y polimorfismo
    cout << "\n--- inicio de combate ---" << endl;
    
    // guerrero ataca alarquero
    cout << "\n>>> TURNO 1: El Guerrero ataca al Arquero:" << endl;
    ejercito[0]->atacar(*ejercito[1]);
    cout << "\nstats del Arquero despues del ataque:" << endl;
    ejercito[1]->imprimir();

    // arquero ataca al mago para probar el revive
    cout << "\n>>> TURNO 2: El Mago recibe daño mortal para probar revive():" << endl;
    ejercito[2]->recibeAtaque(90); 
    cout << "\nstats del Mago despues del ataque letal:" << endl;
    ejercito[2]->imprimir();

    // mago ataca al guerrero
    cout << "\n>>> TURNO 3: El Mago ataca al Guerrero:" << endl;
    ejercito[2]->atacar(*ejercito[0]);
    cout << "\nstats del Guerrero despues del ataque:" << endl;
    ejercito[0]->imprimir();

    // liberacion  de la memoria
    for (int i = 0; i < 3; i++) {
        delete ejercito[i];
    }

    cout << "\nGAME OVER" << endl;
    return 0;
}