// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 20/10/2024 
// Número de ejercicio: 10
/*
10. Escribe un programa que elimine todos los dígitos de una cadena. 
        // Entrada: "abc123def456"  
        // Salida: "abcdef" 
*/  

#include <iostream>
#include <string>
#include <cctype>  // para isalpha()
using namespace std;

void eliminarnumeros(string texto);

int main() {
    system("cls");
    string texto;
    cout << "Ingrese un texto: ";
    getline(cin, texto);  
    eliminarnumeros(texto);
    return 0;
}

// Función que verifica si un texto es palíndromo
void eliminarnumeros(string texto) {
    string limpio = "";
    for (char c : texto) {
        if (isalpha(c)) { 
            limpio += c;
        }
    }
    cout<<"El texto sin numeros es: "<<limpio;
}