// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 24/08/2025 
// Número de ejercicio: 8 
#include <iostream>
using namespace std;
int main (){
    int NUMERO, par;
    cout<<"Ingrese su numero entero: ";
    cin>> NUMERO;
    // % calucla el residuo del resultado de dividir el numero ingresado entre 2
    par= NUMERO % 2;
    // Si par es igual a 0 el numero es par
    if(par == 0){
      cout<<"El numero es par";
    }
    else{
      cout<<"El numero es impar";
    }
    return 0;
}