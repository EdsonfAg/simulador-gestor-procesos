#pragma once

#include <string>
#include <cstdint>
#include "../core/GestorRecursos/GestorRecursos.h"
#include "../core/GestorLogs/GestorLogs.h"
#include "../core/Planificador/Planificador.h"

class MotorSimulacion {
private:
    GestorLogs registros;
    GestorRecursos recursos;
    Planificador planificador;

public:
    MotorSimulacion();

    // ================= CREAR PROCESO =================
    void crearProceso(std::string nombre,int rafaga,int prioridad,int memoria);

    // ================= RAM =================
    bool validarMemoriaProceso(uint32_t memoria) const;

    bool asignarMemoriaProceso(uint32_t pid,uint32_t memoria);

    uint32_t liberarMemoriaProceso(uint32_t pid);

    // ================= CPU =================
    bool asignarCPUProceso(uint32_t pid);

    void liberarCPUProceso(uint32_t pid);

    // ================= LIBERAR MEMORIA =================
    void liberarMemoria(uint32_t pid);

    // ================= GETTERS =================
    uint32_t obtenerMemoriaUsada() const;
};