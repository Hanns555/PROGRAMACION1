// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 04/12/2025
// Número de ejercicio: 2
/*
2. Contador de palabras en un archivo
Descripción: Escribe un programa que lea un archivo de texto llamado
texto.txt y cuente cuántas palabras contiene. Una "palabra" se define como
cualquier secuencia de caracteres separada por espacios o saltos de línea.
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

int Leer();

int main(){
    cout<< "LA CANTIDAD DE PALABRAS DEL ARCVHIVO texto.txt SON: "<<Leer()<<endl;
    return 0;
}

int Leer(){
    string palabra;
    string linea;
    ifstream archivo;
    int p=0;
    archivo.open("texto.txt", ios::in);
    if(archivo.fail()){
        cout<<"Archivo no se logro abrir"<<endl;
    }
    else{
        while (getline(archivo,linea))
        {
            for(int i = 0; i < linea.length(); i++) {
            if ((linea[i] >= 'A' && linea[i] <= 'Z') || (linea[i] >= 'a' && linea[i] <= 'z'))
            {
                palabra+=linea[i];
            }
            if(linea[i] == ' '){
                if(palabra.length() > 0){
                    p++;
                    palabra = "";
                }
            }
            }
            if(palabra.length() > 0){
            p++;
            }
        }
        archivo.close();
         return p;
    }
}