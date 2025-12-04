// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 09/12/2025
// Número de ejercicio: 7
/*
7. Inventario de productos en una tienda
Descripción: Define una estructura llamada Producto con los siguientes campos:
• nombre (cadena de caracteres)
• codigo (cadena de caracteres)
• precio (decimal)
• cantidad_en_inventario (entero)
• observaciones (cadena de caracteres)
Luego, escribe un programa que permita:
• Registrar N productos en el inventario.
• Mostrar el producto más caro en el inventario.
• Mostrar la cantidad total de productos en inventario.
• Si un producto se encuentra con cantidad_en_inventario menor a 5, en el
campo observaciones debe tener un mensaje de advertencia “PRUDUCTO
CON BAJA CANTIDAD DE INVENTARIO”.
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Producto
{
        char nombre [100];
        char codigo [100];
        double precio ;
        int cantidad_en_inventario;
        char observaciones [100];
};

vector <Producto> Registro_producto();
void Menu (vector <Producto> Listado_Productos_Global);
void Mostrar_Productos(Producto Datos_Producto);
void Mostrar_Producto_Caro(vector <Producto> Listado_Productos_Global);
void Mostrar_CantiadTotal_Productos(vector <Producto> Listado_Productos_Global);

int main()
{
    vector <Producto> Listado_Global;
    Listado_Global = Registro_producto();
    Menu (Listado_Global);
    return 0;
}

vector <Producto> Registro_producto()
{
    system ("cls");
    char Mensaje1 [100]= {"PRUDUCTO CON BAJA CANTIDAD DE INVENTARIO"}; 
    char Mensaje2 [100]= {"NINGUNA"}; 
    vector <Producto> Listado_Productos_Global;
    Producto Datos_Producto;
    int a;
    cout<< "Ingrese la cantidad de productos que desea registrar: ";
    cin >> a;
    cin.ignore();
    for (int i = 0; i < a; i++)
    {
        cout << "Ingrese el nombre del producto: ";
        cin.getline(Datos_Producto.nombre,100);
        cout << "Ingrese el codigo del producto: ";
        cin.getline(Datos_Producto.codigo,100);
        cout << "Ingrese el precio del producto: ";
        cin >> Datos_Producto.precio;
        cout << "Ingrese la cantidad de producto: ";
        cin >> Datos_Producto.cantidad_en_inventario;
        cin.ignore();
        if(Datos_Producto.cantidad_en_inventario<5)
        {
          strcpy(Datos_Producto.observaciones, Mensaje1);
        }
        else
        {
          strcpy(Datos_Producto.observaciones, Mensaje2);
        }
        Listado_Productos_Global.push_back(Datos_Producto);
    }
    return Listado_Productos_Global;
}

void Menu (vector <Producto> Listado_Productos_Global)
{
    system("cls");
    int condition;
    cout<<"MENU"<<endl;
    do
    {
    cout<<"1. Mostrar el producto mas caro en el inventario."<<endl;
    cout<<"2. Mostrar la cantidad total de productos en inventario."<<endl;
    cout<<"0. Salir"<<endl;
    cin >> condition;
    cin.ignore();
    switch (condition)
    {
    case 1:
        system ("cls");
        Mostrar_Producto_Caro(Listado_Productos_Global);
        break;
    case 2:
        system ("cls");
        Mostrar_CantiadTotal_Productos(Listado_Productos_Global);
        break;
    }
    } while (condition != 0);
}

void Mostrar_Producto_Caro(vector <Producto> Listado_Productos_Global)
{
    Producto Caro_Producto;
    double Precio = 0.0;
    for (int i = 0; i < Listado_Productos_Global.size(); i++)
    {
        if (Precio < Listado_Productos_Global[i].precio)
        {
          Precio = Listado_Productos_Global[i].precio;
          Caro_Producto = Listado_Productos_Global[i];
        }
    }
    Mostrar_Productos(Caro_Producto);
}

void Mostrar_Productos(Producto Datos_Producto){
   cout<<"El nombre del producto es: "<< Datos_Producto.nombre<<endl;
   cout<<"El codigo del producto es: "<< Datos_Producto.codigo<<endl;
   cout<<"El precio del producto es: "<< Datos_Producto.precio<<endl;
   cout<<"La cantidad del producto es: "<< Datos_Producto.cantidad_en_inventario<<endl;
   cout<<"La observacion del producto es: "<< Datos_Producto.observaciones<<endl;
}

void Mostrar_CantiadTotal_Productos(vector <Producto> Listado_Productos_Global){
  int suma=0;
    for (int i = 0; i < Listado_Productos_Global.size(); i++)
  {
    suma += Listado_Productos_Global[i].cantidad_en_inventario;
  }
    cout <<"La cantidad de productos en el inventario es :"<<suma<<endl;
}
