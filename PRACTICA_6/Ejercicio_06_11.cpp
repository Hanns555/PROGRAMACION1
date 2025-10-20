// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 20/10/2024 
// Número de ejercicio: 11
/*
11. Escribe un programa que divida una cadena en tokens (subcadenas) separadas por un 
delimitador. Por ejemplo, dividir una oración en palabras. 
// Entrada: "Esto,es,una,cadena,separada,por,comas", delimitador: ','  
// Salida:  
// Esto  
// es  
// una  
// cadena  
// separada  
// por  
// comas 
*/  
#include <iostream>
#include <sstream>

using namespace std;

void Eliminar_comas(string&frase);

int main (){
    string frase;
    string palabra;
    cout<<"Ingrese una frase separada por comas: ";
    getline(cin, frase);
    Eliminar_comas(frase);
    stringstream ss(frase);
    while (ss>>palabra)
    {
        cout<< palabra<<endl;
    }
    return 0;
}

void Eliminar_comas(string&frase){
   char coma=',';
   char coma2=' ';
   for (int i=0; i<frase.size(); i++)
   {
        if (frase[i]==coma)
        {
           frase[i]=coma2;
        }
   }
}