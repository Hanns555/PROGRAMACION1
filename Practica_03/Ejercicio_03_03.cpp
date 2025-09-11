// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 LP
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 11/09/2025 
// Ejercicio: 3
#include <iostream>
using namespace std;

bool esCapicua(int numero);

int main() {
    int num;
    cout << "Ingresa un número: ";
    cin >> num; //el usuario mete un número

    if (esCapicua(num)) {
        cout << num << " es capicúa." << endl; //cuando el número al revés es igual
    } else {
        cout << num << " no es capicúa." << endl; //cuando no coincide
    }

    return 0;
}

bool esCapicua(int numero) {
    int original = numero;
    int invertido = 0;

    while (numero > 0) {
        int digito = numero % 10; //agarra el último dígito
        invertido = invertido * 10 + digito;
        numero /= 10;
    }

    return original == invertido;
}