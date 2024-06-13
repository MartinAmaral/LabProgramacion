// Programacion Avanzada - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Laboratorio 5
// main.cpp

#include "entidades/usuario.h"
#include <string.h>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

bool contrasenaValida(string contra){
    
    if(contra.length() <5 || contra.length() >9 )
        return false;
    for (char ch : contra) {
        if (!std::isalpha(ch) && !std::isdigit(ch)) {
            return false;
        }
    }
    return true;
}

void iniciarSesion(){

    int cedulaAdminDefecto = 26;
    string contrasenaAdmin = "pepon";
    int cedula = -33;
    Usuario* usuarioIngresando = NULL;

    cout << "Ingrese su cedula (solo numero) o -1 para cancelar:\n";
    
    do {
        cin >> cedula; 
	    if(cin.fail() || cedula<0){
		    if (cedula == -1) return;
            cin.clear(); 
	        cout << "\nCedula invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        cedula = -33;
        }

        //else if(!existe){ nos fijamos si hay un usuario con esa cedula
        //  std::cout << "\nLa cedula ingresada no existe en el sistema, intentelo de nuevo.\n\n";
        //  cedula = -33;
        //}
        //else { // conseguimos el usario con esa cedula
        //  usuarioIngresando = getUsaron(cedula);  
        //}
    }while(cedula == -33);

    if (cedulaAdminDefecto == cedula){ // es el usuario adminstrativo
            
        string contra = "";
   
        cout << "\nBienvenido/a Admin. Ingrese su contrasena: ";
	    
        do{
            std::cin >> contra; 
	        if(contra == "salir") return;
	        std::cout << "\nContrasena invalida, intentelo de nuevo o escriba salir para salir.\n\n";
        }while(contra != contrasenaAdmin );
        
        // asignar la sesion al administrativo
        cout<< "\nSesion Admin default iniciada \n";
        return;
    }
    else{ // if (usuarioIngresando->getContrasena() == "") { //verificamos 
	    string nuevaContra = "";
        std::cout << "\nIngrese su contrasena para ser guardada por el sistema. \n";
	    std::cout << "\nLa contrasena debe ser de entre 6 y 9 caracteres largo y caracteres alfanumericos.\n";
        
        while (!contrasenaValida(nuevaContra)) {
            cin >> nuevaContra;
            if(nuevaContra == "salir"){
                return;
            }
            cout << "Ingrese una contrasena valida o escriba 'salir' para salir\n";
        }
        cout <<"contrasena valida!\n";
    }
    
    
}


int main (){
	int option=-1;

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
                iniciarSesion();
    		break;
    	    case 2:
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
