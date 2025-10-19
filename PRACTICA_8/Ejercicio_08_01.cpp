// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Fecha creación: 18/10/2025 
// Número de ejercicio: 1
/*
1. Escribe una función recursiva que reciba un número entero positivo y 
devuelva la suma de sus dígitos. Por ejemplo: para el número 1234, el 
resultado debería ser 10 (1 + 2 + 3 + 4). 
*/ 
#include <iostream>

using namespace std;

int suma(int x);

int main(){
    system("cls");
    int numero=0;
    cout<<"Ingrese un numero: ";
    cin>> numero;
    cout<<"La suma de los digitos es: "<<suma(numero);
    return 0;
}

//Se divide entre 10 para que llegue al caso base
int suma(int x){
    if(x==0){
        return 0;
    }
    else{
        return x%10 + suma(x/10);
    }
}