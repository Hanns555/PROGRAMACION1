// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 04/12/2025
// Número de ejercicio: 7

/*
7. Promedio de calificaciones por estudiante
Descripción: Escribe un programa que lea un archivo calificaciones.txt,
donde cada línea contiene el nombre de un estudiante seguido de varias
calificaciones. El programa debe calcular el promedio de cada estudiante y
escribirlo en un archivo promedios.txt en el formato Nombre Promedio.
Formato del archivo de entrada (calificaciones.txt):
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>
#include <fstream>

using namespace std;

void Calificaciones();

int main(){
    Calificaciones();
    return 0;
}

void Calificaciones() {
    ifstream archivo("calificaciones.txt"); // Archivo de entrada
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo calificaciones.txt" << endl;
        return;
    }

    ofstream archivoSalida("promedios.txt"); // Archivo de salida
    if (!archivoSalida.is_open()) {
        cout << "No se pudo crear el archivo promedios.txt" << endl;
        return;
    }

    string linea;
    // Leer línea por línea (cada estudiante)
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre;
        ss >> nombre; // Tomar la primera palabra como nombre del estudiante

        double nota, suma = 0;
        int contador = 0;

        // Leer todas las calificaciones restantes
        while (ss >> nota) {
            suma += nota;
            contador++;
        }

        double promedio = 0;
        if (contador > 0) {
            promedio = suma / contador;
        }

        // Escribir en archivo de salida
        archivoSalida << nombre << " " << promedio << endl;

        // Mostrar en consola
        cout << nombre << " -> Promedio: " << promedio << endl;
    }

    archivo.close();
    archivoSalida.close();
}