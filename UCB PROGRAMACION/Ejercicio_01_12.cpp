// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P.
// Carrera del estudiante: Ingeniería Biomedica
// Fecha creación: 24/08/2025
// Número de ejercicio: 12
#include <iostream>
using namespace std;
main (){
    int numero;
    do{
      cout<<"Ingrese un numero: ";
      cin>>numero;
    } while(numero<1 || numero>5); //Este do while hace que mientras mientras el numero ingresado no sea 1,2,3,4,5 sigue pidiendo un numero
    return 0;

}
