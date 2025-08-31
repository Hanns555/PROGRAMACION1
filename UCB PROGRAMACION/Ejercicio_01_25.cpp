// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P.
// Carrera del estudiante: Ingeniería Biomedica
// Fecha creación: 29/08/2025
// Número de ejercicio: 25
/*25. Pedir un número y mostrar su tabla de multiplicar del 1 al 10.
      Al terminar, preguntar:
      “¿Desea calcular otra tabla? (s/n)”.
      Repetir mientras la respuesta sea ‘s’.*/
    
#include <iostream>
using namespace std;
int main(){
    int numero;
    char respuesta= 's';
    while (respuesta!='n'){
    cout<< "Ingrese un numero: ";
    cin>> numero;
    int x=1;
    while(x<=10){
        cout<< numero<< " x "<< x<< " = "<< numero*x<<endl;
    x++;}
    cout<< " ¿Desea calcular otra tabla? (s/n) ";
    cin>> respuesta;

    switch(respuesta){
        case 's':
         break;
        case 'n':
         break;
        default:
         cout << "Opción no valida. " << endl;
         respuesta = 'n';
         break;
    }}
    return 0;
}
