// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Fecha creación: 18/10/2025 
// Número de ejercicio: 4
/*
4. Realizar un algoritmo recursivo para calcular el máximo común divisor de 
dos números enteros aplicando el algoritmo de Euclides. 
*/ 
#include <iostream>

using namespace std;

int mcd(int n, int m);

int main (){
    int a=0,b=0;
    cout<<"Ingrese un numero a: ";
    cin>>a;
    cout<<"Ingrese un numero b: ";
    cin>>b;
    cout<<"El mcd es: "<< mcd(a,b);
    return 0;
}

int mcd(int a, int b) {
    if (b == 0)
        return a; // Caso base
    else
        return mcd(b, a % b); // Llamada recursiva
}