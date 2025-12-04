// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 04/12/2025
// Número de ejercicio: 6

/*
6. Filtrado de registros de temperatura
Descripción: Escribe un programa que lea un archivo de texto llamado
temperaturas.txt, donde cada línea contiene el nombre de una ciudad
seguido de su temperatura promedio del día. El programa debe generar un
archivo altas_temperaturas.txt que solo incluya las ciudades con
temperaturas superiores a N°C.
Formato del archivo de entrada (temperaturas.txt):
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

struct Departamentos
{
    char nombre [100];
    double temepratura;
};

void Temperaturas();
void Filtrar_Temperaturas(vector <Departamentos> Lista_Departamentos);

int main(){
    Temperaturas();
    return 0;
}

void Temperaturas(){
    ifstream archivo;
    string linea;
    vector <Departamentos> Lista_Departamentos;
    archivo.open("temperaturas.txt",ios::in);
    if (archivo.fail())
    {
        cout<<"No se logro abrir el archivo";
    }
    else {
        while (getline(archivo,linea))
        {
            Departamentos Datos_Departamentos;
            stringstream subcadenas(linea);
            subcadenas>> Datos_Departamentos.nombre>> Datos_Departamentos.temepratura;
            Lista_Departamentos.push_back(Datos_Departamentos);
        }
        Filtrar_Temperaturas( Lista_Departamentos);
    }
}

void Filtrar_Temperaturas(vector <Departamentos> Lista_Departamentos){
    double n;
    ofstream archivo;
    archivo.open("altas_temperaturas.txt", ios::out);
    if (archivo.fail())
    {
    cout<<"No se creo el archivo"<<endl;
    }
    cout<<"Ingrese la temperatura que quiere filtrar: ";
    cin >>n;
    for (int i = 0; i < Lista_Departamentos.size(); i++)
    {
        if (n<Lista_Departamentos[i].temepratura)
        {
           archivo<<Lista_Departamentos[i].nombre<<"   "<<Lista_Departamentos[i].temepratura<<endl;     
        }
    }
}
