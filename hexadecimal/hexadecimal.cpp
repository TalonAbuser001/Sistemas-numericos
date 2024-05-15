#include "hexadecimal.h"

/*constructor predeterminado*/
/**
 * Constructor de la clase hexadecimal.
 * Convierte un valor decimal a su representación hexadecimal.
 *
 * @param valor El valor decimal a ser convertido.
 */
hexadecimal::hexadecimal(long valor)
{
  int i, temp = 0;
  for(i = 0; i < 100; i++) hexa[i] = '0';
  i = 99;
  while(valor > 0) {
    temp = valor % 16;
    if(temp < 10) {
      hexa[i] = temp + 48;
      i--;
    }
    else {
      hexa[i] = temp + 55;
      i--;
    }
    valor = valor / 16;
  }
}

/**
 * Suma dos números hexadecimales.
 *
 * Esta función sobrecarga el operador '+' para sumar dos números hexadecimales.
 * Realiza la suma dígito a dígito, teniendo en cuenta cualquier acarreo.
 *
 * @param op2 El número hexadecimal que se va a sumar.
 * @return La suma de los dos números hexadecimales.
 */
hexadecimal hexadecimal::operator+(const hexadecimal &op2) const {
    hexadecimal temp;
    int sum = 0;
    int acarreo = 0;

    for (int i = 99; i >= 0; i--) {
        int digit1 = (hexa[i] >= '0' && hexa[i] <= '9') ? hexa[i] - '0' : hexa[i] - 'A' + 10;
        int digit2 = (op2.hexa[i] >= '0' && op2.hexa[i] <= '9') ? op2.hexa[i] - '0' : op2.hexa[i] - 'A' + 10;
        sum = digit1 + digit2 + acarreo;

        if (sum >= 16) {
            acarreo = sum / 16;
            sum = sum % 16;
        } else {
            acarreo = 0;
        }

        if (sum < 10) {
            temp.hexa[i] = sum + '0';
        } else {
            temp.hexa[i] = sum - 10 + 'A';
        }
    }

    return temp;
}


/*operador de salida sobrecargado*/
/**
 * Operador de inserción sobrecargado para la clase hexadecimal.
 * Imprime el número hexadecimal en el flujo de salida.
 *
 * @param salida El flujo de salida donde se imprimirá el número hexadecimal.
 * @param num El número hexadecimal que se imprimirá.
 * @return El flujo de salida después de imprimir el número hexadecimal.
 */
ostream& operator<<(ostream &salida, const hexadecimal &num)
{
    int i;
    for(i = 0; (num.hexa[i] == '0') && (i < 100); i++);
    /*ignora ceros a la izquierda*/
    if(i == 99)
        salida << 0;
    else
        for( ; i < 100; i++)
            salida << num.hexa[i];
    return salida;
}
