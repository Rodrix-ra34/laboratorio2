#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>
#include "estudiante.h"

using namespace std;

struct Nodo
{
    Estudiante* est;
    Nodo* sig;

    Nodo(Estudiante* e)
    {
        est = e;
        sig = nullptr;
    }
};

class ListaEnlazada
{
private:
    Nodo* head;

    float sumarNotas(Nodo* actual, int& contador)
    {
        if (actual == nullptr)
            return 0;

        contador++;
        return actual->est->nota() + sumarNotas(actual->sig, contador);
    }

public:
    ListaEnlazada()
    {
        head = nullptr;
    }

    void agregarEstudiante(string nombre, float nota)
    {
        Estudiante* nuevo = new Estudiante(nombre, nota);
        Nodo* nuevoNodo = new Nodo(nuevo);

        if (head == nullptr)
        {
            head = nuevoNodo;
        }
        else
        {
            Nodo* temp = head;
            while (temp->sig != nullptr)
                temp = temp->sig;

            temp->sig = nuevoNodo;
        }
    }

    void imprimirLista()
    {
        Nodo* temp = head;
        cout << "--- Lista de Estudiantes ---" << endl;

        while (temp != nullptr)
        {
            temp->est->imprimir();
            temp = temp->sig;
        }
    }

    float calcularPromedioRecursivo()
    {
        int total = 0;
        float suma = sumarNotas(head, total);

        if (total == 0)
            return 0;

        return suma / total;
    }

    ~ListaEnlazada()
    {
        Nodo* temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->sig;
            delete temp->est;
            delete temp;
        }
    }
};

#endif
