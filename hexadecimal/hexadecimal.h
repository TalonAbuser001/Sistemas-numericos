#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include <iostream>
using namespace std;

/**
 * @class hexadecimal
 * Representa un número hexadecimal.
 *
 * La clase `hexadecimal` proporciona funcionalidad para trabajar con números hexadecimales.
 * Admite la suma de dos números hexadecimales y proporciona un operador de salida
 * para imprimir el número hexadecimal en un flujo de salida.
 */
class hexadecimal
{
public:
    friend ostream &operator<<(ostream &, const hexadecimal &);
public:
    /**
     * Construye un objeto `hexadecimal` con el valor dado.
     * @param value El valor inicial del número hexadecimal. El valor predeterminado es 0.
     */
    hexadecimal(long = 0);

    /**
     * Suma dos números hexadecimales.
     * @param other El otro número hexadecimal a sumar.
     * @return El resultado de la suma como un nuevo objeto `hexadecimal`.
     */
    hexadecimal operator+(const hexadecimal &) const;

private:
    char hexa[100]; /**< El número hexadecimal representado como un arreglo de caracteres. */
};

#endif // HEXADECIMAL_H