#ifndef CONSULTASDIA_H
#define CONSULTASDIA_H

#include <string>
using namespace std;

class ConsultaDia{

    private:
        int ciPaciente;
        string nombrePaciente;
        string nombreMedico;
    public:
        ConsultaDia(int ciPaciente,string nombrePaciente, string nombreMedico);
        int getCiPaciente();
        string getNombrePaciente();
        string getNombreMedico();

        ~ConsultaDia();
};
#endif
