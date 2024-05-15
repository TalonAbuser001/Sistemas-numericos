#include "octal.h"

/*constructor predeterminado; convierte un entero decimal en un objeto octal*/
octal::octal(long valor){
    // Inicializa el arreglo 'oct' con ceros
    for(int i = 0; i <= 49; i++)
        oct[i] = 0;

    /*coloca los digitos del argumento dentro del arreglo*/
    for(int j = 49; valor != 0 && j >= 0; j--){
        oct[j] = valor % 8; // Obtiene el último dígito en base 8
        valor /= 8; // Reduce el valor dividiéndolo entre 8
    }
}

/* Sobrecarga del operador '+' para sumar dos números octales */
octal octal::operator+(const octal &op2) const{
    octal temp;
    int acarreo = 0;
    // Suma los dígitos de los dos números octales desde el final
    for(int i = 49; i >= 0; i--){
        temp.oct[i] = oct[i] + op2.oct[i] + acarreo;
        if(temp.oct[i] > 1){
            temp.oct[i] %= 8; // Reduce el dígito a un valor entre 0 y 7
            acarreo = 1; // Si el dígito es mayor que 7, lleva 1 al siguiente dígito
        }
        else
            acarreo = 0; // Si no, no hay acarreo
    }
    return temp;
}

/*operador de salida sobrecargado*/
ostream& operator<<(ostream &salida, const octal &num){
    int i;
    for(i = 0; (num.oct[i] == 0) && (i <= 49); i++);
    /*ignora ceros a la izquierda*/
    if(i == 50)
        salida << 0;
    else
        // Imprime los dígitos del número octal
        for( ; i <= 49; i++)
            salida << num.oct[i];
    return salida;
}
