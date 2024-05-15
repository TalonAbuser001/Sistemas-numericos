#include "binario.h"

/* Incluye el archivo de encabezado binario.h, que debe contener las declaraciones de la clase binario y otras funciones o clases relacionadas. */

/*constructor predeterminado; convierte un entero decimal en un objeto binario*/
binario::binario(long valor)
{
    for(int i = 0; i <= 39; i++)
        bin[i] = 0;
    /* Inicializa el arreglo bin[] con ceros */

    /*coloca los digitos del argumento dentro del arreglo*/
    for(int j = 39; valor != 0 && j >= 0; j--){
        bin[j] = valor % 2;
        valor /= 2;
    }
    /* Convierte el valor decimal en binario y lo guarda en el arreglo bin[]. */
}

binario binario::operator+(const binario &op2) const
{
    binario temp;
    int acarreo = 0;

    for(int i = 39; i >= 0; i--){
        temp.bin[i] = bin[i] + op2.bin[i] + acarreo;
        if(temp.bin[i] > 1){
            temp.bin[i] %= 2; //reduce a 0 - 1
            acarreo = 1;
        }
        else
            acarreo = 0;
    }
    return temp;
}
/* Sobrecarga del operador '+' para sumar dos números binarios. Devuelve un nuevo objeto binario que representa la suma de los dos operandos. */

/*operador de salida sobrecargado*/
ostream& operator<<(ostream &salida, const binario &num)
{
    int i;
    for(i = 0; (num.bin[i] == 0) && (i <= 39); i++);
    /* Encuentra el primer bit significativo (diferente de cero) */

    if(i == 40)
        salida << 0;
    else
        for( ; i <= 39; i++)
            salida << num.bin[i];
    /* Imprime el número binario sin ceros a la izquierda */
    return salida;
}
/* Sobrecarga del operador '<<' para imprimir un objeto binario en una secuencia de salida, como la consola. */