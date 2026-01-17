#include <iostream>
#include "listaenlazada.h"

using namespace std;

int main()
{
    ListaEnlazada lista;

    // Agregar estudiantes
    lista.agregarEstudiante("Emely", 8.5);
    lista.agregarEstudiante("Rodrigo", 9.0);
    lista.agregarEstudiante("Carlos", 9.2);
    lista.agregarEstudiante("juana", 8.8);

    // Imprimir lista
    lista.imprimirLista();

    // Calcular y mostrar promedio
    float promedio = lista.calcularPromedioRecursivo();
    cout << "\nPromedio final: " << promedio << endl;

    return 0;
}
