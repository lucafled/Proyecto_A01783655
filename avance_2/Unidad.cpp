#include "Unidad.hpp"

using namespace std;

Unidad::Unidad() // asignando valores iniciales
{
    vida = 100;
    salud = 100;
    ataque = 20;
    nivel = 1;
}

Unidad::Unidad(int v, int a, int n) // constructor con parametros y nombre
{
    vida = v;
    salud = v;
    ataque = a;
    nivel = n;
}




// asignandole el contenido a los setetrs y getters creados en el archivo.hpp
// getters
int Unidad::getVida() { return vida; }
int Unidad::getSalud() { return salud; }
int Unidad::getAtaque() { return ataque; }
int Unidad::getNivel() { return nivel; }


// setter
void Unidad::setAtaque(int a) { ataque = a; }
void Unidad::setSalud(int s) { salud = s; }
void Unidad::setVida(int v) { vida = v; }
void Unidad::setNivel(int n) { nivel = n; }


int Unidad::porcentajeSalud()  // calculo para la salud, vida siendo el maximo (100) y la salud el estado actual despeus de daño
{ 
    if (vida == 0) return 0;
    return (salud * 100) / vida;
}

void Unidad::imprimeBarra() 
{
    int pct = porcentajeSalud(); // pct guarda el % actual de salud 
    int caracteresVida = pct / 5; // la barra de 20 caracteres en total, se divide de 5 en 5, entonces si tiene la mitad de la vida solo aparece la mitad de la barra
    int caracteresPerdidos = 20 - caracteresVida; // y aqui se obtiene el numero actual de carecteres que se han perdido 


    for (int i = 0; i < caracteresVida; i++) // primero se imprimen los "%%%%%%"
    {
        cout << "%";
    }
    for (int i = 0; i < caracteresPerdidos; i++) // para despues rellenar con la vida que falta con "======"
    {
        cout << "=";
    }
}


int Unidad::calculaAtaque(Unidad &objetivo) 
{
    int dañoHecho = 0;
    
   
    int numeroRandom = (salud + objetivo.getSalud()) % 5; // obtener nmero random 

    if (objetivo.getNivel() > nivel) // casos de nerviosismo
    {   
        int mitadAtaque = ataque / 2; // mitad del ataque 
        if (mitadAtaque < 1) mitadAtaque = 1; // si la mitad es 0 se vuelve 1
        
        dañoHecho = 1 + (numeroRandom % mitadAtaque); // y se calcula un ataque dependiendo del numeroRandom, que sea es entre 1 y la mitad del ataque dependiendo de caso
    }  

    
    else // caso de confianza
    {
        int mitadAtaque = ataque / 2; 
        int rango = ataque - mitadAtaque; // diferencia entre el min y max daño posible
        
        dañoHecho = mitadAtaque + (numeroRandom % (rango + 1)); // aqui se saca el numero del ataque para que sea de la mitad de ataque hacia arriba
    }
    return dañoHecho;
}






void Unidad::recibeAtaque(int puntosAtaque) // cuanto daño se le hace a nuestro personaje
{
    salud = salud - puntosAtaque; // calculo
    if (salud < 0) 
    {
        salud = 0; // si es menor que 0 pues que sea 0
    }
}




void Unidad::atacar(Unidad &objetivo) // el turno para saber cuando les toca golpear (& usado para modificar el original en vez de hacer una copia)
{
    int daño = calculaAtaque(objetivo); // ver cuando se le quita de daño a nuestro personaje por el nivel del boss/enemigo
    objetivo.recibeAtaque(daño); // donde se le quita salud al enemigo 

    cout << "Ataque de " << daño << " de daño" << endl; // print
}






void Unidad::imprimir() 
 {
    cout << "-------------------------" << endl;
    cout << "Nivel: " << nivel << " | Ataque Base: " << ataque << endl;
    cout << "Salud actual: " << salud << " / " << vida << endl;
    cout << "Barra de Vida: [";
    imprimeBarra();
    cout << "] (" << porcentajeSalud() << "%)" << endl;
    cout << "-------------------------" << endl;
}