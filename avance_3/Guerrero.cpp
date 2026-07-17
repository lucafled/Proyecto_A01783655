#include "Guerrero.hpp"

using namespace std;

Guerrero::Guerrero() : Unidad() 
{
    fuerza = 10;
}

Guerrero::Guerrero(int v, int a, int n, int f) : Unidad(v, a, n) 
{
    fuerza = f;
}


// se suma el daño de la unidad base mas los puntos de fuerza adicionales
int Guerrero::calculaAtaque(Unidad &objetivo) {
    return Unidad::calculaAtaque(objetivo) + fuerza;
}


// donde se recibe el ataque con filtro para que la salud no se pase abajo de 0
void Guerrero::recibeAtaque(int ptosAtaque) 
{
    int dañoReducido = ptosAtaque - (fuerza / 2);
    if (dañoReducido < 1) dañoReducido = 1;
    
    salud = salud - dañoReducido;
    if (salud <= 0) 
    
    {
        salud = 0;
        revive(); 
    }
}



// en el caso de que tenga 10 o mas de pts de fuerza pierde 5 para pararse con el 20% de vida, de lo contrario muere y game over 
void Guerrero::revive() 
{
    if (fuerza >= 10) 
    {
        fuerza -= 5; 
        salud = vida * 0.20; 
        cout << "¡El guerrero uso sus puntos de fuerza para sobrevivir! Revivi0 con " << salud << " de salud (La fuerza ahora es menor)" << endl;
    } 
    else 
    {
        cout << "¡El guerrero murio en batalla! No le quedaban fuerzas" << endl;
    }
}



void Guerrero::imprimir() 
{
    Unidad::imprimir();
    cout << "Clase: Guerrero | Fuerza Extra: " << fuerza << endl; //cantidad de de fuerza
    cout << "-------------------------" << endl;
}