// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Fecha creación: 18/10/2025 
// Número de ejercicio: 4
/*
5. Realizar un algoritmo recursivo, dado un vector de números enteros, 
retorne la suma de sus elementos. 
*/ 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int suma_elementos(vector<int> x, int tamanio);

int main (){
    vector <int> numero;
    string elementos;
    int elemento;
    cout<< "Ingrese los datos del vector: ";
    getline(cin, elementos);
    stringstream ss(elementos);
    while (ss>>elemento)
    {
        numero.push_back(elemento);
    }
    /*
    for ( int i : numero)
    {
        cout<<i<<" ";
    }
    */
    cout<<"La suma de elementos es: "<< suma_elementos(numero, numero.size());
    return 0;
}

int suma_elementos(vector<int> x, int tamanio) {
    if (tamanio == 0)
        return 0; // Caso base
    else
        return x[tamanio-1]+suma_elementos(x,tamanio-1); // Llamada recursiva
}