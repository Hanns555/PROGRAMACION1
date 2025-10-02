// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 1
// Problema planteado: Generar listas de datos aleatorios en vectores usando funciones

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
double randomDouble(double min, double max);
char randomChar();
void generarVoltajes(vector<double> &v);
void generarTemperaturas(vector<double> &t);
void generarCaracteres(vector<char> &c);
void generarAnios(vector<int> &a);
void generarVelocidades(vector<double> &v);
void generarDistancias(vector<double> &d);

int main() {
    srand(time(0));
    vector<double> voltajes, temperaturas, velocidades, distancias;
    vector<char> caracteres;
    vector<int> anios;

    generarVoltajes(voltajes);
    generarTemperaturas(temperaturas);
    generarCaracteres(caracteres);
    generarAnios(anios);
    generarVelocidades(velocidades);
    generarDistancias(distancias);

    cout << "Datos generados correctamente." << endl;
    return 0;
}
double randomDouble(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

char randomChar() {
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    return chars[rand() % chars.size()];
}

void generarVoltajes(vector<double> &v) {
    for (int i = 0; i < 100; i++) v.push_back(randomDouble(20.0, 220.0));
}

void generarTemperaturas(vector<double> &t) {
    for (int i = 0; i < 50; i++) t.push_back(randomDouble(0.0, 100.0));
}

void generarCaracteres(vector<char> &c) {
    for (int i = 0; i < 30; i++) c.push_back(randomChar());
}

void generarAnios(vector<int> &a) {
    for (int i = 0; i < 100; i++) a.push_back(1990 + rand() % (2025 - 1990 + 1));
}

void generarVelocidades(vector<double> &v) {
    for (int i = 0; i < 32; i++) v.push_back(randomDouble(10.0, 300.0));
}

void generarDistancias(vector<double> &d) {
    for (int i = 0; i < 1000; i++) d.push_back(randomDouble(1.0, 1000.0));
}

