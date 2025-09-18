// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 17/09/2025 
// Número de ejercicio: 6
/*
6. Leer un número entero y determinar si las sumas de sus dígitos distintos de cero 
forman un número primo; de ser así, imprimir el mensaje respectivo.  
*/
#include <iostream>
using namespace std;
void SumaDigitos(int x);
int EsPrimo(int a);
int main(){
    int numero=0;
    cout<< "Ingreese un numero: ";
    cin>>numero;
    SumaDigitos (numero);
    return 0;
}
void SumaDigitos(int x){
   int digito=0, suma=0;
   while(x>0){
     digito=(x%10);
     suma+=digito;
     x=x/10;
   }
   cout<<"La suma de los digitos del numero ingresado es: " <<suma<< endl;
   if (EsPrimo(suma)==1)
   {
   cout<<"La suma de los digitos es primo"<< endl;
   }
   else{
   cout<<"La suma de los digitos no es primo"<< endl;
   }
}
// Esta funcion retorna 0 si el numero tiene mas de dos divisores
int EsPrimo(int a){
    int Division=0, Contador=0;
    for ( int i = 1; i <= a; i++)
    {
        Division= a%i;
        if(Division==0){Contador++;}
    }
    if(Contador==2){
        return 1;
    }
    else{
        return 0;
    }
    
    
}