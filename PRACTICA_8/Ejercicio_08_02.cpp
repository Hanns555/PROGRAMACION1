// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Fecha creación: 18/10/2025 
// Número de ejercicio: 2
/*
2. Implementa una función recursiva para calcular la potencia de un número. 
    La función debe recibir dos parámetros, la base a y el exponente n, y 
    devolver el valor de a^n. Evita usar la función pow de la biblioteca 
    estándar. Por ejemplo, potencia(2, 3) debería devolver 8.  
*/ 
#include <iostream>

using namespace std;

int potencia(int base, int exponente);

int main(){
    system("cls");
    int numero=0, exponente=0;;
    cout<<"Ingrese un numero: ";
    cin>>numero;
    cout<<"Ingrese el exponente del numero: ";
    cin>>exponente;
    cout<<"La potencia del numero es: "<<potencia(numero, exponente);
    return 0;
}
// Se resta el exponente para llegar al caso base
int potencia(int base, int exponente){
    if(exponente==0){
        return 1;
    }
    else{
        return base*potencia(base,exponente-1);
    }
}