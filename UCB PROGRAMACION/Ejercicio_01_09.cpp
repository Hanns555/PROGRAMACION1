// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 24/08/2025 
// Número de ejercicio: 9 
#include <iostream>
using namespace std;
int main(){
    int edad;
    cout<<"Ingrese su edad: ";
    cin>>edad;
    // El siguiente bloque hace que evalua si edad pertenece a cierto intervalo
    if (0<edad && edad<=12)
    {
        cout<< "El usuario es un nino";
    }
    else if (12<edad && edad<=18){
         cout<< "El usuario es adolescente";
    }
    else if (18<edad && edad<60){
         cout<< "El usuario es adulto";
    }
    else if (60<=edad){
         cout<< "El usuario es adulto mayor";
    }
    else{
         cout<< "Edad invalida";
    }
    return 0;
}