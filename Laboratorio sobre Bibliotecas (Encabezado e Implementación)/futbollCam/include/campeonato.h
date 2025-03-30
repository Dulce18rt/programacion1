#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include <vector>
#include <string>
#include <utility>

class Campeonato {
private:
    // Nombres de los equipos
    std::vector<std::string> equipos;
    // Matriz de resultados: resultados[i][j] = {goles de i contra j, goles de j contra i}
    std::vector<std::vector< std::pair<int,int> >> resultados;
    // Estadísticas de cada equipo: {PJ, PG, PE, PP, GF, GC, Pts}
    std::vector<std::vector<int>> estadisticas;

public:
    Campeonato();
    void ingresarEquipos();
    void llenarResultados();
    void calcularEstadisticas();
    void imprimirTabla();
};

#endif // CAMPEONATO_H
