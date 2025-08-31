// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P.
// Carrera del estudiante: Ingeniería Biomedica
// Fecha creación: 29/08/2025
// Número de ejercicio: 23
/*23. Crea un programa para leer un número 
      entero y mostrarlo con las cifras al revés.*/

#include <iostream>
using namespace std;
int main(){
    int numero, numero_invertido=0,modulo;
    cout<<"Ingrese un numero: ";
    cin>>numero;
    //Con el siguiente while comienza las operaciones para invertir un numero
    while (numero>0)
    {   
        modulo = numero%10;
        // La siguiente ecuacion calcula las unidades, desenas, centenas, etc de numero
        numero_invertido = modulo + numero_invertido*10;
        // Se actualiza el valor de numero hasta que se detenga el while
        numero=numero/10;
    }
    cout<< "El numero invertido es: "<<numero_invertido;
    return 0;
}