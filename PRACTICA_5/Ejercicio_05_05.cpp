// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 5
/*
5. Leer 2 vectores de dimensión N y combine ambos en otro vector. 
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector <int> combinar(vector <int>x, vector <int>y);
int main(){
    system("cls");
    vector <int> elements1;
    vector <int> elements2;
    vector <int> a;
    string lista_1;
    string lista_2;
    double elementos1;
    double elementos2;
    cout<<"Ingrese elementos de lista_1: ";
    getline(cin,lista_1);
    stringstream ss(lista_1);
    while (ss>>elementos1)
    {
        elements1.push_back(elementos1);
    }
    cout<<"Ingrese elementos de lista_2: ";
    getline(cin,lista_2);
    stringstream aa(lista_2);
    while (aa>>elementos2)
    {
        elements2.push_back(elementos2);
    }
    cout<<"El vector combinado es: ";
    a=combinar(elements1,elements2);
    for (int i : a)
    {
        cout<< i<<" ";
    }
    return 0;
}

vector <int> combinar(vector <int>x, vector <int>y){
    for (int valor : y){
     x.push_back(valor);
    }
    return x;
}