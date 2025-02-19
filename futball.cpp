#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

const int TOTAL_EQUIPOS = 6;
const int GOLES_MAXIMOS = 10;

struct Equipo {
    string nombre;
    int partidosJugados = 0;
    int partidosGanados = 0;
    int partidosPerdidos = 0;
    int partidosEmpatados = 0;
    int totalPuntos = 0;
};

void generarResultados(int resultados[TOTAL_EQUIPOS][TOTAL_EQUIPOS]) {
    srand(time(0));
    for (int i = 0; i < TOTAL_EQUIPOS; i++) {
        for (int j = 0; j < TOTAL_EQUIPOS; j++) {
            if (i != j) {
                resultados[i][j] = rand() % (GOLES_MAXIMOS + 1);
                resultados[j][i] = rand() % (GOLES_MAXIMOS + 1);
            } else {
                resultados[i][j] = -1; // Sin enfrentamiento
            }
        }
    }
}

void calcularTabla(int resultados[TOTAL_EQUIPOS][TOTAL_EQUIPOS], vector<Equipo> &equipos) {
    for (int i = 0; i < TOTAL_EQUIPOS; i++) {
        for (int j = 0; j < TOTAL_EQUIPOS; j++) {
            if (i != j) {
                equipos[i].partidosJugados++;
                if (resultados[i][j] > resultados[j][i]) {
                    equipos[i].partidosGanados++;
                    equipos[i].totalPuntos += 3;
                    equipos[j].partidosPerdidos++;
                } else if (resultados[i][j] < resultados[j][i]) {
                    equipos[j].partidosGanados++;
                    equipos[j].totalPuntos += 3;
                    equipos[i].partidosPerdidos++;
                } else {
                    equipos[i].partidosEmpatados++;
                    equipos[j].partidosEmpatados++;
                    equipos[i].totalPuntos += 1;
                    equipos[j].totalPuntos += 1;
                }
            }
        }
    }
}

void mostrarTabla(const vector<Equipo> &equipos) {
    cout << "\nTabla de Posiciones:" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Equipo\tPJ\tG\tE\tP\tPuntos" << endl;
    for (const auto &equipo : equipos) {
        cout << equipo.nombre << "\t" << equipo.partidosJugados << "\t" << equipo.partidosGanados
             << "\t" << equipo.partidosEmpatados << "\t" << equipo.partidosPerdidos << "\t" << equipo.totalPuntos << endl;
    }
}

void determinarGanadorYDescenso(const vector<Equipo> &equipos) {
    int puntosMaximos = -1, puntosMinimos = 1000;
    string equipoGanador, equipoDescendido;

    for (const auto &equipo : equipos) {
        if (equipo.totalPuntos > puntosMaximos) {
            puntosMaximos = equipo.totalPuntos;
            equipoGanador = equipo.nombre;
        }
        if (equipo.totalPuntos < puntosMinimos) {
            puntosMinimos = equipo.totalPuntos;
            equipoDescendido = equipo.nombre;
        }
    }
    cout << "\nEl equipo ganador del campeonato es: " << equipoGanador << endl;
    cout << "El equipo que desciende es: " << equipoDescendido << endl;
}

int main() {
    vector<Equipo> equipos(TOTAL_EQUIPOS);
    int resultados[TOTAL_EQUIPOS][TOTAL_EQUIPOS];
    char opcion;

    do {
        cout << "Ingrese los nombres de los " << TOTAL_EQUIPOS << " equipos:" << endl;
        for (int i = 0; i < TOTAL_EQUIPOS; i++) {
            cout << "Equipo " << i + 1 << ": ";
            cin >> equipos[i].nombre;
        }

        generarResultados(resultados);
        calcularTabla(resultados, equipos);
        mostrarTabla(equipos);
        determinarGanadorYDescenso(equipos);

        cout << "\nDesea generar otro campeonato? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
