// Materia: Programación I, Paralelo 4 
// Autor: Willy Edwin Tenorio Palza 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 24/08/2025 
// Número de ejercicio: 6
#include <iostream>
using namespace std;
main (){
    double Numero;
    cout<<"Ingrese su numero";
    cin>>Numero;
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
