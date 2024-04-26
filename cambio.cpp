#include "cambio.h"

float cambio::a_peso(float dolar){    
    float total = dolar * VAL_DOLAR;
    return total;
}

float cambio::a_dolar(float peso){
    float total = peso / VAL_DOLAR;
    return total;
}





