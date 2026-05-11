#include "../core/MotorSimulacion/MotorSimulacion.h"

// ================= CONSTRUCTOR =================
MotorSimulacion::MotorSimulacion():recursos(&registros),planificador(){
}

// ================= RAM =================
bool MotorSimulacion::validarMemoriaProceso(uint32_t memoria) const {
    return recursos.validarDisponibilidadMemoria(memoria);
}

bool MotorSimulacion::asignarMemoriaProceso(uint32_t pid,uint32_t memoria) {
    return recursos.asignarMemoria(pid, memoria);
}

uint32_t MotorSimulacion::liberarMemoriaProceso(uint32_t pid) {
    return recursos.liberarMemoria(pid);
}

// ================= CPU =================
bool MotorSimulacion::asignarCPUProceso(uint32_t pid) {
    return recursos.asignarCPU(pid);
}

void MotorSimulacion::liberarCPUProceso(uint32_t pid) {
    recursos.liberarCPU(pid);
}

// ================= CREACIÓN DE PROCESO MEMORIA=================
void MotorSimulacion::crearProceso(std::string nombre,int rafaga,int prioridad,int memoria) {

    uint32_t memReq = static_cast<uint32_t>(memoria);

    // 1. Validar memoria
    if (!validarMemoriaProceso(memReq)) {
        std::cout << "Memoria insuficiente\n";
        return;
    }

    // 2. Crear proceso usando el planificador
    uint32_t pid = planificador.crearYAsignarProceso(nombre,prioridad,rafaga,memReq);

    // 3. Asignar memoria al proceso
    asignarMemoriaProceso(pid, memReq);

}

// ================= LIBERAR MEMORIA =================
void MotorSimulacion::liberarMemoria(uint32_t pid) {
    liberarMemoriaProceso(pid);
}

// ================= GETTERS =================
uint32_t MotorSimulacion::obtenerMemoriaUsada() const {
    return recursos.obtenerMemoriaUsada();
}