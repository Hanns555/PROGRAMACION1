// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 7
/*
7.  Programa que declare un vector de diez elementos enteros y pida números para 
    rellenarlo hasta que se llene el vector o se introduzca un número negativo. Entonces se 
    debe imprimir el vector (sólo los elementos introducidos). 
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main(){
    int lista[10],n=0, i=0;
    while (n!=10)
    {
        cout << "Ingrese el elemento " << n + 1 << " para la lista: ";
        cin >> lista[n];
        if (lista[n]<0){break;} 
        n++;
    }
    cout<<"Los elementos de la lista son: ";
    for (int i=0; i < n; i++)
    {
        cout<<lista[i]<<" ";
    }
    
    return 0;
}