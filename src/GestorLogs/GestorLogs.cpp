#include "../core/GestorLogs/GestorLogs.h"

// Constructor
GestorLogs::GestorLogs() {
}

// ================= MÉTODO CENTRAL =================

void GestorLogs::anotarEvento(std::vector<std::string>& contenedor, const std::string& mensaje) {
    contenedor.push_back(mensaje);
    std::cout << mensaje << std::endl;
}

// ================= RAM =================

void GestorLogs::logValidarDisponibilidadMemoria(uint32_t mb) {
    anotarEvento(logsRAM, "Validando " + std::to_string(mb) + " MB de RAM");
}

void GestorLogs::logReservarMemoria(uint32_t pid, uint32_t mb) {
    anotarEvento(logsRAM, "PID " + std::to_string(pid) +
                          " reserva " + std::to_string(mb) + " MB");
}

void GestorLogs::logAsignarMemoria(uint32_t pid, uint32_t mb) {
    anotarEvento(logsRAM, "PID " + std::to_string(pid) +
                          " asigna " + std::to_string(mb) + " MB");
}

void GestorLogs::logLiberarMemoria(uint32_t pid, uint32_t mb) {
    anotarEvento(logsRAM, "PID " + std::to_string(pid) +
                          " libera " + std::to_string(mb) + " MB");
}

// ================= CPU =================

void GestorLogs::logAsignarCPU(uint32_t pid) {
    anotarEvento(logsCPU, "CPU asignada al PID " + std::to_string(pid));
}

void GestorLogs::logLiberarCPU() {
    anotarEvento(logsCPU, "CPU liberada");
}

// ================= EXPORTAR =================

std::vector<std::string> GestorLogs::exportarLogsRAM() const {
    return logsRAM;
}

std::vector<std::string> GestorLogs::exportarLogsCPU() const {
    return logsCPU;
}