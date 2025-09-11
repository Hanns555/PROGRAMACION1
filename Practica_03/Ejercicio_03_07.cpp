// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 LP
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 11/09/2025 
// Ejercicio: 7
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//función que genera una edad aleatoria
int generarEdad();

//función que genera una altura aleatoria
int generarAltura();

//función que calcula el promedio de un conjunto de números
double calcularPromedio(int suma, int cantidad);

int main() {
    srand(time(0)); //inicializa los números aleatorios

    int N;
    cout << "Ingrese la cantidad de alumnos: ";
    cin >> N; //el usuario dice cuántos alumnos

    int sumaEdades = 0;
    int sumaAlturas = 0;
    int mayores18 = 0;
    int mas175 = 0;

    for (int i = 1; i <= N; ++i) {
        int edad = generarEdad();
        int altura = generarAltura();

        cout << "Alumno " << i << ": Edad = " << edad << ", Altura = " << altura << " cm" << endl;

        sumaEdades += edad; //sumamos las edades para luego calcular promedio
        sumaAlturas += altura; //sumamos las alturas

        if (edad > 18) mayores18++; //contamos cuántos son mayores de 18
        if (altura > 175) mas175++; //contamos cuántos miden más de 175
    }

    double edadMedia = calcularPromedio(sumaEdades, N);
    double alturaMedia = calcularPromedio(sumaAlturas, N);

    cout << "\nEdad media: " << edadMedia << " años" << endl;
    cout << "Altura media: " << alturaMedia << " cm" << endl;
    cout << "Alumnos mayores de 18 años: " << mayores18 << endl;
    cout << "Alumnos que miden más de 175 cm: " << mas175 << endl;

    return 0;
}

int generarEdad() {
    return rand() % 35 + 1; //edad entre 1 y 35
}

int generarAltura() {
    return rand() % 81 + 120; //altura entre 120 y 200
}

double calcularPromedio(int suma, int cantidad) {
    return static_cast<double>(suma) / cantidad; //calculamos promedio
}
