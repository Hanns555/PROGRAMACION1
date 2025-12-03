// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Siva Pardo 
// Fecha creación: 03/12/2025 
// Número de ejercicio: 1
/*
1. Registro de una biblioteca 
Descripción: 
Define una estructura llamada Libro con los siguientes campos: 
• titulo (cadena de caracteres) 
• autor (cadena de caracteres) 
• anio_publicacion (entero) 
• disponible (booleano, que indica si el libro está disponible o no) 
Escribe un programa que permita al usuario registrar los datos de 1 libros, y luego 
muestre los datos del libro, indicando si está o no disponible.
*/
#include <iostream>
#include <vector>

using namespace std;

struct Libro
{
    char Titulo[100];
    char Autor [100];
    int Anio_Publicacion;
    bool Disponible;
};

Libro Registro_Libro();
void Mostrar_Libro(Libro& Datos_Libro);

//Datos Estrcutura
Libro Datos_Libro;

int main()
{
    system("cls");
    Datos_Libro = Registro_Libro();
    system("cls");
    Mostrar_Libro(Datos_Libro);
    return 0;
}

Libro Registro_Libro()
{
    Libro Datos_Libro;
    int Opcion;
    cout<<"\nIngrese el titulo del libro: ";
    cin.getline(Datos_Libro.Titulo,100);
    cout<<"\nIngrese el autor del libro: ";
    cin.getline(Datos_Libro.Autor,100);
    cout<<"\nIngrese el anio de publicacion del libro: ";
    cin>>Datos_Libro.Anio_Publicacion;
    cout<<"\nIngrese la disponiblidad del libro:"<<endl;
    cout<<"1. Disponible"<<endl;
    cout<<"2. No Disponible"<<endl;
    cin>> Opcion;
    if(Opcion == 1) 
    {
        Datos_Libro.Disponible=true;
    }
    else
    {
        Datos_Libro.Disponible=false;
    }
    return Datos_Libro;
}

void Mostrar_Libro(Libro& Datos_Libro){
    cout<<"RESGISTRO COMPLETADO"<<endl;
    cout<<"===================="<<endl;
    cout<<"El titulo del libro es: "<<Datos_Libro.Titulo<<endl;
    cout<<"El autor del libro es: "<<Datos_Libro.Autor<<endl;
    cout<<"El anio de publicacion del libro es: "<<Datos_Libro.Anio_Publicacion<<endl;
    if (Datos_Libro.Disponible)
    {
    cout<<"Libro disponible"<<endl;
    }
    else
    {
    cout<<"Libro no disponible"<<endl;
    }
}