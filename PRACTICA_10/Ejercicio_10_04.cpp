// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 04/12/2025
// Número de ejercicio: 4
/*
4. Búsqueda de texto en un archivo
Descripción: Escribe un programa que lea un archivo de texto llamado
datos.txt y permita al usuario buscar una palabra o frase específica. El
programa debe contar y mostrar cuántas veces aparece esa palabra o frase
en el archivo.
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void Contador_Palabras();

int main() {
    Contador_Palabras();
    return 0;
}

void Contador_Palabras(){
    ifstream archivo("datos.txt");
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo datos.txt"<<endl;
    }
    string busqueda;
    string linea;
    string palabra;
    vector <string> Partes_Linea;
    int contador = 0;
    cout << "Ingrese la palabra o frase a buscar: ";
    getline(cin, busqueda);
    while (getline(archivo, linea)) {
        // Buscar dentro de la línea todas las apariciones
        stringstream subcadenas(linea);
        while (subcadenas >> palabra) {
            Partes_Linea.push_back(palabra);
        }
    }
    for (int i = 0; i < Partes_Linea.size(); i++)
    {
        if (busqueda == Partes_Linea[i])
        {
          contador++;  
        }
    }
    archivo.close();
    cout << "La palabra " << busqueda 
              << " aparece " << contador << " veces en el archivo";
}
