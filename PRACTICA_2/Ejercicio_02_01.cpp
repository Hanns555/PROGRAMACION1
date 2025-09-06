// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 06/09/2025 
// Número de ejercicio: 1
/*
1. Simular el lanzamiento de un dado n veces y determinar la frecuencia de 
repetición de las caras pares. 
*/ 
#include <iostream>
#include <ctime>
using namespace std;
int main (){
    int DADO,lanzamiento, x=1, contador=0;
    srand(time(NULL));
    cout<< "Ingrese el numero de veces que lanzara el dado: ";
    cin>> lanzamiento;
    while( x <= lanzamiento){
    DADO=(rand()%6)+1;
    cout<< DADO<< " ";
    if((DADO%2)==0){
        contador++;
    }
    x++;
    } 
    cout<< endl;
    cout<< "El numero de veces que salio una cara par en sus lanzamientos fue: "<<contador;
    return 0;
}