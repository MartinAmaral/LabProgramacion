
using namespace std;

cout << "Registrar una nueva consulta \n\r"
while(option !=4){
		std::cout << "1: Consulta de Emergencia \n";
		std::cout << "2: Consulta Comun \n";
		std::cout << "3: Volver\n";


		std::cin >> option;

		if(std::cin.fail() || option >4 || option<0){
		    std::cin.clear();
		    std::cin.ignore(100,'\n');
		    std::cout << "\nOpcion invalida, intentelo de nuevo.\n\n";
            continue;
		}
	    switch (option){
	        case 1:
		        break;
    	    case 2:
    		    break;
    	    case 3:
    		    break;
	    }
	}

void IngresarCI(){
    std::cout << "Ingrese CI del medico"
    std::cin >> Cimed;
    std::cout << "Ingrese CI del paciente"
    std::cin >> Cipas;
}