// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Fecha creación: 19/10/2025 
// Número de ejercicio: 7
/*
7. Realizar un algoritmo recursivo para la siguiente función: 1^2+2^2+..+n^2
*/ 
#include <iostream>
#include <cmath>

using namespace std;

int suma_cuadrados(int x); 

int main (){
    system("cls");
    int numero=0;
    cout<<"Ingrese un numero: ";
    cin>> numero;
    cout<<"La suma de los cuadrados hasta es: "<<suma_cuadrados(numero);
    return 0;
}

int suma_cuadrados(int x) {
    if (x==0)
    {
        return 0;
    }
    else{
        return pow(x,2)+suma_cuadrados(x-1);
    }
}