#include "hexadecimal.h"
#include "hexadecimal.cpp"

int main()
{
    // Crear tres objetos hexadecimal
    hexadecimal n1(7654321);
    hexadecimal n2(7891234);
    hexadecimal n3(1234);

    // Imprimir los valores de los objetos
    cout << "\nn1 es " << n1;
    cout << "\nn2 es " << n2;
    cout << "\nn3 es " << n3;

    // Sumar dos objetos y asignar el resultado a un tercer objeto
    n3 = n1 + n2;
    cout << "\n\n" << n1 << " + " << n2 << " = " << n3;

    cout<<"\n\n";

    return 0;
}