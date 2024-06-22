#ifndef CONSULTACOMUN_H
#define CONSULTACOMUN_H

#include "consulta.h"
#include "fecha.h"
#include "usuario.h"

class ConsultaComun : public Consulta {
private:
    Fecha* fechaReserva;
    bool asistio;

public:
    ConsultaComun(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta, Fecha* fechaReserva, bool asistio);
    Fecha* getFechaReserva();
    bool getAsistio();
    void setFechaReserva(Fecha* fecha);
    void setAsistio(bool asistio);
    ~ConsultaComun();
};

#endif
