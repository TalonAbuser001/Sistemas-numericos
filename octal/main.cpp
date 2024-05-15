#include "octal.h"

int main(){
    // Crea un objeto de la clase octal con el valor decimal 
    octal n1(79);
    octal n2(36965);
    octal n3; // Crea un objeto de la clase octal sin inicializar

    // Imprime los valores
    cout << "\nn1 es " << n1;
    cout << "\nn2 es " << n2;
    cout << "\nn3 es " << n3;

    //Suma de valores
    n3 = n1 + n2;
    cout << "\n\n" << n1 << " + " << n2 << " = " << n3;

    cout << "\n\n";

    return 0;
}
