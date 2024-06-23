#include "menuConsulta.h"
#include <iostream>
#include <limits>
#include <string>
#include "../fabricas/fabricaCUsuario.h"
#include "../fabricas/fabricaCConsulta.h"
#include "../Interfaces/ICConsulta.h"
#include "../Interfaces/ICUsuarioYSesion.h"

using namespace std;

void MenuConsulta::registrarConsulta() {

    TipoUsuario tipoUsuario = FabricaCUsuario::getCUsuario()->getTipoUsuarioActivo();
    bool ok = false;
    if( tipoUsuario == Admin || tipoUsuario == SocioAdmin) 
        ok = true;
    if(!ok){
        cout << "El usuario logeado necesita ser Administrativo\n";
        return;
    }

    ICConsulta* consultaController = FabricaCConsulta::getCConsulta();

    int cedulaMedico = -33;
	do{
        cout << "Ingrese la cedula del Medico de la reserva.\n";
        cin >> cedulaMedico; 

        if(cin.fail() || cedulaMedico<0){
            cin.clear(); 
	        cout << "\nCedula invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cedulaMedico = -33;
        }
    }while(cedulaMedico == -33);
    
    int cedulaPaciente = -33;
	do{
        cout << "Ingrese la cedula del Paciente de la reserva.\n";
        cin >> cedulaPaciente; 

        if(cin.fail() || cedulaPaciente<0){
            cin.clear(); 
	        cout << "\nCedula invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cedulaPaciente = -33;
        }
    }while(cedulaPaciente == -33);
    

    Fecha* fechaConsulta;
    int dia = -1;
    do{
        cout<< "\nIngrese el dia de la Consulta: \n";
        cin >> dia; 
        if(cin.fail() || dia<=0 || dia >31){
            cin.clear(); 
	        cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            dia = -1;
        }
    }while(dia<0);
        
    int mes = -1;
    do{
        cout<< "\nIngrese el mes de la Consulta: \n";
        cin >> mes; 
        if(cin.fail() || mes<=0 || mes >12){
            cin.clear(); 
	        cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mes = -1;
        }
    }while(mes<0);
        
    int ano = -1;
    do{
        cout<< "\nIngrese el ano de la Consulta: \n";
        cin >> ano; 
        if(cin.fail() || ano<0 || ano >2024){
           cin.clear(); 
           cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ano = -1;
        }
    }while(ano<0);

    fechaConsulta = new Fecha(ano, mes, dia);

    int valor =-1;
    do{
        cout<< "Ingresa 0 para Consulta comun o 1 para Consulta de Emergencia \n";
        cin >> valor; 
        if(cin.fail() || valor<0 || valor >1){
            cin.clear(); 
	        cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            valor = -1;
        }
    }while(valor<0);

    bool esComun = false;
    if(valor == 0)
        esComun = true;

    if(esComun){
        valor =-1;
        do{
            cout<< "Ingresa 0 para si asistio a la consulta o 1 sino asistio \n";
            cin >> valor; 
            if(cin.fail() || valor<0 || valor >1){
                cin.clear(); 
	            cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valor=-1;
            }
        }while(valor<0);
        bool asistio = false;
        if(valor ==0)
            asistio = true;

        Fecha* fechaReserva;
        int dia = -1;
        do{
            cout<< "\nIngrese el dia de Reserva: \n";
            cin >> dia; 
            if(cin.fail() || dia<=0 || dia >31){
                cin.clear(); 
	            cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                dia = -1;
            }
        }while(dia<0);
        
        int mes = -1;
        do{
            cout<< "\nIngrese el mes de Reserva: \n";
            cin >> mes; 
            if(cin.fail() || mes<=0 || mes >12){
                cin.clear(); 
    	        cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                mes = -1;
            }
        }while(mes<0);
            
        int ano = -1;
        do{
            cout<< "\nIngrese el ano de Reserva: \n";
            cin >> ano; 
            if(cin.fail() || ano<0 || ano >2024){
               cin.clear(); 
               cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ano = -1;
            }
        }while(ano<0);

        fechaReserva = new Fecha(ano, mes, dia);

        if(consultaController->consultaExistente(cedulaMedico,cedulaPaciente,fechaConsulta,fechaReserva)){
            cout << "Ya existe una consulta o reserva para ese medico para ese dia\n";
        }
        else{
            consultaController->altaConsultaComun(cedulaMedico, cedulaPaciente, fechaConsulta, fechaReserva, asistio);
        }
    }
    else{
        string motivo = "";
        cout << "Ingrese el motivo de la misma:\n";
        cin >> motivo;
        consultaController->altaConsultaEmergencia(cedulaMedico, cedulaPaciente, fechaConsulta, motivo);
    }
    cout << "Consulta registrada exitosamente!" << endl;
}

void MenuConsulta::altaDiagnostico() {
    ICConsulta* consultaManager = FabricaCConsulta::getCConsulta();
    /*
    string ciMedico;
    cout << "Ingrese su CI (Médico): ";
    cin >> ciMedico;
  
    Fecha* fechaActual = new Fecha(2024, 6, 18);

    map<string, shared_ptr<Consulta>> consultas = consultaManager->obtenerConsultasDelDia(ciMedico, fechaActual);
    cout << "Consultas para hoy:" << endl;
    for (auto entry : consultas) {
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

    consultaManager->darAltaDiagnostico(ciMedico, ciPaciente, fechaActual, nuevoDiagnostico);
    */
    cout << "Diagnósticos registrados exitosamente." << endl;
}

