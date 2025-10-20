// Materia: Programación I, Paralelo 1
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 20/10/2024
// Número de ejercicio: 13
/*
13. Crea una función que reciba un String de cualquier tipo y se encargue de poner en 
mayúscula la primera letra de cada palabra. 
No se pueden utilizar operaciones del lenguaje que lo resuelvan directamente.
*/
#include <iostream>
#include <string>
using namespace std;

void capitalizar(string &frase);

int main() {
    string texto;
    cout << "Ingrese una frase: ";
    getline(cin, texto);

    capitalizar(texto);

    cout << "Frase capitalizada: " << texto << endl;
    return 0;
}

void capitalizar(string &frase) {
    bool nuevaPalabra = true;  // indica si estamos al inicio de una palabra

    for (int i = 0; i < frase.size(); i++) {
        char c = frase[i];

        // si es una letra minúscula y estamos al inicio de una palabra
        if (nuevaPalabra && c >= 'a' && c <= 'z') {
            frase[i] = c - 32;  // convertir a mayúscula (ASCII)
            nuevaPalabra = false;  // ya no estamos al inicio
        } 
    }
}
