// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 09/12/2025
// Número de ejercicio: 9
/*
10. Escribe una función llamada ReducirFraccion que reciba una estructura llamada
Fraccion y devuelva una nueva estructura FraccionSimplificada, que represente la
fracción simplificada.
Para simplificar, necesitarás calcular el Máximo Común Divisor (MCD) del
numerador y el denominador. Puedes implementar el algoritmo de Euclides, que
ya lo hiciste en la práctica 7 ejercicio 4.
Ejemplo: 4/8 → 1/2
*/

#include <iostream>

using namespace std;

struct Fracccion{
   int numerador;
   int denominador;
};

Fracccion ReducirFraccion(Fracccion X);
int mcd(int a, int b);

int main(){
    Fracccion X;
    Fracccion Valor;
    cout <<"Ingrese el numerador de la fraccion: ";
    cin >> X.numerador;
    cout <<"Ingrese el denominador de la fraccion: ";
    cin >> X.denominador;
    Valor = ReducirFraccion(X);
    cout << "La fraccion simplificada es:"<<endl;
    cout << "Numerador: "<<Valor.numerador<<endl;
    cout << "Denominador: "<<Valor.denominador<<endl;
    return 0;
}

int mcd(int a, int b) {
    if (b == 0)
        return a; // Caso base
    else
        return mcd(b, a % b); // Llamada recursiva
}

Fracccion ReducirFraccion(Fracccion X){
    Fracccion Fraccion_Simplificada;
    Fracccion Numero = X;
    double mcdv;
    mcdv = mcd (Numero.numerador,Numero.denominador);
    Fraccion_Simplificada.numerador = (Numero.numerador/mcdv);
    Fraccion_Simplificada.denominador = (Numero.denominador/mcdv);
    return Fraccion_Simplificada;
}

