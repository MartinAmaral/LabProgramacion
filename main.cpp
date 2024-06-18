// Programacion Avanzada - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Laboratorio 5
// main.cpp

#include <iostream>
#include "menus/menuSesion.h"
#include "menus/menuConsulta.h"
using namespace std;

int main (){
	int option=-1;

    MenuSesion* menuSesion = new MenuSesion();
	MenuConsulta* menuConsulta = new MenuConsulta()

	while(option !=8){
		cout << "0: Cargar Datos de Prueba\n1: Iniciar Sesion \n";
		cout << "2: Cerrar Sesion \n3: Alta/Reactivacion de Usuario\n";
		cout << "4: Usuarios dados de alta y reactivados \n5: Alta medicamento\n";
		cout << "6: Alta de representacion estarandizada de diagnosticos \n7: Listar representaciones estarandizadas\n";
        cout << "8: Registrar Consulta\n";
		cout << "9: Alta diagnosticos de una consulta.\n";
        cout << "10: Salir\n";
		cin >> option;

		if(cin.fail() || option >8 || option<0){
		    cin.clear();
		    cin.ignore(100,'\n');
		    cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
            continue;
		}
	    switch (option){
	        case 0:
		        break;
    	    case 1:
                menuSesion->iniciarSesion();
    		break;
    	    case 2:
                menuSesion->cerrarSesion();
    		    break;
	        case 3:
        		break;
        	case 4:
	        	break;
        	case 5:
	        	break;
        	case 6:
	        	break;
        	case 7:
        		break;
			case 8:
				menuConsulta->registrarConsulta();
        		break;
			case 9:
        		break;
        	default:
	        	break;
	    }
	}
	std::cout << "Chau\n";
	return 0;
}
