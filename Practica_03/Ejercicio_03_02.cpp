// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 LP
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 11/09/2025 
// Ejercicio: 2
#include <iostream>
using namespace std;

double farenheit(double x);

int main() {
    double temperatura;
    cout<< "Ingrese su temperatura: ";
    cin >> temperatura; //aquí el usuario mete la temperatura en °C
    cout<< "Su temperatura es: "<<farenheit(temperatura); //muestra el resultado en °F
    return 0;
}

double farenheit(double x){
    double convertir;
    convertir= (9.0/5.0)*x+32; //fórmula para pasar de °C a °F
    return convertir;
}