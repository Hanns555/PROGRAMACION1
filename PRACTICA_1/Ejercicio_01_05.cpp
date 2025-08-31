// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 24/08/2025 
// Número de ejercicio: 5
#include <iostream>
using namespace std;
main (){
    double temperatura_kelvin,temperatura_centigrados;
    cout<<"Ingrese su temperatura en grados centigrados: ";
    cin>> temperatura_centigrados;
    // Establece la temperatura en kelvin sumando 273 al dato ingresado 
    temperatura_kelvin= 273 + temperatura_centigrados;
    cout<<"Su temperatura en grados kelvin es: "<<temperatura_kelvin;
    return 0;

}
