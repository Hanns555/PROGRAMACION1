// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 24/08/2025 
// Número de ejercicio: 6
#include <iostream>
using namespace std;
main (){
    // double es casi lo mismo que float solo que admite mas decimales
    double Numero;
    cout<<"Ingrese su numero: ";
    cin>>Numero;
    // Con el siguiente if comienza a evaluar el dato ingresado para ver que condicion cumple o sino cumple ninguna con else
    if (Numero>0)
    {
        cout<< "El numero es positivo";
    }
    else if (Numero<0){
         cout<< "El numero es negativo";
    }
    else{
         cout<< "El numero es 0";
    }
    return 0;
}

