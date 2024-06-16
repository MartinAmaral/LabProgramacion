
#include <cstddef>
#include <iostream>
#include <string>
#include "../entidades/usuario.h"
#include <limits>
#include "menuSesion.h"
#include "../controllers/CUsuarioYSesion.h"


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


CUsuarioYSesion* controller = NULL;

void MenuSesion::iniciarSesion(){

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

void MenuSesion::cerrarSesion(){
    if (controller->getUsuarioActivo() == NULL){
        cout << "No hay ninguna sesion iniciada.!\n";
    }
    else{
        controller->cerrarSesion();
        cout << "La Sesion ha sido cerrada con exito.\n";
    }
}

void darAlta(int cedula){ // hice esto por la indentacion de mierda

    

    if (true){ // nos fijamos si exite la ceula y reactivamos el Usuario 
       
        // devolver todos los datos del usario en un dt

        cout << "Quiere reactivar a este Usuario?\n";
        int valor =-1;
        do{
            cout<< "Ingresa 1 para reactivar el usuario y 0 para no \n";
            cin >> valor; 
            if(cin.fail() || valor<0 || valor >1){
                cin.clear(); 
	            cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }while(valor<0);
        if(valor == 1){
            //reactivar al usuario
            cout << "El usuario con cedula: " << cedula << "ha sido reactivado\n";
        }
        return;
    }
    
    cout << "El usuario con esa cedula no existe ingrese los datos para ingrearlo en el sistema\n";
    cout << "Ingrese -1 en cualquier momento para cancelar.\n";
    
    string inputTexto;
    

        

}

void MenuSesion::altaUsuario(){

    if (false){
        // fijarnos si el usuario logeado es un Usario Administrativo
        cout<< "Se necesita a un Usuario administrativo para dar de alta o Reactivar a un usuario.\n";
        return;
    }

    int cedula = -33;
	do{
        cout << "Ingrese la cedula a dar de alta o reactivar o ingrese -1 para salir.\n";
        cin >> cedula; 

        if(cin.fail() || cedula<0){
	        if (!cin.fail() && cedula == -1) return;
            cin.clear(); 
	        cout << "\nCedula invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            darAlta(cedula);
        }
        cedula = -33;
    }while(cedula == -33);
}


