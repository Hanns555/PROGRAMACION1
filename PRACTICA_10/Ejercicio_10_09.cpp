// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 04/12/2025
// Número de ejercicio: 9

/*
9. Cifrado de un archivo de texto (Cifrado César)
Descripción: Escribe un programa que lea un archivo mensaje.txt, realice
un cifrado César con un desplazamiento de 3 sobre el texto y guarde el
resultado en un archivo mensaje_cifrado.txt. El cifrado César desplaza cada
letra por un número fijo de posiciones en el alfabeto (por ejemplo, A se
convierte en D, B en E, etc.).
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Función principal que realiza el cifrado
void Cifrado_Cesar();

int main() {
    Cifrado_Cesar();
    return 0;
}

void Cifrado_Cesar() {
    ifstream archivo("mensaje.txt"); // Abrir archivo original
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo mensaje.txt" << endl;
        return;
    }

    ofstream archivoCifrado("mensaje_cifrado.txt"); // Archivo para guardar el mensaje cifrado
    if (!archivoCifrado.is_open()) {
        cout << "No se pudo crear el archivo mensaje_cifrado.txt" << endl;
        archivo.close();
        return;
    }

    string linea;
    int desplazamiento = 3; // Desplazamiento fijo del cifrado César

    // Leer archivo línea por línea
    while (getline(archivo, linea)) {
        for (int i = 0; i < linea.length(); i++) {
            char c = linea[i];

            // Cifrado solo para letras mayúsculas y minúsculas
            if (c >= 'A' && c <= 'Z') {
                c = ((c - 'A' + desplazamiento) % 26) + 'A';
            } else if (c >= 'a' && c <= 'z') {
                c = ((c - 'a' + desplazamiento) % 26) + 'a';
            }

            archivoCifrado << c; // Escribir el carácter cifrado
        }
        archivoCifrado << endl; // Saltar línea
    }

    archivo.close();       // Cerrar archivo original
    archivoCifrado.close(); // Cerrar archivo cifrado

    cout << "Archivo cifrado correctamente en mensaje_cifrado.txt" << endl;
}
