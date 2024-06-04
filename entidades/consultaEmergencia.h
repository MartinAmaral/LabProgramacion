#include "consulta.h"
#include <string>


class ConsultaEmergencia : Consulta
{
    private:
        string motivo;
    public:
        ConsultaEmergencia(Fecha fecha, string hora, string motivo);
        ~ConsultaEmergencia();
};

