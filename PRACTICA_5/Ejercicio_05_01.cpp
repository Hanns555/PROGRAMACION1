// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 1
/*
1. Escriba un programa con 6 funciones utilizando vectores para lo siguiente: 
    a. Una lista de 100 voltajes de precisión doble (entre 20.00 V y 220.00 V) 
    b. Una lista de 50 temperaturas de precisión doble (Entre 0.00 y 100.00) 
    c. Una lista de 30 caracteres alfanuméricos. 
    d. Una lista de 100 años en número entero (entre 1990 y 2025) 
    e. Una lista de 32 velocidades de precisión doble (entre 10.00 y 300.00) 
    f. Una lista de 1000 distancias de precisión doble (entre 1.00 a 1000.00) 
   Los datos debes ser generados utilizando numero aleatorios. 
*/
#include <iostream>
#include <vector>
// Libreria para setpresicion
#include <iomanip> 
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
int aleatorio(int Limite_superior, int Limite_inferior);
void voltajes (int G_voltajes);
void temperaturas (int G_temperaturas);
void alfanumericos(int G_alfanumericos);
void anios (int G_anios);
void velocidades (int G_velocidades);
void distancias (int G_distancias);
int main(){
    system("cls");
    int n1=100, n2=50, n3=30,n4=100, n5=32, n6=1000;
    srand(time(0));
    cout<< "a) Los voltajes generados son: ";
    voltajes(n1);
    cout<< "b) Las temperaturas generadas son: ";
    temperaturas(n2);
    cout<< "c) Los caracteres alfanumericos generados son: "<< endl;
    alfanumericos(n3);
    cout<< "d) Los anios generados son: ";
    anios(n4);
    cout<< "e) Las velocidades generadas son: ";
    velocidades(n5);
    cout<< "f) Las distancias generadas son: ";
    distancias(n6);
    return 0;
}
void alfanumericos(int G_alfanumericos){
    int m=0;
    srand(time(0));
    string palabra = "123456789qazwsxedcrfvtgbyhnujmikolp";
    for (int i = 0; i < G_alfanumericos ; i++)
    {
        m= aleatorio(35,1);
        cout<<palabra[m]<< " ";
    }
    cout<< endl;
}

void distancias (int G_distancias){
    int a=1000,b=1;
    double g=0;
    vector<double>lista_6;
    cout<<endl;
    // Genera el vector con n de tamano
    for (int x=0 ; x<G_distancias ;x++ )
    {
        g=aleatorio(a,b);
        lista_6.push_back(g);
    }
    // Configura la salida para mostrar 2 decimales
    cout << fixed << setprecision(2);
    // Muestra los elementos del vector
     for (double y : lista_6 )
    {
        cout<< y<<" ";
    }
    cout<< endl;
}

void velocidades (int G_velocidades){
    int a=300,b=10;
    double g=0;
    vector<double>lista_5;
    cout<<endl;
    // Genera el vector con n de tamano
    for (int x=0 ; x<G_velocidades ;x++ )
    {
        g=aleatorio(a,b);
        lista_5.push_back(g);
    }
    // Configura la salida para mostrar 2 decimales
    cout << fixed << setprecision(2);
    // Muestra los elementos del vector
     for (double y : lista_5 )
    {
        cout<< y<<" ";
    }
    cout<< endl;
}

void anios (int G_anios){
    int a=2025,b=1990;
    double g=0;
    vector<double>lista_4;
    cout<<endl;
    // Genera el vector con n de tamano
    for (int x=0 ; x<G_anios ;x++ )
    {
        g=aleatorio(a,b);
        lista_4.push_back(g);
    }
    // Muestra los elementos del vector
     for (int y : lista_4 )
    {
        cout<< y<<" ";
    }
    cout<< endl;
}

void temperaturas (int G_temperaturas){
    int a=100,b=0;
    double g=0;
    vector<double>lista_2;
    cout<<endl;
    // Genera el vector con n de tamano
    for (int x=0 ; x<G_temperaturas ;x++ )
    {
        g=aleatorio(a,b);
        lista_2.push_back(g);
    }
    // Configura la salida para mostrar 2 decimales
    cout << fixed << setprecision(2);
    // Muestra los elementos del vector
     for (double y : lista_2 )
    {
        cout<< y<<" ";
    }
    cout<< endl;
}

void voltajes (int G_voltajes){
    int a=220,b=20;
    double g=0;
    vector<double>lista_1;
    cout<<endl;
    // Genera el vector con n de tamano
    for (int x=0 ; x<G_voltajes ;x++ )
    {
        g=aleatorio(a,b);
        lista_1.push_back(g);
    }
    // Configura la salida para mostrar 2 decimales
    cout << fixed << setprecision(2);
    // Muestra los elementos del vector
     for (double y : lista_1 )
    {
        cout<< y<<" ";
    }
    cout<< endl;
}

int aleatorio(int Limite_superior, int Limite_inferior){
    int random=0;
    random = ( rand() % (Limite_superior-Limite_inferior+1)) + Limite_inferior;
    return random;
}