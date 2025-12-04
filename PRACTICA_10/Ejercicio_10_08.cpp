// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 04/12/2025
// Número de ejercicio: 8

/*
8. Contador de líneas, palabras y caracteres
Descripción: Escribe un programa que lea un archivo de texto llamado
documento.txt y cuente el número total de líneas, palabras y caracteres. Al
final, el programa debe mostrar estos totales en la consola.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Funcion principal que realiza el conteo
void Contador_Archivo();

int main() {
    Contador_Archivo();
    return 0;
}

void Contador_Archivo() {
    ifstream archivo("documento.txt"); // Abrir el archivo en modo lectura
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo documento.txt" << endl;
        return;
    }

    string linea;
    int numLineas = 0;     // Contador de lineas
    int numPalabras = 0;   // Contador de palabras
    int numCaracteres = 0; // Contador de caracteres

    // Leer el archivo línea por línea
    while (getline(archivo, linea)) {
        numLineas++;                // Contar cada linea leida
        numCaracteres += linea.length(); // Sumar cantidad de caracteres de la linea

        stringstream ss(linea);     // Permite separar las palabras de la linea
        string palabra;
        while (ss >> palabra) {     // Leer palabra por palabra
            numPalabras++;          // Contar cada palabra
        }
    }

    archivo.close(); // Cerrar archivo

    // Mostrar resultados
    cout << "Numero de lineas: " << numLineas << endl;
    cout << "Numero de palabras: " << numPalabras << endl;
    cout << "Numero de caracteres: " << numCaracteres << endl;
}
