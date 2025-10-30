// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo.
// Fecha creación: 30/10/2025
// Número de ejercicio: 1

/*
1. Registro de una biblioteca
Descripción: Define una estructura llamada Libro con los siguientes campos:
    • titulo (cadena de caracteres)
    • autor (cadena de caracteres)
    • anio_publicacion (entero)
    • disponible (booleano, que indica si el libro está disponible o no)
Escribe un programa que permita al usuario registrar los datos de 1 libros, y luego
muestre los datos del libro, indicando si está o no disponible.
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

struct libro{
    char titulo [30];
    char nombre_autor [50];
    int anio_publicacion;
    bool disponible;
};

libro Ingresar_Datos();
void Mostar_Datos(libro book);

int main (){
    cout<<"-----SISTEMA DE REGISTRO-----"<<endl;
    Ingresar_Datos();
    return 0;
}

libro Ingresar_Datos(){
    libro book;
    string dato_d;
    cout<<"Ingrese el titulo del libro: ";
    cin.getline(book.titulo, 30);
    cout<<"Ingrese el autor del libro: ";
    cin.getline(book.nombre_autor, 30);
    cout<<"Ingrese el anio de publicacion: ";
    cin>>book.anio_publicacion;
    cin.ignore();
    cout<<"Ingrese si esta disponible el libro (Si o No): ";
    getline(cin,dato_d);
    if(dato_d == "Si"){
        book.disponible=true;
    }
    else{
        book.disponible=false;
    }
    Mostar_Datos(book);
}
void Mostar_Datos(libro book){
   cout<<"-----SE REGISTRO LOS SIGUIENTES DATOS-----"<<endl;
   cout<<"El titulo del libro es: "<<book.titulo<<endl;
   cout<<"El autor del libro es: "<<book.nombre_autor<<endl;
   cout<<"El anio de publicacion del libro es: "<<book.anio_publicacion<<endl;
   if(book.disponible){
   cout<<"El libro esta disponible"<<endl;
   }
   else{
   cout<<"El libro no esta disponible"<<endl;
   }
   
}