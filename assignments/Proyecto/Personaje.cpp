//GEnera la implementación de la clase base Personaje#include "Personaje.hpp"

using namespace std;




// Unidad.cpp

Unidad::Unidad() 
{
    // constructores
    vida = 100;
    salud = 100;
    ataque = 20;
    nivel = 1;
}

Unidad::Unidad(int v, int a, int n) 
{
    // constructores con parametros
    vida = v;
    salud = v;
    ataque = a;
    nivel = n;
}


//getters 
int Unidad::getVida()
 { return vida; }
int Unidad::getSalud() 
{ return salud; }
int Unidad::getAtaque() 
{ return ataque; }
int Unidad::getNivel()
 { return nivel; }


// setters
void Unidad::setAtaque(int a) 
{ ataque = a; }
void Unidad::setSalud(int s) 
{ salud = s; }
void Unidad::setVida(int v) 
{ vida = v; }
void Unidad::setNivel(int n) 
{ nivel = n; }


// calc para saber cuanta salud queda del 0 al 100
int Unidad::porcentajeSalud() 
{ 
    if (vida == 0) return 0;
    return (salud * 100) / vida; // aqui el calculo
}


// se dibuja la barra de vida con = y % como se menciona en las instrucciones
void Unidad::imprimeBarra() 
{
    int pct = porcentajeSalud(); 
    int caracteresVida = pct / 5; 
    int caracteresPerdidos = 20 - caracteresVida; 

    for (int i = 0; i < caracteresVida; i++) 
    {
        cout << "%";
    }
    for (int i = 0; i < caracteresPerdidos; i++) 
    {
        cout << "=";
    }
}


// se ajusta el ataque dependieno de los nervios o confianza
int Unidad::calculaAtaque(Unidad &objetivo) 
{
    int dañoHecho = 0;
    int numeroRandom = (salud + objetivo.getSalud()) % 5; 

    if (objetivo.getNivel() > nivel) // nervioso
    {   
        int mitadAtaque = ataque / 2; 
        if (mitadAtaque < 1) mitadAtaque = 1; // si es menor a 1 que sea 1
        dañoHecho = 1 + (numeroRandom % mitadAtaque); // calc para que el ataque sea entre 1 (por eso se suma el 1) y la mitad de atque
    } 
    
    else  // confianza
    {
        int mitadAtaque = ataque / 2; 
        int rango = ataque - mitadAtaque; 
        dañoHecho = mitadAtaque + (numeroRandom % (rango + 1)); // ahora el ataque sera de la mitad para arriba
    }
    return dañoHecho;
}


// resta el daño a la salud sin que pase abajo de 0
void Unidad::recibeAtaque(int puntosAtaque) 
{
    salud = salud - puntosAtaque; 
    if (salud < 0) 
    {
        salud = 0; 
    }
}


// se llama al calc del daño y se golpea al objetivo 
void Unidad::atacar(Unidad &objetivo) 
{
    int daño = calculaAtaque(objetivo); 
    objetivo.recibeAtaque(daño); 
    cout << "Ataque de " << daño << " de daño" << endl; // muestra cuando daño se hizo
}


// se printea las stats del personaje con su barra de vida
void Unidad::imprimir() 
{
    cout << "-------------------------" << endl;
    cout << "Nivel: " << nivel << " | Ataque Base: " << ataque << endl;
    cout << "Salud actual: " << salud << " / " << vida << endl;
    cout << "Barra de Vida: [";
    imprimeBarra();
    cout << "] (" << porcentajeSalud() << "%)" << endl;
}











// Guerrero.cpp

Guerrero::Guerrero() : Unidad() 
{
    fuerza = 10;
}

Guerrero::Guerrero(int v, int a, int n, int f) : Unidad(v, a, n) 
{
    fuerza = f;
}


// se suma el daño de la unidad base mas los puntos de fuerza adicionales
int Guerrero::calculaAtaque(Unidad &objetivo) 
{
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












// Arquero.cpp


Arquero::Arquero() : Unidad() 
{
    precision = 20;
}

Arquero::Arquero(int v, int a, int n, int p) : Unidad(v, a, n) 
{
    precision = p;
}



// dependiedo de la suerte del momento su ataque se multiplica por 1.5
int Arquero::calculaAtaque(Unidad &objetivo) 
{
    int dañoBase = Unidad::calculaAtaque(objetivo);
    int suerte = (getSalud() + precision) % 100;
    
    if (suerte < precision) 
    {
        cout << "¡Golpe critico del Arquero!" << endl;
        return dañoBase * 1.5; 
    }
    return dañoBase;
}



// se actualiza el daño y checa la salud para ver si usa el revive
void Arquero::recibeAtaque(int ptosAtaque) 
{
    salud = salud - ptosAtaque;
    if (salud <= 0) 
    {
        salud = 0;
        revive(); 
    }
}



// si la precision es mas del 30% se le quita la mitad de su precision para hacer un movimiento evasivo y revivir con el 15% de vida
void Arquero::revive() 
{
    if (precision >= 30) 
    {
        precision /= 2; 
        salud = vida * 0.15; 
        cout << "¡El Arquero reaccionó con reflejos felinos y esquivó la muerte! Revivió con " << salud << " HP. (Precisión reducida)" << endl;
    } 
    else 
    {
        cout << "¡El Arquero ha muerto! No pudo esquivar el golpe final." << endl;
    }
}

void Arquero::imprimir() 
{
    Unidad::imprimir();
    cout << "Clase: Arquero | Precisión: " << precision << "%" << endl;
    cout << "-------------------------" << endl;
}














// Mago.cpp
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
        cout << "¡El Mago gasto su mana para lanzar un hechizo and revivir! Revivio con " << salud << " de salud" << endl;
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
