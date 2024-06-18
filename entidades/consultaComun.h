#ifndef CONSULTACOMUN_H
#define CONSULTACOMUN_H

#include "consulta.h"
#include "fecha.h"
#include "usuario.h"

class ConsultaComun : public Consulta{
    private:
        Fecha* fechaReserva;
        bool asistio;
    public:
        ConsultaComun(Usuario* paciente, Usuario* medico, Fecha* fechaConsulta, Fecha* fechaReserva);
        Fecha* getFechaReserva() const { return fechaReserva; }
        bool getAsistio() const { return asistio; }
        void setFechaReserva(Fecha* fecha) { fechaReserva = fecha; }
        void setAsistio(bool asistio) { this->asistio = asistio; }
        ~ConsultaComun();
};
#endif
