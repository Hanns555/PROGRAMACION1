// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 LP
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 11/09/2025 
// Ejercicio: 4
#include <iostream>
using namespace std;

double IMC(double x,  double y);

int main() {
    double PESO, ALTURA;
    cout << "Ingresa su PESO: ";
    cin >> PESO; //el usuario mete su peso en kilos
    cout << "Ingresa su ALTURA: ";
    cin >> ALTURA; //el usuario mete su altura en metros
    cout<< "Su IMC es: "<<IMC(PESO, ALTURA); //muestra el resultado del cálculo
    return 0;
}

double IMC(double x,  double y){
    double IMC;
    IMC= x/(y*y); //fórmula del índice de masa corporal
    return IMC;
}