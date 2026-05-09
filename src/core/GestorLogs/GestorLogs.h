#ifndef GESTOR_LOGS_H
#define GESTOR_LOGS_H

#include <string>
#include <vector>
#include <cstdint>
#include <iostream>

class GestorLogs {
private:
    std::vector<std::string> logsRAM;
    std::vector<std::string> logsCPU;

    // ================= IMPRIMIR LOGS =================
    static void anotarEvento(std::vector<std::string>& contenedor, const std::string& mensaje);

public:
    GestorLogs();

    // ================= RAM =================
    void logValidarDisponibilidadMemoria(uint32_t mb);
    void logReservarMemoria(uint32_t pid, uint32_t mb);
    void logAsignarMemoria(uint32_t pid, uint32_t mb);
    void logLiberarMemoria(uint32_t pid, uint32_t mb);

    // ================= CPU =================
    void logAsignarCPU(uint32_t pid);
    void logLiberarCPU();

    // ================= FINALIZAR =================
    void logFinalizarMemoria(uint32_t pid);
    void logFinalizarCPU(uint32_t pid);

    // ================= EXPORTAR  =================
    std::vector<std::string> exportarLogsRAM() const;
    std::vector<std::string> exportarLogsCPU() const;
};

#endif