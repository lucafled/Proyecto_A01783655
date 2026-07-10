#include "Arquero.hpp"

Arquero::Arquero() : Unidad() {
    precision = 20;
}

Arquero::Arquero(int v, int a, int n, int p) : Unidad(v, a, n) {
    precision = p;
}

int Arquero::calculaAtaque(Unidad &objetivo) {
    int dañoBase = Unidad::calculaAtaque(objetivo);
    int suerte = (getSalud() + precision) % 100;
    
    if (suerte < precision) {
        cout << "¡Golpe Crítico del Arquero!" << endl;
        return dañoBase * 1.5; 
    }
    return dañoBase;
}

void Arquero::imprimir() {
    Unidad::imprimir();
    cout << "Clase: Arquero | Precisión: " << precision << "%" << endl;
    cout << "-------------------------" << endl;
}