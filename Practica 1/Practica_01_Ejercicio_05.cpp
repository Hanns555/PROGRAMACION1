// Materia: Programación I, Paralelo 4 
// Autor: Willy Edwin Tenorio Palza 
// Carnet: 8357097 L.P. cls
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 24/08/2025 
// Número de ejercicio: 5
#include <iostream>
using namespace std;
main (){
    double temperatura_kelvin,temperatura_centigrados;
    cout<<"Ingrese su temperatura en grados centigrados: ";
    cin>> temperatura_centigrados;
    temperatura_kelvin= 273 + temperatura_centigrados;
    cout<<"Su temperatura en grados kelvin es: "<<temperatura_kelvin;
    return 0;
}