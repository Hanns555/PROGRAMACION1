// Materia: Programación I, Paralelo 4 
// Autor: Hanns Micahel Silva Pardo. 
// Fecha creación: 16/09/2025 
// Número de ejercicio: 2
/*
2. Crea una función llamada “CalcularVolumen” que reciba un parámetro radio y un 
parámetro altura. El parámetro altura debe tener un valor por defecto de 10. Calcula y 
devuelve el volumen de un cilindro (usando la fórmula: V=π×r2×hV)  
*/
#include<iostream>
#include<cmath>
using namespace std;
double CalcularVolumen(double x, double y=10.0);
int main(){
    double radio=0, Volumen=0;
    cout<< "Ingrese el radio del cilindro: ";
    cin>> radio;
    Volumen=CalcularVolumen(radio);
    cout<< "El volumen es: "<< Volumen;
    return 0;
}
//Como nos dice que retorne un valor no usamos void
double CalcularVolumen(double x, double y){
    double Volumen=0;
    Volumen=M_PI*pow(x,2)*y;
    return Volumen;
}