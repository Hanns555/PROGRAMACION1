// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 04/12/2025
// Número de ejercicio: 2
/*
3. Almacenamiento de registros de estudiantes
Descripción: Escribe un programa que permita registrar la información de
varios estudiantes en un archivo de texto llamado estudiantes.txt. Cada
estudiante debe tener un nombre, una edad y un promedio de
calificaciones. Luego, el programa debe poder leer el archivo y mostrar toda
la información de los estudiantes en un formato organizado.
Formato del archivo:
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

struct Estudiantes{
   char nombre[100];
   int edad;
   double promedio;
};

    vector <Estudiantes> Registrar_Estudiantes();
    void archivotxt(vector <Estudiantes> Registro_Global_Estudiantes);
    void Leer( );

int main(){
    vector<Estudiantes> Lista_Completa;
    Lista_Completa= Registrar_Estudiantes();
    archivotxt(Lista_Completa);
    Leer( );
    return 0;
}

vector <Estudiantes> Registrar_Estudiantes(){
    int n;
    Estudiantes Datos_Estudiante;
    vector <Estudiantes> Registro_Global_Estudiantes;
    cout<<"Ingrese el numero de estudiantes a registrar: ";
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout<<"DATOS ESTUDIANTE ["<<i+1<<"]"<<endl;
        cout<<"===================="<<endl;
        cout<<"Ingrese el nombre del estudiante: ";
        cin.getline(Datos_Estudiante.nombre, 100);
        cout<<"Ingrese la edad del estudiante: ";
        cin>> Datos_Estudiante.edad;
        cout<<"Ingrese el promedio del estudiante: ";
        cin>> Datos_Estudiante.promedio;
        cin.ignore();
        Registro_Global_Estudiantes.push_back(Datos_Estudiante);
    }
    return Registro_Global_Estudiantes;
}

void archivotxt(vector <Estudiantes> Registro_Global_Estudiantes){
    ofstream archivo;
    archivo.open("estudiantes.txt", ios::out);
    if (archivo.fail())
    {
        cout<<"No se logro crear el archivo";
    }
    else
    {
        for (int i = 0; i < Registro_Global_Estudiantes.size(); i++)
        {
         archivo<<"Datos estudiante ["<<i+1<<"]"<<endl;
         archivo<<"======================="<<endl;
         archivo<<"Nombre: "<<Registro_Global_Estudiantes[i].nombre<<endl;  
         archivo<<"Edad: "<<Registro_Global_Estudiantes[i].edad<<endl;   
         archivo<<"Promedio: "<<Registro_Global_Estudiantes[i].promedio<<endl;    
        }
    }
    archivo.close();
}

void Leer( ){
    system("cls");
    ifstream archivo;
    string linea;
    vector <string> mostrar;
    archivo.open("estudiantes.txt", ios::in);
    if (archivo.fail())
    {
      cout<<"El archivo no se logro abrir"<<endl;
    }
    else{
        while (getline(archivo,linea))
        {
            mostrar.push_back(linea);
        }
        for (string i : mostrar)
            {
                cout<<i<<endl;
            }
    }
    archivo.close();
}