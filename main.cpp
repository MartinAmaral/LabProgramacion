// Programacion Avanzada - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Laboratorio 5
// main.cpp

#include <iostream>
#include "menus/menuSesion.h"
#include "menus/menuConsulta.h"
#include "menus/menuAgregarDatos.h"
using namespace std;

int main (){
	int option=-1;

    MenuSesion* menuSesion = new MenuSesion();
	MenuConsulta* menuConsulta = new MenuConsulta();
    MenuAgregarDatos* menuDatos = new MenuAgregarDatos();
	
    while(option !=6){
		cout << "0: Cargar Datos de Prueba\n1: Iniciar Sesion \n";
		cout << "2: Cerrar Sesion \n3: Alta/Reactivacion de Usuario\n";
        cout << "4: Registrar Consulta\n";
		cout << "5: Alta diagnosticos de una consulta.\n";
        cout << "6: Salir\n";
		cin >> option;

		if(cin.fail() || option >6 || option<0){
		    cin.clear();
		    cin.ignore(100,'\n');
		    cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
            continue;
		}
	    switch (option){
	        case 0:
                menuDatos->AgregarDatos();
		        break;
    	    case 1:
                menuSesion->iniciarSesion();
    		break;
    	    case 2:
                menuSesion->cerrarSesion();
    		    break;
	        case 3:
                menuSesion->altaUsuario();
        		break;
        	case 4:
                menuConsulta->registrarConsulta();
	        	break;
        	case 5:
                menuConsulta->altaDiagnostico();
	        	break;
        	default:
	        	break;
	    }
	}
	std::cout << "Chau\n";
	return 0;
}
