// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 14
#include <iostream>
using namespace std;
main(){
    int numero;
    cout<<"Ingrese un numero: ";
    cin>>numero;
   for (int i = 0; i <= numero; i++)
   {
    for (int a = 1; a <= i; a++) //Este for hace que imprima a veces cada vez
    {
         cout<<"*";
    }
    cout<< endl; // Este endl hace que al imprimir los * se haga una linea abajo 
   }
    return 0;
}
