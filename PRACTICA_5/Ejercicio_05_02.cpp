// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 2
// Problema planteado: Introducir y mostrar valores en un arreglo

#include <iostream>
using namespace std;

void mostrarVoltios(double voltios[], int n);

int main() {
    double voltios[] = {11.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59};
    int n = 9;
    mostrarVoltios(voltios, n);
    return 0;
}
void mostrarVoltios(double voltios[], int n) {
    for (int i = 0; i < n; i++) {
        cout << voltios[i] << "\t";
        if ((i+1)%3 == 0) cout << endl;
    }
}
