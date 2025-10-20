// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 3
/*
3. Se tiene 3 vectores de 10 elementos cada uno: 
    • Vector de nombres. 
    • Vector Apellidos 
    • Vector de Edad 
    Seleccione 1 nombre, 1 apellido y una edad al azar y despliegue en pantalla. 
    Esto debe realizar N veces. 
    //NOMBRES: Ana Luis María Carlos Sofía Diego Valeria Martín Lucía Pablo
    //APELLIDOS: García López Martínez Silva Paco Pérez Sánchez Ramírez Torres Flores
*/    
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Declaración de funciones
void leerNombres(vector<string>& nombres);
void leerApellidos(vector<string>& apellidos);
void generarEdades(vector<int>& edades, int cantidad);
void mostrarResultados(const vector<string>& nombres, const vector<string>& apellidos, const vector<int>& edades, int n);

int main() {
    system("cls");
    srand(time(0));
    vector<string> nombres;
    vector<string> apellidos;
    vector<int> edades;
    int n;
    leerNombres(nombres);
    leerApellidos(apellidos);
    generarEdades(edades, 10);
    system("cls");
    cout << "Ingrese la cantidad de nombres a generar (max. 10): ";
    cin >> n;
    cout << "\tNombre\tApellido\tEdad" << endl;
    mostrarResultados(nombres, apellidos, edades, n);
    return 0;
}

//Funcion para convertir de string a vector
void leerNombres(vector<string>& nombres) {
    string linea;
    string datos;
    cout << "Ingrese 10 nombres: ";
    getline(cin, linea);
    stringstream ss(linea);
    while (ss >> datos) {
        nombres.push_back(datos);
    }
}

//Funcion para convertir de string a vector
void leerApellidos(vector<string>& apellidos) {
    string linea;
    string datos;
    cout << "Ingrese 10 apellidos: ";
    getline(cin, linea);
    stringstream ss(linea);
    while (ss >> datos) {
        apellidos.push_back(datos);
    }
}

//Genera edades
void generarEdades(vector<int>& edades, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        edades.push_back(rand() % 100 + 1);
    }
}

//Muestra Resultado
void mostrarResultados(const vector<string>& nombres, const vector<string>& apellidos, const vector<int>& edades, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\t" << nombres[rand() % 10] 
             << "\t" << apellidos[rand() % 10] 
             << "\t\t" << edades[rand() % 10] << endl;
    }
}