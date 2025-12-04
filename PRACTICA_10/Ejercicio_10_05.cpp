// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 04/12/2025
// Número de ejercicio: 5
/*
5. Actualizar datos en un archivo
Descripción: Escribe un programa que permita actualizar un archivo de
texto llamado productos.txt, el cual contiene una lista de productos y sus
precios. Cada línea del archivo tiene el formato Producto Precio (por
ejemplo, Manzana 1.50). El programa debe permitir al usuario ingresar el
nombre de un producto y el nuevo precio, y actualizar ese precio en el
archivo. Si el producto no se encuentra, debe indicar que no existe.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

struct Producto{
   char nombre[100];
   double precio;
};

void Actualizar_Archivo(vector <Producto> Lista_Productos);
void Actualizar_Datos();

int main(){
  Actualizar_Datos();
  return 0;   
}

void Actualizar_Datos(){
    ifstream archivo;
    string texto;
    vector <Producto> Lista_Productos;
    archivo.open("productos.txt", ios::in);
    if (archivo.fail())
    {
        cout<< "Archivo no encontrado"<<endl;
    }
    else
    {
      while (getline(archivo, texto))
      {
        stringstream subcadenas(texto);
        Producto Datos_productos;
        subcadenas>> Datos_productos.nombre>> Datos_productos.precio;
            // DATOS COMO VECTOR STRUCTURA
        Lista_Productos.push_back(Datos_productos);
      }
      cout<<"Ingrese el producto que quiere actualizar su precio: ";
      char busqueda[100];
      int contador=0;
      cin.getline(busqueda,100);
      for (int i = 0; i < Lista_Productos.size(); i++)
      {
        if (!strcmp(busqueda, Lista_Productos[i].nombre))
        {
            cout<<"Ingrese el nuevo precio: ";
            cin >> Lista_Productos[i].precio;
        }
        else {
            contador++;
        }
      }
      if (contador == Lista_Productos.size())
      {
        cout<<"Producto no encontrado"<<endl;
      }
      
      Actualizar_Archivo(Lista_Productos);
    }
    archivo.close();
}
void Actualizar_Archivo(vector <Producto> Lista_Productos){
    ofstream archivo;
    archivo.open("productos.txt", ios::out);
    if (archivo.fail())
    {
        cout<< "Archivo no encontrado"<<endl;
    }
    else {
        for (int i = 0; i < Lista_Productos.size(); i++)
        {
            archivo << Lista_Productos[i].nombre<<"   "<<Lista_Productos[i].precio<<endl;
        }
    }
    archivo.close();
}