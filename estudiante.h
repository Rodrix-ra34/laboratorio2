#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#include <iostream>
#include <string>
using namespace std;

class Estudiante
{
private:
    string nombre;
    float notafinal;

public:
    Estudiante(string n, float notaf) : nombre(n), notafinal(notaf) {}
    float nota()
    {
        return notafinal;
    }
    void imprimir()
    {
        cout << nombre << " su nota es: " << notafinal << endl;
    }
};

#endif
