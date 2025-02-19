#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define NUMERO_ALUMNOS 5
#define NUMERO_NOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100

// Declaración de prototipos de función
void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad);

int main() {
    srand(getpid());
    llamaCiclo();
    return 0;
}

void llamaCiclo() {
    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    char opcion;
    bool repetir = true;
    float promedio_facultad_1, promedio_facultad_2, promedio_facultad_3;
    char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA] = {"Carlos","Luis","Maria","Pedro","Juan"};

    // Acumuladores
    int total_calculos = 0;
    int victorias_ingenieria = 0, victorias_arquitectura = 0, victorias_administracion = 0;

    do {
        system("cls");
        promedio_facultad_1 = 0;
        promedio_facultad_2 = 0;
        promedio_facultad_3 = 0;

        cout << "*** Comparativo de Facultades ***" << endl << endl;
        llenarMatriz(matriz_facultad_1);
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria");

        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");

        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Administracion");

        // Determinar la facultad ganadora
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3) {
            cout << "La facultad con el mejor promedio es: Facultad de Ingenieria Promedio: " << promedio_facultad_1 << endl;
            victorias_ingenieria++;
        } else if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3) {
            cout << "La facultad con el mejor promedio es: Facultad de Arquitectura Promedio: " << promedio_facultad_2 << endl;
            victorias_arquitectura++;
        } else if (promedio_facultad_3 > promedio_facultad_1 && promedio_facultad_3 > promedio_facultad_2) {
            cout << "La facultad con el mejor promedio es: Facultad de Administracion Promedio: " << promedio_facultad_3 << endl;
            victorias_administracion++;
        } else {
            cout << "Algunas facultades tienen el mismo promedio" << endl;
        }

        total_calculos++;
        cout << "Desea otro cálculo (s/n)? ";
        cin >> opcion;

        if (opcion == 'n') {
            repetir = false;
            cout << "\nResultados finales:\n";
            cout << "Total de cálculos realizados: " << total_calculos << " veces.\n";
            cout << "Facultad de Ingenieria gano: " << victorias_ingenieria << " veces.\n";
            cout << "Facultad de Arquitectura gano: " << victorias_arquitectura << " veces.\n";
            cout << "Facultad de Administración gano: " << victorias_administracion << " veces.\n";

            // Determinar la facultad con más victorias
            if (victorias_ingenieria > victorias_arquitectura,victorias_administracion) {
                cout << "La mejor facultad es: Facultad de Ingenieria.\n";
            } else if (victorias_arquitectura > victorias_ingenieria,victorias_administracion) {
                cout << "La mejor facultad es: Facultad de Arquitectura.\n";
            } else if (victorias_administracion > victorias_ingenieria, victorias_arquitectura) {
                cout << "La mejor facultad es: Facultad de Administracion.\n";
            } else {
                cout << "No hay una mejor facultad, hay empate.\n";
            }
        }
    } while (repetir);
}

int busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]) {
    for (int y = 0; y < NUMERO_ALUMNOS; y++) {
        float suma = 0;
        for (int x = 0; x < NUMERO_NOTAS; x++) {
            int calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            suma += calificacion;
            matriz[y][x] = calificacion;
        }
        matriz[y][NUMERO_NOTAS] = suma;
    }
}

void imprimirMatrizLinea() {
    cout << "+--------";
    for (int x = 0; x < NUMERO_NOTAS + 1; x++) {
        cout << "+---------";
    }
    cout << "+\n";
}

float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad) {
    float totalGeneral = 0;
    cout << nombreFacultad << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Alumno";
    for (int x = 0; x < NUMERO_NOTAS; x++) {
        cout << setw(9) << "Nota" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (int y = 0; y < NUMERO_ALUMNOS; y++) {
        cout << "!" << setw(8) << alumnos[y] << "!";
        for (int x = 0; x < NUMERO_NOTAS; x++) {
            cout << setw(9) << matriz[y][x] << "!";
        }
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += promedio;
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    return totalGeneral / NUMERO_ALUMNOS;
}
