#include <iostream>
#include <string>
#include "../controllers/CConsulta.h"

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
    Fecha fechaConsulta(ano, mes, dia); // Asumiendo que el orden es año, mes, día

    if (esEmergencia) {
        cin.ignore(); // Limpiar el buffer después de leer el char
        cout << "Ingrese el motivo de la consulta: ";
        getline(cin, motivo);
        consultaCtrl->ingresarDatosConsultaEmergencia(new Socio("", "", Sexo::Masculino, stoi(ciMedico), nullptr, TipoUsuario::Socio), new Socio("", "", Sexo::Masculino, stoi(ciPaciente), nullptr, TipoUsuario::Socio), fechaConsulta, motivo);
    } else {
        cout << "Ingrese la fecha de reserva (dd mm aaaa): ";
        cin >> diaReserva >> mesReserva >> anoReserva;
        Fecha fechaReserva(anoReserva, mesReserva, diaReserva);
        cout << "El paciente asistió a la consulta? (s/n): ";
        cin >> respuestaAsistio;
        asistio = (respuestaAsistio == 's' || respuestaAsistio == 'S');
        consultaCtrl->ingresarDatosConsultaComun(new Socio("", "", Sexo::Masculino, stoi(ciMedico), nullptr, TipoUsuario::Socio), new Socio("", "", Sexo::Masculino, stoi(ciPaciente), nullptr, TipoUsuario::Socio), fechaConsulta, &fechaReserva, asistio);
    }
    cout << "Consulta registrada exitosamente!" << endl;
}

void altaDiagnostico() {
    CConsulta* consultaManager = CConsulta::getInstanceConsulta();

    string ciMedico;
    cout << "Ingrese su CI (Médico): ";
    cin >> ciMedico;

    Fecha fechaActual(18, 6, 2024); // Se puede obtener dinámicamente

    map<string, shared_ptr<Consulta>> consultas = consultaManager->obtenerConsultasDelDia(ciMedico, fechaActual);
    cout << "Consultas para hoy:" << endl;
    for (const auto& entry : consultas) {
        cout << "CI Paciente: " << entry.first << endl;
    }

    string ciPaciente;
    cout << "Seleccione la consulta ingresando la CI del Paciente: ";
    cin >> ciPaciente;

    Diagnostico* nuevoDiagnostico = nullptr;
    vector<Tratamiento*> tratamientos; // Usar vector de punteros a Tratamiento

    while (true) {
        string categoriaSeleccionada;
        cout << "Seleccione una categoría de diagnóstico: ";
        cin >> categoriaSeleccionada;

        // Simulación de selección de diagnóstico basado en la categoría
        string codigoDiagnostico, descripcionDiagnostico;
        cout << "Ingrese el código del diagnóstico seleccionado: ";
        cin >> codigoDiagnostico;
        cout << "Ingrese la descripción del diagnóstico: ";
        cin.ignore();
        getline(cin, descripcionDiagnostico);

        RepresentacionE* representacion = new RepresentacionE(codigoDiagnostico, descripcionDiagnostico);
        string descripcionLibre;
        cout << "Ingrese una descripción complementaria: ";
        getline(cin, descripcionLibre);

        nuevoDiagnostico = new Diagnostico(representacion, descripcionLibre);

        string agregarMas;
        cout << "¿Desea agregar tratamientos a este diagnóstico? (s/n): ";
        cin >> agregarMas;

        if (agregarMas == "s" || agregarMas == "S") {
            string descripcionTratamiento, nombreMedicamento;
            cout << "Ingrese la descripción del tratamiento: ";
            getline(cin, descripcionTratamiento);

            cout << "Ingrese el nombre del medicamento: ";
            getline(cin, nombreMedicamento);

            Tratamiento* tratamiento = new Farmaco(descripcionTratamiento, nombreMedicamento);
            tratamientos.push_back(tratamiento); // Agregar tratamiento al vector

            cout << "Tratamiento agregado exitosamente." << endl;
        }

        cout << "¿Desea agregar otro diagnóstico? (s/n): ";
        cin >> agregarMas;

        if (agregarMas == "n" || agregarMas == "N") {
            break;
        }
    }

    consultaManager->darAltaDiagnostico(ciMedico, ciPaciente, fechaActual, nuevoDiagnostico, tratamientos);
    cout << "Diagnósticos registrados exitosamente." << endl;
}

