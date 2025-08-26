// Materia: Programación I, Paralelo 4 
// Autor: Willy Edwin Tenorio Palza 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 24/08/2025 
// Número de ejercicio: 2
#include <iostream>
using namespace std;

int main() {
    float b, h, area; //De esta forma se debine las variables b,h,area como flotantes
    cout << "Ingrese la base de tu triangulo: ";
    cin >> b;
    cout << "Ingrese la altura de tu triangulo: ";
    cin >> h;
    area = (b * h) / 2; //Definimos area con la formula de calcular area de un triangulo
    cout << "El area de tu triangulo es: " << area << endl;
    return 0;
}
