// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 6
// Problema planteado: Generar listas de datos aleatorios en vectores usando funciones
#include <iostream>
#include <vector>

using namespace std;

vector<int> ingresar(){
    vector<int> v(5);
    for(int i = 0; i < 5; i++){
        cout << "Ingrese el valor " << i + 1 << ":\n";
        cin >> v[i];
    }
    return v;
}

vector<int> sumar (vector<int> v1, vector<int> v2){
    vector<int> v3(5);
    for(int i = 0; i < 5; i++){
        v3[i] = v1[i] + v2[i];
    }
    
    return v3;
}

void mostrar(vector<int> arr){
    for(int i = 0; i < 5; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    vector<int> v1 = ingresar();
    vector<int> v2 = ingresar();
    
    vector<int> v3 = sumar(v1, v2);
    
    mostrar(v1);
    mostrar(v2);
    mostrar(v3);
    return 0;
}