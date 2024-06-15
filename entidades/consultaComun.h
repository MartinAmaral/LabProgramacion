#include "consulta.h"
#include "fecha.h"
#include "usuario.h"

class ConsultaComun : Consulta
{
    private:
        Fecha* fechaReserva;
        bool asistio;
    public:
        ConsultaComun(Usuario* paciente,Usuario* medico,Fecha* fechaConsulta,Fecha* fechaReserva);
        ~ConsultaComun();
};

