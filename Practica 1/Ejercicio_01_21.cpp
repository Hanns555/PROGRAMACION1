// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P.
// Carrera del estudiante: Ingeniería Biomedica
// Fecha creación: 29/08/2025
// Número de ejercicio: 21
/*21. Crea un programa para calcular para multiplicar dos números enteros, 
      sin emplear el operador de la multiplicación, empleando sumas sucesivas.*/
#include <iostream>
using namespace std;
int main (){
    int numero_1=0, numero_2=0,x=1, suma=0;
    cout<<" Este programa calcula la multiplicacion de numero_1 x numero_2"<< endl;
    cout<<" Ingrese un numero: ";
    cin>> numero_1;
    cout<<" Ingrese un numero: ";
    cin>> numero_2;
    // Este while suma numero_2-veces el numero_1
    while( x <=numero_2){
       suma+= numero_1;
       x++;
    }
    cout<< " La multiplicacion de "<<numero_1<<" x "<<numero_2<<" = "<<suma;
    return 0;
}