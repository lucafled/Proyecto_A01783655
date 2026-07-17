#include "Unidad.hpp"

using namespace std;

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
int Unidad::getVida() { return vida; }
int Unidad::getSalud() { return salud; }
int Unidad::getAtaque() { return ataque; }
int Unidad::getNivel() { return nivel; }

// setters
void Unidad::setAtaque(int a) { ataque = a; }
void Unidad::setSalud(int s) { salud = s; }
void Unidad::setVida(int v) { vida = v; }
void Unidad::setNivel(int n) { nivel = n; }


// calc para saber cuanta salud queda del 0 al 100
int Unidad::porcentajeSalud() { 
    if (vida == 0) return 0;
    return (salud * 100) / vida; // aqui el calculo
}


// se dibuja la barra de vida con = y % como se menciona en las instrucciones
void Unidad::imprimeBarra() {
    int pct = porcentajeSalud(); 
    int caracteresVida = pct / 5; 
    int caracteresPerdidos = 20 - caracteresVida; 

    for (int i = 0; i < caracteresVida; i++) {
        cout << "%";
    }
    for (int i = 0; i < caracteresPerdidos; i++) {
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
    } else { // confianza
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


// se llama al cald del daño y se golpea al objetivo 
void Unidad::atacar(Unidad &objetivo) {
    int daño = calculaAtaque(objetivo); 
    objetivo.recibeAtaque(daño); 
    cout << "Ataque de " << daño << " de daño" << endl; // muestra cuando daño se hizo
}


// se printea las stats del personaje con su barra de vida
void Unidad::imprimir() {
    cout << "-------------------------" << endl;
    cout << "Nivel: " << nivel << " | Ataque Base: " << ataque << endl;
    cout << "Salud actual: " << salud << " / " << vida << endl;
    cout << "Barra de Vida: [";
    imprimeBarra();
    cout << "] (" << porcentajeSalud() << "%)" << endl;
}