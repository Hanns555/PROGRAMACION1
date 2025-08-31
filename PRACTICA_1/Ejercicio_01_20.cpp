// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P.
// Carrera del estudiante: Ingeniería Biomedica
// Fecha creación: 29/08/2025
// Número de ejercicio: 21
/*20. Crea un programa para calcular la cantidad de 
      dígitos que tiene un número entero.*/

#include <iostream>
using namespace std;
main(){
    //El long long es para que nuestro programa pueda calcular los digitos de un numero de hasta 19 digitos
    long long int numero=0, suma_de_digitos=0;
    cout<< " Ingrese un numero: ";
    cin>> numero;
    //Este while comienza el proceso donde numero de divide entre 10 hasta que sea igual a 0 o menor a 0
    while(numero>0){
        suma_de_digitos++; 
        numero=numero/10;
    }
    cout<< " Los digitos del numero ingresado son: "<< suma_de_digitos;
    return 0;
}