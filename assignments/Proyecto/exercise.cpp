#include <iostream>
#include <cstdlib>   // para rand() y srand()
#include <ctime>     // para time() que nos da los segundos y asi tenemos numeros diferentes constantemente 
#include "Personaje.hpp"

using namespace std;

// para ver si un ejercito  tiene unidades con vida
bool ejercitoTieneVida(Unidad* ejercito[], int tamano) 
{
    for (int i = 0; i < tamano; i++) 
    {
        if (ejercito[i]->getSalud() > 0)
        {
            return true;
        }
    }
    return false;
}





int main() {
    // inicializacion de numeros random
    srand(time(0));

    const int TAMANO_EJERCITO = 3; // se le dice el tamaño del ejercito


    // definicidn de los dos ejercitos de mismo tamaño
    Unidad* ejercitoA[TAMANO_EJERCITO];
    Unidad* ejercitoB[TAMANO_EJERCITO];

    // crear el ejercito A
    ejercitoA[0] = new Guerrero(150, 40, 3, 15);  // vida, ataque, nivel, fuerza
    ejercitoA[1] = new Arquero(100, 25, 3, 35);   // vida, ataque, nivel, precision
    ejercitoA[2] = new Mago(80, 20, 3, 50);       // vida, ataque, nivel, mana

    // crear el ejercito B 
    ejercitoB[0] = new Guerrero(140, 35, 3, 12); // vida, ataque, nivel, fuerza
    ejercitoB[1] = new Arquero(110, 20, 3, 40);  // vida, ataque, nivel, precision
    ejercitoB[2] = new Mago(90, 22, 3, 45);      // vida, ataque, nivel, mana




    // stats iniciales de los dos ejercitos
    cout << "\n--- STATS INICIALES EJERCITO A ---" << endl;
    for (int i = 0; i < TAMANO_EJERCITO; i++) 
    {
        ejercitoA[i]->imprimir();
    }

    cout << "\n--- STATS INICIALES EJERCITO B ---" << endl;
    for (int i = 0; i < TAMANO_EJERCITO; i++) 
    {
        ejercitoB[i]->imprimir();
    }





    // prueba de sobrecarga para ver quien tiene mas salud
    cout << "\n--- Prueba de sobrecarga (> salud) ---" << endl;
    if (*ejercitoA[0] > *ejercitoB[0]) 
    {
        cout << "El Guerrero A tiene mas salud que el guerrero B" << endl;
    } 
    else 
    {
        cout << "El guerrero B tiene mas o igual salud que el guerrero A" << endl;
    }

    // loop del juego interactivo
    cout << "          ¡INICIO DE LA BATALLA!          " << endl;
  

    int ronda = 1;

    // mientras los dos abndos tengan un personaje vivo el juego continua
    while (ejercitoTieneVida(ejercitoA, TAMANO_EJERCITO) && ejercitoTieneVida(ejercitoB, TAMANO_EJERCITO)) 
    {
        cout << "\n--- RONDA " << ronda << " ---" << endl;

        // turno del ejercito A (lo que elige el usuario) 
        cout << "\nTurno del ejercito A (Controlado por el usuario)" << endl;
        cout << "Elige a tu combatiente que este vivo:" << endl;
        for (int i = 0; i < TAMANO_EJERCITO; i++) 
        {
            cout << i << ". ";

            // if para ver si siguen vivos o no y nos diga
            if (ejercitoA[i]->getSalud() > 0) 
            {
                cout << "Unidad viva (HP: " << ejercitoA[i]->getSalud() << ")";
            } 
            else 
            {
                cout << "[CAIDO]";
            }
            cout << endl;
        }


        int seleccionA = -1; // -1 para que sea como el 0 y empieze desde nada

        // do while para que si el usuario elige opciones que no son nos lo diga
        do 
        {
            cout << "Ingresa el numero de combatiente a elegir (0-2): ";
            cin >> seleccionA;

            // nos dice si el soldado elegido esta muerto
            if (seleccionA < 0 || seleccionA >= TAMANO_EJERCITO || ejercitoA[seleccionA]->getSalud() <= 0) {
                cout << "Opcion invalida o unidad muerta, elige otra opcion" << endl;
            }
        } 
        while (seleccionA < 0 || seleccionA >= TAMANO_EJERCITO || ejercitoA[seleccionA]->getSalud() <= 0);






        // la comnputadora selecciona un objetivo VIVO y random del ejercito B 
        int objetivoB = -1;
        do 
        {
            objetivoB = rand() % TAMANO_EJERCITO;
        } while (ejercitoB[objetivoB]->getSalud() <= 0);

        cout << "\n>>> El Ejercito A ataca:" << endl;
        ejercitoA[seleccionA]->atacar(*ejercitoB[objetivoB]);
        cout << "Estado del objetivo del Ejercito B:" << endl;
        ejercitoB[objetivoB]->imprimir();






        // verificamos si el ejercito B aun vive antes de que pueda contraatacar
        if (!ejercitoTieneVida(ejercitoB, TAMANO_EJERCITO)) 
        {
            break;
        }

        //  turno del B (Elegido por la computadora) 
        cout << "\nTurno del ejercito B (Controlado por la omputadora)" << endl;
        
        int atacanteB = -1;

        // aqui se asegura que la compu no eliga personajes muetos
        do 
        {
            atacanteB = rand() % TAMANO_EJERCITO;
        } while (ejercitoB[atacanteB]->getSalud() <= 0); 

        int objetivoA = -1;
        do 
        {
            objetivoA = rand() % TAMANO_EJERCITO;
        } while (ejercitoA[objetivoA]->getSalud() <= 0);



        cout << "\n>>> El ejercito B ataca:" << endl;
        ejercitoB[atacanteB]->atacar(*ejercitoA[objetivoA]);
        cout << "Estado del objetivo del ejercito A:" << endl;
        ejercitoA[objetivoA]->imprimir();

        ronda++;
    }






    // se printea el ganador
    cout << "\n==========================================" << endl;
    if (ejercitoTieneVida(ejercitoA, TAMANO_EJERCITO)) 
    {
        cout << "El ejercito A ha ganado la batalla" << endl;
    } 
    else 
    {
        cout << "El ejercito B ha ganado la batalla el ejercito A ha sido destruido" << endl;
    }
    cout << "==========================================" << endl;






    // liberador de memoria
    for (int i = 0; i < TAMANO_EJERCITO; i++) 
    {
        delete ejercitoA[i];
        delete ejercitoB[i];
    }

    cout << "\nGAME OVER" << endl;
    return 0;
}
