#include "consulta.h"
#include "fecha.h"
#include "usuario.h"

class ConsultaComun : public Consulta
{
    private:
        Fecha* fechaReserva;
        bool asistio;
    public:
        ConsultaComun(Usuario* paciente,Usuario* medico,Fecha* fechaConsulta,Fecha* fechaReserva);
        ~ConsultaComun();
};

