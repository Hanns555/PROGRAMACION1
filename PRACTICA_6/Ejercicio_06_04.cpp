// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 4
/*
4. Crea un programa que permita al usuario ingresar N números en un vector y luego rota 
   el vector k posiciones a la derecha. Muestra el vector después de la rotación. 
*/ 
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;
void leerdatos(string& datos);
void mover_posiciones(vector<int>&lista);
int main(){
    system("cls");
    string datos;
    cout<<"Ingrese los datos que quiera separados por espacios: ";
    getline(cin, datos);
    leerdatos(datos);
    return 0;
}

void leerdatos(string& datos){
    vector <int> lista;
    // variable donde se guarda la separacion del string datos
    int a;
    stringstream ss(datos);
    while (ss>>a)
    {
        lista.push_back(a);
    }
    /*
    for (int x : lista)
    {
        cout<< x<<" ";
    }
    */
    // cout<<endl;
    mover_posiciones(lista);
}
// Funcion que rota el vector a la izquierda
void mover_posiciones(vector<int>&lista){
    int k=0, q=0;
    vector<int>copia;
    cout<<"Ingresa la cantidad de posiciones que desea mover: ";
    cin>> k;
    q= lista.size();
    // aniade los ultimos elementos (los que movi)
    for (int i = lista.size()-k; i < lista.size(); i++)
    {
        copia.push_back(lista[i]);
    }
    // copia al final los datos iniciales
    for (int i = 0; i < lista.size()-k; i++)
    {
        copia.push_back(lista[i]);
    }
    lista=copia;
    cout<<"El vector rotado es: ";
    for (int t : lista)
    {
        cout<< t<<" ";
    } 
}