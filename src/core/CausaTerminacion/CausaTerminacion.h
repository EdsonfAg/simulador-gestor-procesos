#ifndef CAUSA_TERMINACION_H
#define CAUSA_TERMINACION_H

#include <string>

// ================= ENUMS QUITAR DE AQUI =================
enum class TipoTerminacion {
    NORMAL,
    ERROR,
    INTERBLOQUEO,
    USUARIO
};

enum class ModuloFallo {
    NINGUNO,
    CPU,
    RAM
};

enum class DetalleFallo {
    NINGUNO,

    // RAM
    MEMORIA_INSUFICIENTE_FAKE,
    FRAGMENTACION_FAKE,

    // CPU
    CPU_SATURADA_FAKE,
    QUANTUM_AGOTADO_FAKE
};

// ================= CLASE ORIGINAL =================
class CausaTerminacion {

private:
    TipoTerminacion tipo;
    ModuloFallo modulo;
    DetalleFallo detalle;

public:
    CausaTerminacion(TipoTerminacion tipo,
                     ModuloFallo modulo = ModuloFallo::NINGUNO,
                     DetalleFallo detalle = DetalleFallo::NINGUNO);

    TipoTerminacion getTipo() const;
    ModuloFallo getModulo() const;
    DetalleFallo getDetalle() const;

    std::string obtenerDescripcion() const;
    std::string obtenerSolucion() const;
};

#endif