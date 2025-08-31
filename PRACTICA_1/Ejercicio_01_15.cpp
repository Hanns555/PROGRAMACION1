// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 15 
#include <iostream>
using namespace std;
int main() {
    int numero_notas;
    float notas, promedio, suma=0;
    cout << "Numero de notas que desea ingresar: ";
    cin >> numero_notas; //Se coloca esto para hacerle saber cuantas notas ingresaran 
    for (int i = 1; i <= numero_notas; i++) {
        cout << "Ingrese la nota " << i << ": ";
        cin >> notas;
        suma += notas; // Se suma los datos ingresado
    }
    promedio = suma / numero_notas; 
    cout << "El promedio general es: " << promedio << endl;
    return 0;

}
