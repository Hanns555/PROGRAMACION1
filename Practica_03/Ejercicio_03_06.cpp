// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 LP
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 11/09/2025 
// Ejercicio: 6
#include <iostream>
using namespace std;

//función que revisa si un año es bisiesto
bool esBisiesto(int anio);

//función que devuelve cuántos días tiene un mes en un año
int diasDelMes(int anio, int mes);

int main() {
    int anio, mes;
    cout << "Ingresa el año: ";
    cin >> anio; //el usuario mete el año
    cout << "Ingresa el mes (1-12): ";
    cin >> mes; //el usuario mete el mes en número

    int dias = diasDelMes(anio, mes); //llamamos a la función que devuelve los días
    if (dias == -1) {
        cout << "Mes inválido." << endl; //cuando el número no es de 1 a 12
    } else {
        cout << "El mes " << mes << " del año " << anio << " tiene " << dias << " días." << endl;
    }

    return 0;
}

//un año es bisiesto si cumple estas reglas
bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

//según el mes, devolvemos los días que tiene
int diasDelMes(int anio, int mes) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31; //meses con 31 días
        case 4: case 6: case 9: case 11:
            return 30; //meses con 30 días
        case 2:
            return esBisiesto(anio) ? 29 : 28; //febrero depende si es bisiesto
        default:
            return -1; //si el mes no existe
    }
}