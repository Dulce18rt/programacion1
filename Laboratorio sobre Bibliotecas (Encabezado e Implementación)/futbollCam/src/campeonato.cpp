#include "Campeonato.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUMERO_EQUIPOS = 6;
const int MAX_GOLES = 10;
const int MIN_GOLES = 0;

Campeonato::Campeonato() {
    equipos.resize(NUMERO_EQUIPOS);
    resultados.resize(NUMERO_EQUIPOS, vector< pair<int,int> >(NUMERO_EQUIPOS, make_pair(0,0)));
    estadisticas.resize(NUMERO_EQUIPOS, vector<int>(7, 0));
}

void Campeonato::ingresarEquipos() {
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        cout << "Ingrese el nombre del equipo " << i + 1 << ": ";
        cin >> equipos[i];
    }
}

void Campeonato::llenarResultados() {
    char modo;
    cout << "Desea ingresar los resultados manualmente (m) o generarlos aleatoriamente (a)? ";
    cin >> modo;

    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = i + 1; j < NUMERO_EQUIPOS; j++) {
            if (modo == 'm' || modo == 'M') {
                int golesI, golesJ;
                // Ingresar goles de i contra j
                do {
                    cout << "Ingrese goles de " << equipos[i] << " contra " << equipos[j] << ": ";
                    cin >> golesI;
                } while (golesI < MIN_GOLES || golesI > MAX_GOLES);

                // Ingresar goles de j contra i
                do {
                    cout << "Ingrese goles de " << equipos[j] << " contra " << equipos[i] << ": ";
                    cin >> golesJ;
                } while (golesJ < MIN_GOLES || golesJ > MAX_GOLES);

                resultados[i][j].first  = golesI;
                resultados[i][j].second = golesJ;
                // Partido de vuelta
                resultados[j][i].first  = golesJ;
                resultados[j][i].second = golesI;
            } else {
                // Generación aleatoria
                int golesI = rand() % (MAX_GOLES + 1);
                int golesJ = rand() % (MAX_GOLES + 1);

                resultados[i][j].first  = golesI;
                resultados[i][j].second = golesJ;
                resultados[j][i].first  = golesJ;
                resultados[j][i].second = golesI;
            }
        }
    }
}

void Campeonato::calcularEstadisticas() {
    // Reiniciamos estadísticas
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = 0; j < 7; j++) {
            estadisticas[i][j] = 0;
        }
    }
    // Recorremos cada partido (i vs j)
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = 0; j < NUMERO_EQUIPOS; j++) {
            if (i != j) {
                estadisticas[i][0]++; // Partido jugado
                int golesFavor = resultados[i][j].first;
                int golesContra = resultados[i][j].second;
                estadisticas[i][4] += golesFavor;
                estadisticas[i][5] += golesContra;

                if (golesFavor > golesContra) {
                    estadisticas[i][1]++;       // Ganados
                    estadisticas[i][6] += 3;      // 3 puntos
                } else if (golesFavor < golesContra) {
                    estadisticas[i][3]++;       // Perdidos
                } else {
                    estadisticas[i][2]++;       // Empatados
                    estadisticas[i][6] += 1;      // 1 punto
                }
            }
        }
    }
}

void Campeonato::imprimirTabla() {
    cout << "\n===== Tabla de Posiciones =====\n";
    cout << "Equipo\tPJ\tPG\tPE\tPP\tGF\tGC\tPts\n";

    int campeon = 0;
    int ultimo = 0;
    int maxPuntos = -1;
    int minPuntos = 999999;

    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        int PJ  = estadisticas[i][0];
        int PG  = estadisticas[i][1];
        int PE  = estadisticas[i][2];
        int PP  = estadisticas[i][3];
        int GF  = estadisticas[i][4];
        int GC  = estadisticas[i][5];
        int Pts = estadisticas[i][6];

        cout << equipos[i] << "\t"
             << PJ  << "\t"
             << PG  << "\t"
             << PE  << "\t"
             << PP  << "\t"
             << GF  << "\t"
             << GC  << "\t"
             << Pts << "\n";

        if (Pts > maxPuntos) {
            maxPuntos = Pts;
            campeon = i;
        }
        if (Pts < minPuntos) {
            minPuntos = Pts;
            ultimo = i;
        }
    }
    cout << "\nCampeon: " << equipos[campeon] << " con " << maxPuntos << " puntos.\n";
    cout << "Ultimo lugar (descenso): " << equipos[ultimo] << " con " << minPuntos << " puntos.\n\n";
}
