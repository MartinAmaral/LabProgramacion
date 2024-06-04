#include "consulta.h"
#include "fecha.h"

class ConsultaComun : Consulta
{
    private:
        Fecha fechaReserva;
        bool asistio;
    public:
        ConsultaComun(Fecha fechaConsulta, Fecha fechaReserva);
        ~ConsultaComun();
};

