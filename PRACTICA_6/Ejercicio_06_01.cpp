// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 1 
/*
1. Almacene en un arreglo las edades de varias personas (hasta ingresar un -1) y a partir 
   de este arreglo determine la desviación típica. 
*/  
#include <iostream> 
#include <vector> 
#include <cmath>
#include <string> 

using namespace std;
double calculo(double y, double z);
int main (){
    system("cls");
    int  n=0, edades[100];
    double suma=0, media_aritmetica=0, numerador=0, desviacion_tipica=0, fraccion=0;
    while (n>=0)
    {
      cout<<"Ingrese la edad "<< n+1<<" a almacenar: ";
      cin>> edades [n];
      if (edades[n]<0){ 
        break; }
      n++;
    }
    for ( int x=0; x<n; x++)
    {
        suma+=edades[x];
    }
    media_aritmetica= suma/ n;
    for (int a=0; a<n; a++)
    {
        numerador+= pow(edades[a]-media_aritmetica,2);
    }
    desviacion_tipica= calculo(numerador,n);
    cout<< "La desviacion tipica es: "<<desviacion_tipica;
    return 0;
}

double calculo(double y, double z){
    double resultado=0, x=0;
    x= y/z;
    resultado= sqrt(x);
    return resultado;
}
