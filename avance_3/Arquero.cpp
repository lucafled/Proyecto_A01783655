#include "Arquero.hpp"

using namespace std;

Arquero::Arquero() : Unidad() {
    precision = 20;
}

Arquero::Arquero(int v, int a, int n, int p) : Unidad(v, a, n) {
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
void Arquero::recibeAtaque(int ptosAtaque) {
    salud = salud - ptosAtaque;
    if (salud <= 0) {
        salud = 0;
        revive(); 
    }
}



// si la precision es mas del 30% se le quita la mitad de su precision para hacer un movimiento evasivo y revivir con el 15% de vida
void Arquero::revive() {
    if (precision >= 30) {
        precision /= 2; 
        salud = vida * 0.15; 
        cout << "¡El Arquero reaccionó con reflejos felinos y esquivó la muerte! Revivió con " << salud << " HP. (Precisión reducida)" << endl;
    } else {
        cout << "¡El Arquero ha muerto! No pudo esquivar el golpe final." << endl;
    }
}

void Arquero::imprimir() {
    Unidad::imprimir();
    cout << "Clase: Arquero | Precisión: " << precision << "%" << endl;
    cout << "-------------------------" << endl;
}