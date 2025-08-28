// Materia: Programación I, Paralelo 4 
// Autor: Willy Edwin Tenorio Palza 
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
    for (int a = 0; a <= i; a++)
    {
         cout<<"*";
    }
    cout<< endl;
   }
   

    return 0;
}