// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 LP
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 11/09/2025 
// Ejercicio: 1
#include <iostream>
using namespace std;

bool residuo(int x);

int main() {
    int numero;
    cout<< "Ingrese un numero: ";
    cin >> numero; //el usuario pone el número

    if(residuo(numero)){
        cout<< "El numero es par"; //si da true es par
    }
    else{
        cout<<"El numero es impar"; //si no es par, entonces es impar
    }

    return 0;
}

bool residuo(int x){
    if ((x%2)==0){
        return true;
    }
    return false; //si no cumple, devuelve false
}