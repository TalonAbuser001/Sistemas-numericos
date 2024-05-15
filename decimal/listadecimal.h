#ifndef LISTADECIMAL_H
#define LISTADECIMAL_H

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* next;
    Nodo* prev;

    Nodo(int d = 0, Nodo* n = nullptr, Nodo* p = nullptr) {
        dato = d;
        next = n;
        prev = p;
    }
};

class ListaDecimal {
public:
    friend ostream& operator<<(ostream&, const ListaDecimal&);
public:
    ListaDecimal();
    ListaDecimal(const ListaDecimal&); // Constructor de copia
    ~ListaDecimal();
    void pedirDatos();
    void entrarDatos(long);
    void quitarDatos();
    void borrarDatos(long);
    int validar(long);
    void imprimir1();
    void imprimir2();
    ListaDecimal operator+(const ListaDecimal&) const; // Operador de suma
private:
    Nodo* head;
    Nodo* tail;
};

#endif // LISTADECIMAL_H