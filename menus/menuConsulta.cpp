#include "menuConsulta.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "../fabricas/fabricaCUsuario.h"
#include "../fabricas/fabricaCConsulta.h"
#include "../Interfaces/ICConsulta.h"
#include "../Interfaces/ICUsuarioYSesion.h"

using namespace std;

void MenuConsulta::registrarConsulta() {

    if(!FabricaCUsuario::getCUsuario()->getUsuarioActivo()){
        cout << "No se ha iniciado ninguna sesion.\n";
        return;
    }

    TipoUsuario tipoUsuario =FabricaCUsuario::getCUsuario()->getTipoUsuarioActivo();
    
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
        getline(cin,motivo);
        consultaController->altaConsultaEmergencia(cedulaMedico, cedulaPaciente, fechaConsulta, motivo);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "Consulta registrada exitosamente!" << endl;
}

void MenuConsulta::altaDiagnostico() {
    ICConsulta* consultaController = FabricaCConsulta::getCConsulta();
    
    if(!FabricaCUsuario::getCUsuario()->getUsuarioActivo()){
        cout << "No se ha iniciado ninguna sesion.\n";
        return;
    }

    TipoUsuario tipoUsuario =FabricaCUsuario::getCUsuario()->getTipoUsuarioActivo();

    bool ok = true; //cambiar a false
    if( tipoUsuario == Medico || tipoUsuario == SocioMedico) 
        ok = true;
    if(!ok){
        cout << "El usuario logeado necesita ser Medico\n";
        return;
    }
    
    Fecha* fechaConsultar;
    int dia = -1;
    do{
        cout<< "\nIngrese el dia de las Consultas a seleccionar: \n";
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
        cout<< "\nIngrese el mes de las Consultas a seleccionar: \n";
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
        cout<< "\nIngrese el ano de las Consultas a seleccionar: \n";
        cin >> ano; 
        if(cin.fail() || ano<0 || ano >2024){
           cin.clear(); 
           cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ano = -1;
        }
    }while(ano<0);

    fechaConsultar = new Fecha(ano, mes, dia);

    vector<ConsultaDia*> consultasDia = consultaController->devolverConsultasDia(fechaConsultar);        

    if(consultasDia.empty()){
        cout <<"No hay consultas para el dia selecionado\n";
        return;
    }

    cout <<"Consultas del dia cedula del paciente:\n";
    for(ConsultaDia* x : consultasDia){
        cout << "CI: "<< x->getCiPaciente() << "\n"; 
    }

    cout <<"Selecciones la ci de la consulta a Agregar(de la lista mostrada anteriormente):\n";
    cout <<"Ingrese -1 para cancelar.\n";
    
    int cedulaElegida = -33;
    bool encontro = false;
	do{
        cin >> cedulaElegida; 

        if(cin.fail() || cedulaElegida<0){
            cin.clear(); 
	        cout << "\nCedula invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cedulaElegida = -33;
        }
        for(ConsultaDia* x : consultasDia){
            if(x->getCiPaciente() == cedulaElegida){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                consultaController->elegirConsultaAgregarDiag(x->getConsulta());
                encontro = true;
                break;
            }
        }
        if (encontro) break;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Esa cedula no se encuetra en las listadas anteriormente\n";
        cedulaElegida = -33;
    }while(cedulaElegida == -33);
    
    for (auto& ptr : consultasDia ) {
        delete ptr;
    }
    consultasDia.clear();
    
    int valor =-1;
    do{
        cout<< "Ingrese 1 si quiere agregar un Diagnóstico a la consulta o 0 sino \n";
        cin >> valor; 
        if(cin.fail() || valor<0 || valor >1){
            cin.clear(); 
	        cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            valor=-1;
        }
        else if (valor == 1){
            
            DatosDiagnostico* datos = consultaController->devolverDatosDiagnostico(); 

            cout << "Categorias:\n1: A Afecciones Pulmonares\n2: B Aparato Digestivo\n";

            int cat =-1;
            do{
                cin >> cat; 
                if(cin.fail() || cat<1 || cat >2){
                    cin.clear(); 
	                cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cat=-1;
                }
            }while(cat<0);
           
            int repN = -1;
            string rep = "";
            if(cat ==1){

                cout << "Representacion:\n 1: A01 Asma \n 2: A02 Congestion\n";
                int repN =-1;
                do{
                    cin >> repN; 
                    if(cin.fail() || repN<1 || repN >2){
                        cin.clear(); 
	                    cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        repN=-1;
                    }
                }while(repN<0);
                if(repN ==1)
                    rep = "A01";
                else rep = "A02";
            }
            else {
                
                cout <<"Solo hay B01 Nauseas y ha sido elegido automaticamente\n";
                rep = "B01";
            }

            string descp ="";
            int v =-1;
            do{
                cout<< "Ingrese 1 si quere agregas una descripcion a la consulta o 0 sino \n";
                cin >> v; 
                if(cin.fail() || v<0 || v >1){
                    cin.clear(); 
	                cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    v=-1;
                }
                if(v ==1 ){
                    cout <<"Ingrese la descripcion\n";
                    getline(cin,descp);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }while(v!=0);
            consultaController->agregarDiagnosticoConsulta(rep,descp);
            cout << "Diagnósticos registrado exitosamente." << endl;
        }
    }while(valor!=0);
}

