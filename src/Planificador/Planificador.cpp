#include "../core/Planificador/Planificador.h"
#include "../core/MotorSimulacion/MotorSimulacion.h"


// Creación y registro de procesos
uint32_t Planificador::crearYAsignarProceso(std::string nombre, int prioridad, uint64_t rafaga, uint32_t memoria) {
    // 1. Instanciamos el proceso
    Proceso nuevo_proceso(nombre, prioridad, rafaga, memoria);
    uint32_t nuevo_pid = nuevo_proceso.obtenerPid();

    // 2. Lo guardamos en el mapa. Usamos emplace porque es más eficiente que insert.
    tabla_procesos.emplace(nuevo_pid, nuevo_proceso);

    // 3. Formamos su PID en la cola de listos
    cola_listos.push(nuevo_pid);

    return nuevo_pid;
}

/*if (tabla_procesos.at(pid_en_ejecucion).obtenerRafaga() == 0) {

    // liberar memoria
    liberarMemoria(pid_en_ejecucion);

    // guardar historial
    historial_terminados.push_back(pid_en_ejecucion);
}*/