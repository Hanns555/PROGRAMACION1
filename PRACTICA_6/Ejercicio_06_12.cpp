// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 20/10/2024 
// Número de ejercicio: 12
/*
12. Escribe una función que reciba un texto y retorne verdadero o falso (Boolean) según 
sean o no palíndromos. 
Un Palíndromo es una palabra o expresión que es igual si se lee de izquierda a derecha 
que de derecha a izquierda. NO se tienen en cuenta los espacios, signos de puntuación y 
tildes.  
Ejemplo: Ana lleva al oso la avellana.  
*/
#include <iostream>
#include <string>

using namespace std;

bool esPalindromo(string texto);
char minusculaSinTilde(char c);

int main() {
    string frase;
    cout << "Ingrese una frase: ";
    getline(cin, frase);

    if (esPalindromo(frase))
        cout << "Es un palindromo." << endl;
    else
        cout << "No es un palindromo." << endl;

    return 0;
}

bool esPalindromo(string texto) {
    string limpio = "";

    // Limpiar la frase: quitar espacios, tildes, signos, etc.
    for (int i = 0; i < texto.size(); i++) {
        char c = texto[i];
        // Convertir a minúscula sin usar tolower()
        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }
        // Reemplazar vocales con tilde por sin tilde
        c = minusculaSinTilde(c);
        // Solo conservar letras
        if (c >= 'a' && c <= 'z') {
            limpio += c;
        }
    }
    // Comprobar si es palíndromo
    int n = limpio.size();
    for (int i = 0; i < n / 2; i++) {
        if (limpio[i] != limpio[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

// Función para quitar tildes de vocales
char minusculaSinTilde(char c) {
    switch (c) {
        case 'á': 
        return 'a';
        case 'é': 
        return 'e';
        case 'í': 
        return 'i';
        case 'ó': 
        return 'o';
        case 'ú': 
        return 'u';
        default: 
        return c;
    }
}
