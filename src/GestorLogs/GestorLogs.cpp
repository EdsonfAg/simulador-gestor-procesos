#include "../core/GestorLogs/GestorLogs.h"

// ================= CONSTRUCTOR =================
GestorLogs::GestorLogs() {
}

// ================= UTILIDAD =================
void GestorLogs::anotarEvento(std::vector<std::string>& contenedor, const std::string& mensaje) {
    contenedor.push_back(mensaje);
    std::cout << mensaje << std::endl;
}

// ================= HISTORIAL =================
std::vector<std::string> GestorLogs::exportarHistorialLogs() const {
    return historialLogs;
}

// ================= RAM =================
void GestorLogs::logValidarDisponibilidadMemoria(uint32_t mb) {
    anotarEvento(logsRAM, "Validando " + std::to_string(mb) + " MB de RAM");
}

void GestorLogs::logAsignarMemoria(uint32_t pid, uint32_t mb) {
    anotarEvento(logsRAM, "PID " + std::to_string(pid) +
                          " asigna " + std::to_string(mb) + " MB");
}

void GestorLogs::logLiberarMemoria(uint32_t pid, uint32_t mb) {
    anotarEvento(logsRAM, "PID " + std::to_string(pid) +
                          " libera " + std::to_string(mb) + " MB");
}

std::vector<std::string> GestorLogs::exportarLogsRAM() {
    historialLogs.insert(historialLogs.end(), logsRAM.begin(), logsRAM.end());
    return logsRAM;
}

// ================= CPU =================
void GestorLogs::logAsignarCPU(uint32_t pid) {
    anotarEvento(logsCPU, "CPU asignada al PID " + std::to_string(pid));
}

void GestorLogs::logLiberarCPU() {
    anotarEvento(logsCPU, "CPU liberada");
}

std::vector<std::string> GestorLogs::exportarLogsCPU() {
    historialLogs.insert(historialLogs.end(), logsCPU.begin(), logsCPU.end());
    return logsCPU;
}