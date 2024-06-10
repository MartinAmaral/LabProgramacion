#include <string>
#include "../entidades/usuario.h"
// Este controllador se encarga de los siguientes casos de uso:
// Alta medicamento
// Alta de representación estandarizada de diagnósticos
// Listar representaciones estandarizadas


class CDiagnostico {
    private:
    
        
    public:
        //Alta medicamento
        void AltaMedicamento(string nombre);
        void CancelarAltaMedicamento();

        //Alta de representación estandarizada de diagnósticos
        void DevolverAltaRepresentacion();

        //Listar representaciones estandarizadas, agregar y seleccionar
        void ListarCategoriaD();
        void SeleccionarCategordiaD();
        void AgregarCategoriaD(string categoriaD);

        
        
 
        //Cerrar Sesion
        void cerrarSesion();

        // Alta/Reactivación de Usuario

        // Usuarios dados de alta y reactivados
};
