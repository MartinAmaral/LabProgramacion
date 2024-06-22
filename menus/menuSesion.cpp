#include <iostream>
#include <string>
#include <limits>
#include "menuSesion.h"
#include "../Interfaces/ICUsuarioYSesion.h"

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

ICUsuarioYSesion* controllerSesion;

void MenuSesion::iniciarSesion(){
    int cedula = -33;
    cout << "Ingrese su cedula (solo numero) o -1 para cancelar:\n";
    do {
        cin >> cedula; 
	    if(cin.fail() || cedula<0){
		    if (cedula == -1){
                return;
            }
            cin.clear(); 
	        cout << "\nCedula invalida, intentelo de nuevo.\n\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        cedula = -33;
        } 
        else if(!controllerSesion->existeUsuario(cedula)){ 
            std::cout << "\nLa cedula ingresada no existe en el sistema, intentelo de nuevo.\n\n";
            cedula = -33;
        } 
        else{
            controllerSesion->recordarCiIS(cedula);
        }
    }while(cedula == -33);

    if (controllerSesion->esAdminDefecto()){
        string contra = "";
   
        cout << "\nBienvenido/a Admin. Ingrese su contrasena: ";
        std::cin >> contra; 
        if(contra == "salir") return;

        while(controllerSesion->ingresarPassIS(contra)){
            std::cout << "\nContrasena invalida, intentelo de nuevo o escriba salir para salir.\n\n";
            std::cin >> contra; 
	        if(contra == "salir") return;
        }
        controllerSesion->asignarSesion();
        cout<< "\nSesion Admin Default iniciada \n";
        return;
    }
    else if (controllerSesion->usuarioSinContrasena()) {
	    string nuevaContra = "";
        std::cout << "\nUsuario sin contrasena. Ingrese su contrasena para ser guardada por el sistema. \n";
	    std::cout << "\nLa contrasena debe ser de entre 6 y 9 caracteres largo y caracteres alfanumericos.\n";
	    std::cout << "\nEscriba salir para volver al menu principal.\n";
        
        cin >> nuevaContra;
        while (!contrasenaValida(nuevaContra)) {
            if(nuevaContra == "salir"){
                return;
            }
            cout << "Ingrese una contrasena valida o escriba 'salir' para salir\n";
            cin >> nuevaContra;
        }
        controllerSesion->asignarContrasena(nuevaContra);
        controllerSesion->asignarSesion();
        cout <<"\nLa Sesion ha sido asginada con exito.Bienvenido\n";
    }
    else{
        string contra = "";
        
        cout << "\nIngrese su contrasena o 'salir' para salir:\n";
        cin >> contra; 
        while (!contrasenaValida(contra)) { 
            if(contra == "salir"){
                return;
            }
            cout << "\nIngrese una contrasena valida o escriba 'salir' para salir\n";
            cin >> contra; 
        }
        
        if (!controllerSesion->esActivoIS()){
            cout << "\nUsuario inactivo, no se puede realizar el inicio de sesión\n";
            return;
        }
        controllerSesion->asignarSesion();
        cout <<"\nLa Sesion ha sido asginada con exito.Bienvenido\n";
    }
}

void MenuSesion::cerrarSesion(){
    if (controllerSesion->getUsuarioActivo() == NULL){
        cout << "No hay ninguna sesion iniciada.!\n";
    }
    else{
        controllerSesion->cerrarSesion();
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


