// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 03/12/2025
// Número de ejercicio: 1
/*
1. Escritura y lectura básica de archivos
Descripción: Escribe un programa que pida al usuario ingresar una lista de
nombres y guarde cada nombre en un archivo de texto llamado
nombres.txt. Después, el programa debe leer el archivo y mostrar todos los
nombres en la consola.
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

void Resgistro();
void lectura();

int main()
{
    Resgistro();
    lectura();
    return 0;
}

void Resgistro()
{
  ofstream archivo;
  int n=0;
  vector <string> Lista_Nombre;
  char Nombre [100];
  archivo.open("nombres.txt", ios::out);
  if (archivo.fail())
  {
    cout<<"Archivo no se logro abrir";
  }
  else
  {
    cout<< "Ingrese el numero de nombres que desea guardar: ";
    cin >>n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout<<"NOMBRE "<<i+1<<endl;
        cout<<"Ingrese el nombre: ";
        cin.getline(Nombre,100);
        Lista_Nombre.push_back(Nombre);
        cout<<endl;
    }
    for (int i = 0; i < Lista_Nombre.size(); i++)
    {
        archivo<<"NOMBRE "<<i+1<<endl;
        archivo<<"====== "<<endl;
        archivo<<Lista_Nombre[i].c_str()<<endl;
    }
    archivo.close();
  }
}

void lectura(){
    vector <string> Nombres;
    string linea;
    ifstream archivo;
    archivo.open("nombres.txt", ios::in);
    if (archivo.fail())
  {
    cout<<"Archivo no se logro abrir";
  }
    else
    {
    while(getline(archivo,linea))
    {
      Nombres.push_back(linea);
    }
    for (string i : Nombres)
    {
        cout << i<<endl;
    }
    }
}