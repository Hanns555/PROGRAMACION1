// Materia: Programación I, Paralelo 3 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 5
/*
5. Multiplique dos matrices una de N x M y la otra de M x N 
*/

// Materia: Programación I, Paralelo 3 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 5
/*
5. Multiplique dos matrices una de N x M y la otra de M x N 
*/

#include <iostream>
using namespace std;

int main(){
system("cls");
int Matriz1[100][100], filas1, columnas1;
int Matriz2[100][100], filas2, columnas2;
int Matrz_Producto[100][100];
cout<<"Ingrese las filas de Matriz1: ";
cin>> filas1;
cout<<"Ingrese las columnas de Matriz1: ";
cin>> columnas1;
cout<<"Ingrese los elementos de Matriz1: "<<endl;
for (int i = 0; i < filas1; i++)
{
for (int j = 0; j < columnas1; j++)
{
cout<<"El elemento de la posicion ("<<i<<","<<j<<"): ";
cin>>Matriz1[i][j];
}
}
cout<<"Ingrese las filas de Matriz2: ";
cin>> filas2;
cout<<"Ingrese las columnas de Matriz2: ";
cin>> columnas2;
cout<<"Ingrese los elementos de Matriz2: "<<endl;
for (int i = 0; i < filas2; i++)
{
for (int j = 0; j < columnas2; j++)
{
cout<<"El elemento de la posicion ("<<i<<","<<j<<"): "; 
cin>>Matriz2[i][j];
}
}
if(columnas1!=filas2){
cout<<"No se puede multiplicar ñas matrices";}
else{
for (int i = 0; i < filas1; i++)
{
for (int j = 0; j < columnas2; j++)
{
for (int z = 0; z < columnas1; z++)
{
Matrz_Producto[i][j]+=Matriz1[i][z]*Matriz2[z][j];
}
}
}
}
for (int i = 0; i < filas1; i++)
{
for (int j = 0; j < columnas2; j++)
{
cout<<"\t"<<Matrz_Producto[i][j]; }
cout<<endl; }
return 0;
}