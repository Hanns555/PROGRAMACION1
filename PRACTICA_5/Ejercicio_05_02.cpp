// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 2
/*
2.  Escriba un programa para introducir los siguientes valores en un arreglo nombrado 
    voltios: 11.95 16.32 12.15 8.22 15.98 26.22 13.54 6.45 17.59. Después que se hayan 
    introducido los datos, haga que su programa despliegue los valores. 
                                        11.95 16.32 12.15 
                                        8.22 15.98 26.22 
                                        13.54 6.45 17.59 
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(){
    // Variable donde se guardan los datos numeicos del string
    double valor;
    vector<double>voltios;
    string t_voltios;
    cout<< "Ingrese su lista de valores: ";
    getline(cin, t_voltios);
    stringstream ss(t_voltios);
    // Ingresa los datos al vector valor
    while (ss >> valor) { 
    voltios.push_back(valor);
    }
    // Muestra como matriz 3x3
    for (int i = 0; i < voltios.size(); i++) {
        cout << voltios[i] << " ";
        if ((i + 1) % 3 == 0) {  
            cout << endl;
        }
    }
    return 0;
}
