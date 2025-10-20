// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 5
/*
5. Intersección de dos listas de clientes: dos empresas tienen listas de clientes y quieren 
saber cuántos clientes tienen en común. Escribe un programa que compare dos vectores 
de nombres y muestre los clientes repetidos.  
*/ 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

vector<string> interseccion(const vector<string>& clientes_1, const vector<string>& clientes_2);
vector <string> leerclientes(string lista);
int main(){
    system("cls");
    string lista_1;
    string lista_2;
    vector<string> clientes_1;
    vector<string> clientes_2;
    vector<string> repetidos;
    cout<<"Ingrese los clientes de la lista_1: ";
    getline(cin, lista_1);
    clientes_1 = leerclientes(lista_1);
    cout<<"Ingrese los clientes de la lista_2: ";
    getline(cin, lista_2);
    clientes_2 = leerclientes(lista_2);
    repetidos = interseccion(clientes_1,clientes_2);
    cout<<"Los clientes repetidos son: ";
    for (string i : repetidos)
    {
    cout<< i;
    }
    
    return 0;
}
vector <string> leerclientes(string lista){
    stringstream ss(lista);
    vector<string> cliente_1;
    //variable para guaardar datos
    string a;
    while (ss>>a)
    {
        cliente_1.push_back(a);
    }
    return cliente_1;
}

vector<string> interseccion(const vector<string>& clientes_1, const vector<string>& clientes_2) {
    //Defnimos los conjuntos A y B
    vector<string> resultado;
    set<string> conjuntoA(clientes_1.begin(), clientes_1.end());
    set<string> conjuntoB(clientes_2.begin(), clientes_2.end());
    //Definimos el vector de interseccion
    for (string x : conjuntoA) {
        if (conjuntoB.count(x)) {  // si x está en B
            resultado.push_back(x);
        }
    }
    return resultado;
}