// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Fecha creación: 19/10/2025 
// Número de ejercicio: 6
/*
6. Realizar un algoritmo recursivo para comparar si dos vectores son iguales. 
*/ 
#include <iostream>
#include <vector>

using namespace std;

bool SonIguales(const vector<int>& v1, const vector<int>& v2, int n, int indice=0);

int main(){
    int tamanio=0;
    vector <int> v1;
    vector <int> v2;
    cout<<"Ingrese el tamanio de los vectores"<<endl;
    cin>> tamanio;
    // Redimenciona los vectores
    v1.resize(tamanio);
    v2.resize(tamanio);
    cout << "Ingrese los " << tamanio << " elementos del primer vector:\n";
    for (int i = 0; i < tamanio; i++) {
        cout<<"Ingrese el elemento de la posicion "<<i<<": ";
        cin >> v1[i];
    }
    cout << "Ingrese los " << tamanio << " elementos del segundo vector:\n";
    for (int i = 0; i < tamanio; i++) {
        cout<<"Ingrese el elemento de la posicion "<<i<<": ";
        cin >> v2[i];
    }
    if (SonIguales(v1, v2, tamanio)) {
        cout << "Los vectores son iguales." << endl;
    } else {
        cout << "Los vectores NO son iguales." << endl;
    }
    return 0;
}

bool SonIguales(const vector<int>& v1, const vector<int>& v2, int n, int indice) {
    // Caso base: ya se compararon todos los elementos
    if (indice == n) {
        return true;
    }
    // Si los elementos en la posición actual son distintos
    if (v1[indice] != v2[indice]) {
        return false;
    }
    else {
        return SonIguales(v1, v2, n, indice + 1);
    }
}