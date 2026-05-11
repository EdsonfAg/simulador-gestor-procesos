#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H

#include "../core/GestorRecursos/GestorRecursos.h"
#include <string>
#include <queue>
#include <map>
#include <vector>

class Planificador {
private:
    // Cola de procesos listos
    std::queue<uint32_t> cola_listos;

    // Tabla de procesos usando PID como clave
    std::map<uint32_t, Proceso> tabla_procesos;

public:
    // NUEVO: historial de procesos terminados
    std::vector<uint32_t> historial_terminados;

    // Constructor
    Planificador();

    // Crear y asignar proceso
    uint32_t crearYAsignarProceso(std::string nombre,int prioridad,uint64_t rafaga,uint32_t memoria);

    // Ejecutar despachador
    void ejecutarDespachador();
};

#endif