// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 LP
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 11/09/2025 
// Ejercicio: 10
#include <iostream>
using namespace std;

double calcularTarifa (double kmRecorridos){
    double costo = 10.0; //tarifa base del viaje
    costo += (kmRecorridos * 2.0); //cada km suma 2 Bs
    if(kmRecorridos > 10.0){
        costo -= (costo * 0.1); //si pasa de 10 km hay descuento del 10%
    }
    return costo;
}

int main(){
    double recorrido;
    cout << "Ingrese el recorrido del viaje en taxi" << endl;
    cin >> recorrido; //el usuario escribe los km del viaje

    double costo = calcularTarifa(recorrido);
    cout << "El costo del viaje es de: " << costo << endl;

    return 0;
}