// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 3
// Problema planteado: Calcular suma, promedio, desviación y varianza de calificaciones

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double promedio(const vector<int>& v);

double varianza(const vector<int>& v, double prom);

int main() {
    int n;
    cout << "Ingrese la cantidad de calificaciones: ";
    cin >> n;

    vector<int> calificaciones(n);
    for (int i = 0; i < n; i++) {
        cout << "Nota " << i+1 << ": ";
        cin >> calificaciones[i];
    }

    double prom = promedio(calificaciones);
    cout << "Promedio = " << prom << endl;

    cout << "Calificación - Desviación" << endl;
    for (int x : calificaciones) {
        double desv = x - prom;
        cout << x << " -> " << desv << endl;
    }

    cout << "Varianza = " << varianza(calificaciones, prom) << endl;
    return 0;
}
double promedio(const vector<int>& v) {
    double suma = 0;
    for (int x : v) suma += x;
    return suma / v.size();
}

double varianza(const vector<int>& v, double prom) {
    double suma = 0;
    for (int x : v) suma += pow(x - prom, 2);
    return suma / v.size();
}