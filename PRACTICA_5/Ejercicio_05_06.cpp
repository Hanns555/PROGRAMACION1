// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 6
/*
6. Programa que declare tres vectores ‘vector1’, ‘vector2’ y ‘vector3’ de cinco enteros 
   cada uno, pida valores para ‘vector1’ y ‘vector2’ y calcule vector3=vector1+vector2. 
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
void mostrar(int n);
int main (){
    int a;
    cout<<"Ingrese el tamanio de los vectores: ";
    cin>>a;
    mostrar(a);
    return 0;
}
void mostrar(int n){
    int vector_1[100], vector_2[100], vector_3[100];
    for (int i = 0; i < n; i++)
    {
        cout<< i+1<<". Ingrese los datos del vector_1: ";
        cin>>vector_1[i];
    }
    cout<<"Los valores de vector_1 se guardo correctamente"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<< i+1<<". Ingrese los datos del vector_2: ";
        cin>>vector_2[i];
    }
    cout<<"Los valores de vector_2 se guardo correctamente"<<endl;
    for (int i = 0; i < n; i++)
    {
        vector_3[i]=vector_1[i]+vector_2[i];
    }
    cout<< "El vector_3 es: ";
    for ( int x = 0 ; x<n ; x++)
    {
        cout<<vector_3[x]<<" ";
    }
}