// Materia: Programación I, Paralelo 4 
// Autor: Hanns Micahel Silva Pardo. 
// Fecha creación: 16/09/2025 
// Número de ejercicio: 3
/*
3. Crea una función llamada “ModificarValores” que reciba dos parámetros: un entero 
por valor y un entero por referencia. La función debe multiplicar el valor por 2 (para el 
valor pasado por valor) y cambiar el valor por referencia (sumando 10).  
*/
#include<iostream>
using namespace std;
void ModificarValores(int x, int &y);
int main(){
    int Numero=0, Referencia=0;
    cout<< "Ingrese un numero entero: ";
    cin>>Numero;
    cout<< "Ingrese otro numero entero (Referencia): ";
    cin>>Referencia;
    cout<< "Numero antes de la funcion es: "<<Numero<<endl;
    cout<< "El valor por referencia antes de la funcion es: "<<Referencia<<endl;
    ModificarValores(Numero, Referencia);
    // Hacemos el cout ahora para demostrar que void cambio el valor refencia
    cout<< "El valor por referencia es ahora: "<<Referencia<<endl;
    return 0;
}
void ModificarValores(int x, int &y){
    x=x*2;
    y=y+10;
    cout<< "Numero ahora es: "<<x<<endl;
    
}
