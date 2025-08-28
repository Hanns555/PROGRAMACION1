// Materia: Programación I, Paralelo 4 
// Autor: Willy Edwin Tenorio Palza 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 24/08/2025 
// Número de ejercicio: 12
#include <iostream>
using namespace std;
main (){
    int numero;
    do{
      cout<<"Ingrese un numero: ";
      cin>>numero;
    } while(numero<1 || numero>5);
    return 0;
}