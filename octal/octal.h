#ifndef OCTAL_H
#define OCTAL_H

#include <iostream>
using namespace std;

class octal{
    friend ostream &operator<<(ostream &, const octal &);
public:
    octal(long = 0); // Constructor
    octal operator+(const octal &) const; //Operador sobrecargado
private:
    short oct[50];
};

#endif // OCTAL_H
