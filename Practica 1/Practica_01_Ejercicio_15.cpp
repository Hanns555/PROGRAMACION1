// Materia: Programación I, Paralelo 4 
// Autor: Willy Edwin Tenorio Palza 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 15 
#include <iostream>
using namespace std;
int main() {
    int notas;
    float nota, promedio, suma=0;
    cout << "Cuantas notas ingresara al programa?: ";
    cin >> notas; //Se coloca esto para hacerle saber cuantas notas ingresaran 
    for (int i = 1; i <= notas; i++) {
        cout << "Ingrese la nota " << i << ": ";
        cin >> nota;
        suma += nota; // Se suma los datos ingresado
    }
    promedio = suma / notas; 
    cout << "El promedio general es: " << promedio << endl;
    return 0;

}
