
#include <cstddef>
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
        cout << "La Sesion ha sido cerrdada con exito.\n";
    }
}


