#include "../core/CausaTerminacion/CausaTerminacion.h"

// Constructor
CausaTerminacion::CausaTerminacion(TipoTerminacion tipo,
                                   ModuloFallo modulo,
                                   DetalleFallo detalle)
    : tipo(tipo), modulo(modulo), detalle(detalle) {}

// Getters
TipoTerminacion CausaTerminacion::getTipo() const {
    return tipo;
}

ModuloFallo CausaTerminacion::getModulo() const {
    return modulo;
}

DetalleFallo CausaTerminacion::getDetalle() const {
    return detalle;
}

// ================= DESCRIPCION =================
std::string CausaTerminacion::obtenerDescripcion() const {

    switch (tipo) {

        case TipoTerminacion::NORMAL:
            return "Proceso finalizado correctamente.";

        case TipoTerminacion::USUARIO:
            return "Proceso terminado por el usuario.";

        case TipoTerminacion::INTERBLOQUEO:
            return "Proceso detenido por interbloqueo.";

        case TipoTerminacion::ERROR:
            switch (detalle) {

                // RAM
                case DetalleFallo::MEMORIA_INSUFICIENTE_FAKE:
                    return "Error: memoria insuficiente durante la ejecucion.";

                case DetalleFallo::FRAGMENTACION_FAKE:
                    return "Error: fragmentacion de memoria detectada.";

                // CPU
                case DetalleFallo::CPU_SATURADA_FAKE:
                    return "Error: CPU saturada.";

                case DetalleFallo::QUANTUM_AGOTADO_FAKE:
                    return "Error: quantum de CPU agotado.";

                default:
                    return "Error desconocido.";
            }

        default:
            return "Causa desconocida.";
    }
}

// ================= SOLUCION =================
std::string CausaTerminacion::obtenerSolucion() const {

    switch (tipo) {

        case TipoTerminacion::NORMAL:
            return "No se requiere accion.";

        case TipoTerminacion::USUARIO:
            return "No se requiere accion adicional.";

        case TipoTerminacion::INTERBLOQUEO:
            return "Revisar recursos compartidos y evitar ciclos de espera.";

        case TipoTerminacion::ERROR:
            switch (detalle) {

                // RAM
                case DetalleFallo::MEMORIA_INSUFICIENTE_FAKE:
                    return "Liberar memoria y reintentar.";

                case DetalleFallo::FRAGMENTACION_FAKE:
                    return "Compactar memoria.";

                // CPU
                case DetalleFallo::CPU_SATURADA_FAKE:
                    return "Esperar liberacion de CPU.";

                case DetalleFallo::QUANTUM_AGOTADO_FAKE:
                    return "Reasignar quantum.";

                default:
                    return "No hay solucion definida.";
            }

        default:
            return "Sin solucion.";
    }
}