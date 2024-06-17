#include <iostream>
#include <string>
#include "../controllers/CConsulta.h"
#include "../entidades/fecha.h"

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
        cout << "Ingrese motivo de la consulta de emergencia: ";
        cin.ignore();  // Para limpiar el buffer de entrada
        getline(cin, motivo);
        try {
            consultaCtrl->ingresarDatosConsultaEmergencia(ciMedico, ciPaciente, fechaConsulta, motivo);
            cout << "Consulta de emergencia registrada exitosamente.\n";
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } else {
        cout << "Ingrese la fecha de la reserva (dd mm aaaa): ";
        cin >> diaReserva >> mesReserva >> anoReserva;
        Fecha* fechaReserva = new Fecha(diaReserva, mesReserva, anoReserva);
        cout << "El paciente asistió a la consulta? (s/n): ";
        cin >> respuestaAsistio;
        asistio = (respuestaAsistio == 's' || respuestaAsistio == 'S');

        try {
            consultaCtrl->ingresarDatosConsultaComun(ciMedico, ciPaciente, fechaConsulta, fechaReserva, asistio);
            cout << "Consulta común registrada exitosamente.\n";
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}