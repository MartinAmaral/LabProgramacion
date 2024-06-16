#include "consulta.h"
#include <string>
#include "consulta.h"

class ConsultaEmergencia : public Consulta{
    private:
        string motivo;
    public:
        ConsultaEmergencia(Usuario* paciente, Usuario* medico, Fecha* fecha , string motivo);
        ~ConsultaEmergencia();
};

