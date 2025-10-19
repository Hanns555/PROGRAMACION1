// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Fecha creación: 18/10/2025 
// Número de ejercicio: 3
/*
3. Implementa una función recursiva que devuelva el enésimo número en la 
    secuencia de Fibonacci. La secuencia de Fibonacci es una serie de 
    números donde cada número es la suma de los dos anteriores, 
    comenzando con 0 y 1.   
*/ 
#include <iostream>

using namespace std;

int Fibonacci(int x);

int main (){
    int termino=0;
    cout<<"Hasta que termino de la serie de Fibonci desea calcular: ";
    cin>>termino;
    cout<<"La serie de fibonaci es: "<<Fibonacci(termino);
    return 0;
}

int Fibonacci(int n){
    if (n == 0) return 0;      // Caso base
    if (n == 1) return 1;      // Caso base
    return Fibonacci(n - 1) + Fibonacci(n - 2); // Llamadas recursivas
}