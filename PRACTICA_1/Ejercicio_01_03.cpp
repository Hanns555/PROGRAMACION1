// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 24/08/2025 
// Número de ejercicio: 3
#include <iostream>
using namespace std;

int main() {
    //De esta forma se debine las variables b,h,area como flotantes
    float base, altura, area; 
    cout << "Ingrese la base de tu triangulo: ";
    cin >> base;
    cout << "Ingrese la altura de tu triangulo: ";
    cin >> altura;
    //Definimos area con la formula de calcular area de un triangulo
    area = (base * altura) / 2; 
    cout << "El area de tu triangulo es: " << area << endl;
    return 0;
}
