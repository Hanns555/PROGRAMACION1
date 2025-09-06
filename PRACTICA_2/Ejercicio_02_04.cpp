// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 06/09/2025 
// Número de ejercicio: 4
/*
4. Escribir un algoritmo que permita adivinar un número que se genere internamente 
al azar, el cual está en el rango de 0 a 50. El usuario debe adivinar este número en 
base a aproximaciones para lo cual se dispone de 5 intentos. 
*/ 
#include<iostream>
#include<ctime>
using namespace std;
int main(){
    int numero_generado=0, usuario=0, x=0, aprox1=0, aprox2=50;
    srand(time(NULL));
    numero_generado= rand()%50;
    cout<< "El numero que pienso esta entre "<<usuario<< " y "<<50<< endl;
    while (usuario!=numero_generado && x<=4){
    cin>> usuario;
    if(usuario<numero_generado){
     aprox1=usuario;
     cout<< "El numero que pienso esta entre "<<aprox1<< " y "<<aprox2<< endl;
     cout<< "Intentos restantes: "<< 4-x<< endl;
    }
    else if (usuario >numero_generado){
     aprox2=usuario;
     cout<< "El numero que pienso esta entre "<<aprox1<< " y "<< aprox2<< endl;
     cout<< "Intentos restantes: "<< 4-x<< endl;
    }
    x++;
    }
    if(usuario==numero_generado){
     cout<< "Bravo! El numero que pense fue: "<< numero_generado<< endl;
    }
    else{
     cout<< "Vuelve a intentarlo mi numero era: "<< numero_generado<<endl;
    }
    return 0;
}