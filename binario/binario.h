#ifndef BINARIO_H
#define BINARIO_H

#include <iostream>
using namespace std;

class binario{
    friend ostream &operator<<(ostream &, const binario &);
public:
    // Constructor predeterminado que puede aceptar un valor predeterminado.
    binario(long = 0);
    // Sobrecarga del operador '+' para sumar dos objetos binarios.
    binario operator+(const binario &) const;
private:
    // Arreglo utilizado para almacenar los dígitos binarios.
    short bin[40];
};

#endif // BINARIO_H
