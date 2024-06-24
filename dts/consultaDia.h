#ifndef CONSULTADIA_H
#define CONSULTADIA_H

#include <string>
#include "../entidades/consulta.h"
using namespace std;

class ConsultaDia{
    private:
        int ciPaciente;
        Consulta* consulta;
    public:
        ConsultaDia(int ciPaciente,Consulta* consulta);
        int getCiPaciente();
        Consulta* getConsulta();

        ~ConsultaDia();
};
#endif
