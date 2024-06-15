// Programacion Avanzada - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Laboratorio 5
// main.cpp

#include <iostream>
#include "menus/menuSesion.h"

using namespace std;

MenuSesion* menuSesion = NULL;


int main (){
	int option=-1;

    menuSesion = new MenuSesion();

	while(option !=15){
		std::cout << "0: Cargar Datos de Prueba\n1: Iniciar Sesion \n";
		std::cout << "2: Cerrar Sesion \n3: Alta/Reactivacion de Usuario\n";
		std::cout << "4: Usuarios dados de alta y reactivados \n5: Alta medicamento\n";
		std::cout << "6: Alta de representacion estarandizada de diagnosticos \n7: Listar representaciones estarandizadas\n";
        std::cout << "8: Reserva consulta \n9: Devolucion de reserva\n";
		std::cout << "10: Registro de consulta \n11: Alta diagnosticos de una consulta \n";
		std::cout << "12: Obtener historial paciente \n13: Cantidad de consultas por categoria de diagnosticos\n";
		std::cout << "14: Estado de situacion de un socio\n15: Salir\n";

		std::cin >> option;

		if(std::cin.fail() || option >15 || option<0){
		    std::cin.clear();
		    std::cin.ignore(100,'\n');
		    std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
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
	        	break;
        	case 9:
	        	break;
        	case 10:
	        	break;
        	case 11:
	        	break;
        	case 12:
	        	break;
        	case 13:
	        	break;
        	case 14:
	        	break;
        	case 15:
	        	break;
        	default:
	        	break;
	    }
	}
	std::cout << "Chau\n";
	return 0;
}
