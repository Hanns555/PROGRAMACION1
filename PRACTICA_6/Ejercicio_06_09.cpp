// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 20/10/2024 
// Número de ejercicio: 11
/*
9. Escribe un programa que invierta el orden de las palabras en una oración sin cambiar el 
orden de los caracteres dentro de cada palabra. 
• // Entrada: "Hola mundo desde C++"  
• // Salida: "C++ desde mundo Hola" 
*/ 
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    int m=0;
    string frase;
    string partes;
    vector <string> partes_v;
    cout<<"Ingrese una frase: ";
    getline(cin,frase);
    stringstream ss(frase);
    while (ss>> partes){
        partes_v.push_back(partes);
    }
    int v=partes_v.size();
    cout<<"La frase escrita al reves es: ";
    for (int i = 1; i <= v; i++)
    {
        cout<< partes_v[v-i]<<" ";
    }
    return 0;
}