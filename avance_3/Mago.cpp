#include "Mago.hpp"

using namespace std;

Mago::Mago() : Unidad() 
{
    mana = 50;
}

Mago::Mago(int v, int a, int n, int m) : Unidad(v, a, n) 
{
    mana = m;
}


// se gasta 20 de mana para un hechizo que ocasiona 15 de daño adicional
int Mago::calculaAtaque(Unidad &objetivo) 
{
    int dañoBase = Unidad::calculaAtaque(objetivo);
    
    if (mana >= 20) 
    {
        mana -= 20; 
        cout << "¡El Mago lanzo un hechizo! (-20 de mana)" << endl;
        return dañoBase + 15; 
    } 
    else  // si tiene menos de 20 de mana se debilita su ataque / 2
    {
        cout << "¡El Mago no tiene suficiente mana! Ataque debilitado" << endl;
        return dañoBase / 2;
    }
}


// si tiene salud negativa o 0 el mago activa su hechizo de revivir 
void Mago::recibeAtaque(int ptosAtaque) 
{
    salud = salud - ptosAtaque;
    if (salud <= 0) 
    {
        salud = 0;
        revive(); 
    }
}


// se lanza el ataque, si este mata al contrincante el mago absorbe su energia y se le suma 30 de mana 
void Mago::atacar(Unidad &objetivo) 
{
    int daño = calculaAtaque(objetivo);
    objetivo.recibeAtaque(daño);

    cout << "Ataque de " << daño << " de daño" << endl;

    if (objetivo.getSalud() <= 0) 
    {
        mana += 30;
        cout << "¡El enemigo ha muerto! El mago gana pts 30 de mana" << endl;
    }
}



// con 30 o mas de mana, los puede gastar para revivir con el 30% de la salud max, si no tiene muere 
void Mago::revive() 
{
    if (mana >= 30) 
    {
        mana -= 30; 
        salud = vida * 0.30; 
        cout << "¡El Mago gasto su mana para lanzar un hechizo y revivir! Revivio con " << salud << " de salud" << endl;
    } 
    else 
    {
        cout << "¡El Mago ha muerto! Se quedo sin mana para revivir" << endl;
    }
}



// stats del mago
void Mago::imprimir() 
{
    Unidad::imprimir();
    cout << "Clase: Mago | Maná Actual: " << mana << endl;
    cout << "-------------------------" << endl;
}