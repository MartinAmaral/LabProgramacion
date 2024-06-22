#include <iostream>
#include <string>
#include <limits>
#include "menuSesion.h"
#include "../Interfaces/ICUsuarioYSesion.h"
#include "../fabricas/fabricaCUsuario.h"
#include "../dts/infoUsuarioDT.h"

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


void MenuSesion::iniciarSesion(){
    if (controllerSesion == NULL)
        controllerSesion = FabricaCUsuario::getCUsuario(); 

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
        controllerSesion->asignarSesionDefecto();
        cout<< "\nSesion Admin Default iniciada \n";
        return;
    }
    else if (controllerSesion->usuarioSinContrasena()) { //primera vez que entra al sistema
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
    if (controllerSesion == NULL)
        controllerSesion = FabricaCUsuario::getCUsuario(); 

    if (controllerSesion->getUsuarioActivo() == NULL){
        cout << "No hay ninguna sesion iniciada.!\n";
    }
    else{
        controllerSesion->cerrarSesion();
        cout << "La Sesion ha sido cerrada con exito.\n";
    }
}

void MenuSesion::altaUsuario(){
    if (controllerSesion == NULL)
        controllerSesion = FabricaCUsuario::getCUsuario(); 

    if (controllerSesion->getTipoUsuarioActivo() == Admin || controllerSesion->getTipoUsuarioActivo() == SocioAdmin ){
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
            cedula = -33;
        }
        cedula = -33;
    }while(cedula == -33);
}

void MenuSesion::darAlta(int cedula){ // hice esto por la indentacion de mierda

    if ( controllerSesion->existeUsuario(cedula)){ // nos fijamos si existe la ceula y reactivamos el Usuario 
       
        InfoUsuarioDT* info = controllerSesion->devolverInfo(cedula);
        
        cout << "Nombre: " << info->getNombre() << " Apellido: " << info->getApellido() << "\n";

        cout << "Sexo: " << info->getSexo() << " Edad: " << (2024 - info->getFechaNacimiento()->getAno()) << "\n";

        if(controllerSesion->esActivo(cedula)){
            cout << "El usuario se encuentra activo\n";
        }
        else cout << "El usuario se encuentra inactivo\n";

        if(controllerSesion->esActivo(cedula)){
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
                controllerSesion->reactivarUsuario(cedula);
                cout << "El usuario con cedula: " << cedula << "ha sido reactivado\n";
            }
        return;
        }
    }
    else { //ingresar los datos del usuario con un di
        cout << "Ingrese los datos del usuario a dar de alta\n";

        string nombre;
        cout << "\nIngrese el nombre: ";
        cin >> nombre;
        
        string apellido;
        cout << "\nIngrese el apellido: ";
        cin >> apellido;

        int sexoN = -1;
        do{
            cout<< "\nIngrese 1 para Masculino o 0 para Femenino \n";
            cin >> sexoN; 
            if(cin.fail() || sexoN<0 || sexoN >1){
                cin.clear(); 
	            cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                sexoN = -1;
            }
        }while(sexoN<0);

        Sexo sexo; 
        if(sexoN ==1)
            sexo = Masculino;
        else sexo = Femenino;
        
        int tipoN = -1;
        do{
            cout<< "\nIngrese 0 para cancelar la alta de usuario\n";
            cout <<"Ingrese 1 para socio, 2 para medico, 3 para admin, 4 para socio-medico, 5 para socio-admin:\n";
            cin >> tipoN; 
            if(cin.fail() || tipoN<0 || tipoN >5){
                if (tipoN == 0) return;
                cin.clear(); 
	            cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                tipoN = -1;
            }
        }while(tipoN<0);
        
        // Falta la fecha
        Fecha* fecha;

        // 
        TipoUsuario tipo;

        if(tipoN == 1)
            tipo = Socio;
        else if (tipoN == 2)
            tipo = Medico;
        else if (tipoN == 3)
            tipo = Admin;
        else if (tipoN ==4)
            tipo = SocioMedico;
        else if (tipoN ==5)
            tipo = SocioAdmin;

        InfoUsuarioDT* infoDt = new InfoUsuarioDT(nombre,apellido,sexo,fecha,tipo);
        controllerSesion->altaUsuario(infoDt);    

        cout <<"\nUsuario dado de alta existosamente!\n";
    }
    
    cout << "El usuario con esa cedula no existe ingrese los datos para ingrearlo en el sistema\n";
    cout << "Ingrese -1 en cualquier momento para cancelar.\n";
    
}

