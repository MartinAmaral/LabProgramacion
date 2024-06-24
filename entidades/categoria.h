#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>
using namespace std;

class Categoria{
    private:
        string codigo;
        string categoria;

    public:
        Categoria(string codigo, string categoria);
        ~Categoria();
};


#endif
