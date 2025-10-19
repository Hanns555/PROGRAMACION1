// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Fecha creación: 19/10/2025 
// Número de ejercicio: 8
/*
8.  Realizar un algoritmo recursivo para elaborar un programa en el que dado 
    un entero n > 1, calcule e imprima los elementos correspondientes a la 
    conjetura de Ullman (en honor al matemático  Ullman) que consiste en lo 
    siguiente: 
        • Empiece con cualquier entero positivo. 
        • Si es par, divídalo entre 2; si es impar multiplíquelo por 3 y agréguele 1. 
        • Obtenga enteros sucesivamente repitiendo el proceso. 
*/ 
#include <iostream>

using namespace std;

int Ullman(int x); 

int main (){
    system("cls");
    int numero=0;
    cout<<"Ingrese un numero: ";
    cin>> numero;
    cout<<"La serie de Ullman de "<<numero<<" es: "<<endl;
    Ullman(numero);
    return 0;
}

int Ullman(int x) {
    cout<< x<<" ";
    if (x==1)
    {
        return 1;
    }
    if (x%2==0)
    {
        return Ullman(x/2);
    }
    else{
        return Ullman(3*x+1);
    }
}