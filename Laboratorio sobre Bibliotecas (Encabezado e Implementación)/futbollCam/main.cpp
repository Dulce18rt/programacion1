#include "Campeonato.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));  // Semilla para números aleatorios

    bool repetir = true;
    while (repetir) {
        Campeonato c;
        c.ingresarEquipos();
        c.llenarResultados();
        c.calcularEstadisticas();
        c.imprimirTabla();

        cout << "¿Desea simular otro campeonato? (s/n): ";
        char opcion;
        cin >> opcion;
        if (opcion == 'n' || opcion == 'N') {
            repetir = false;
        }
    }
    return 0;
}
