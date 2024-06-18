#include <iostream>
#include <string>
#include "../controllers/CConsulta.h"
#include "../entidades/fecha.h"
#include "../entidades/usuario.h"
using namespace std;

void registrarConsulta() {
    CConsulta* consultaCtrl = CConsulta::getInstanceConsulta();
    string ciMedico, ciPaciente, motivo;
    int dia, mes, ano, diaReserva, mesReserva, anoReserva;
    bool esEmergencia, asistio;
    char tipoConsulta, respuestaAsistio;

    cout << "Ingrese CI del médico: ";
    cin >> ciMedico;
    cout << "Ingrese CI del paciente: ";
    cin >> ciPaciente;
    cout << "Es una consulta de emergencia? (s/n): ";
    cin >> tipoConsulta;
    esEmergencia = (tipoConsulta == 's' || tipoConsulta == 'S');

    cout << "Ingrese la fecha de la consulta (dd mm aaaa): ";
    cin >> dia >> mes >> ano;
    Fecha fechaConsulta(dia, mes, ano);

    if (esEmergencia) {
        cout << "Ingrese el motivo de la consulta: ";
        cin.ignore();
        getline(cin, motivo);
        consultaCtrl->ingresarDatosConsultaEmergencia(new Usuario(stoi(ciMedicoStr), ""), new Usuario(stoi(ciPacienteStr), ""), fechaConsulta, motivo);
    } else {
        cout << "Ingrese la fecha de reserva (dd mm aaaa): ";
        cin >> diaReserva >> mesReserva >> anoReserva;
        Fecha fechaReserva(anoReserva, mesReserva, diaReserva);
        cout << "El paciente asistió a la consulta? (s/n): ";
        cin >> respuestaAsistio;
        asistio = (respuestaAsistio == 's' || respuestaAsistio == 'S');
        consultaCtrl->ingresarDatosConsultaComun(new Usuario(stoi(ciMedicoStr), ""), new Usuario(stoi(ciPacienteStr), ""), fechaConsulta, new Fecha(fechaReserva), asistio);
    }

    cout << "Consulta registrada exitosamente!" << endl;

}