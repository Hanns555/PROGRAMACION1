// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 06/09/2025 
// Número de ejercicio: 3
/*
3. Genera un número aleatorio entre 1 y 10 y calcula su factorial.
*/ 
#include <iostream>
#include <ctime>
using namespace std;
int main(){
    int numero=0, factorial=1, rango;
    srand(time(NULL));
    cout<< "Ingrese el rango de su numero aletorio factorial: " ;
    cin >> rango;
    // Definimos un rango porque si no lo hacemos el rand () generaria un numero
    // demasiado grande que no pueda calcular el programa
    numero= (rand()% rango)+1;
    // El for calcula el factorial ddel numero aleatorio generado
    for(int x=1; x<=numero; x++){
       factorial*=x;
    }
    cout<< "El factorial de "<< numero<< " es: "<<factorial;
    return 0;
}