// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Siva Pardo 
// Fecha creación: 03/12/2025 
// Número de ejercicio: 5
/*
5. Sistema de gestión de películas 
Descripción: Define una estructura llamada Pelicula con los siguientes campos: 
• titulo (cadena de caracteres) 
• director (cadena de caracteres) 
• duracion (entero, en minutos) 
• anio_estreno (entero) 
• genero (cadena de caracteres) 
Escribe un programa que permita al usuario registrar N películas en un arreglo de 
estructuras y luego realice lo siguiente: 
• Mostrar todas las películas de un género específico introducido por el usuario. 
• Mostrar todas las películas dirigidas por un director específico introducido por 
el usuario. 
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <set>

using namespace std;

struct Pelicula
{
   char titulo [100]; 
   char director [100]; 
   int duracion;
   int anio_estreno;
   char genero [100]; 
};

vector <Pelicula> Registro_Peliculas();
void Mostrar_por_Genero(vector <Pelicula>  Listado_Global_Peliculas);
void Mostrar_por_Director(vector <Pelicula>  Listado_Global_Peliculas);

int main()
{ 
    int a;
    vector <Pelicula> LISTA_COMPLETA = Registro_Peliculas();
    cout<< "Seleccione un filtro: "<<endl;
    cout<< "1. Filtrar Por Genero"<<endl;
    cout<< "2. Filtrar Por Director"<<endl;
    cin>> a;
    if (a==1)
    {
    Mostrar_por_Genero(LISTA_COMPLETA);
    }
    else
    {
    Mostrar_por_Director(LISTA_COMPLETA);
    }
    return 0;
}

vector <Pelicula> Registro_Peliculas()
{
    system("cls");
    vector <Pelicula>  Listado_Global_Peliculas;
    Pelicula Datos_Pelicula;
    int n;
    cout<<"Ingrese la cantidad de peliculas que desea resgitrar: ";
    cin>> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout <<"RESGITRO DE DATOS DE LA PELICULA ["<<i+1<<"]"<<endl;
        cout <<"========================================"<<endl;
        cout <<"Ingrese el titulo de la pelicula: ";
        cin.getline (Datos_Pelicula.titulo, 100);
        cout <<"Ingrese el nombre del director de la pelicula: ";
        cin.getline (Datos_Pelicula.director, 100);
        cout <<"Ingrese la duracion de la pelicula: ";
        cin >> Datos_Pelicula.duracion;
        cout <<"Ingrese el anio de publicacion de la pelicula: ";
        cin >> Datos_Pelicula.anio_estreno;
        cin.ignore();
        cout <<"Ingrese el genero d la pelicula: ";
        cin.getline (Datos_Pelicula.genero, 100);
        Listado_Global_Peliculas.push_back(Datos_Pelicula);
    }
    return Listado_Global_Peliculas;
}

void Mostrar_por_Genero(vector <Pelicula>  Listado_Global_Peliculas)
{
    int i=1, eleccion;
    set <string> Generos_Disponibles;
    vector <string> Generos_Disponibles_Opcion;
    for ( int i =0 ; i< Listado_Global_Peliculas.size(); i++)
    {
        Generos_Disponibles.insert(Listado_Global_Peliculas[i].genero);
    }
    for (string i : Generos_Disponibles)
    {
        Generos_Disponibles_Opcion.push_back(i);
    }
    cout<< "Generos Disponibles"<<endl;
    for ( string opcion : Generos_Disponibles_Opcion)
    {
        cout<< i<<". "<<opcion<<endl;
        i++;
    }
    cout<< "Seeccion una opcion: ";
    cin >> eleccion;
    for (int i = 0; i < Listado_Global_Peliculas.size(); i++)
    {
    if (Listado_Global_Peliculas[i].genero == Generos_Disponibles_Opcion[eleccion-1])
    {
        cout<< "PELICULAS DE "<< Generos_Disponibles_Opcion[eleccion-1]<<endl;
        cout<< "==================="<<endl;
        cout <<"El titulo de la pelicula es: "<< Listado_Global_Peliculas[i].titulo<<endl;
        cout <<"El nombre del director de la pelicula es: "<< Listado_Global_Peliculas[i].director<<endl;;
        cout <<"La duracion de la pelicula es: "<< Listado_Global_Peliculas[i].duracion<<endl;
        cout <<"El anio de publicacion de la pelicula es: "<< Listado_Global_Peliculas[i].anio_estreno<<endl;
        cout <<"El genero de la pelicula es: "<< Listado_Global_Peliculas[i].genero<<endl;
    }
    }
}
void Mostrar_por_Director(vector <Pelicula>  Listado_Global_Peliculas)
{
    int i=1, eleccion;
    set <string> Directores_Disponibles;
    vector <string> Directores_Disponibles_Opcion;
    for ( int i =0 ; i< Listado_Global_Peliculas.size(); i++)
    {
        Directores_Disponibles.insert(Listado_Global_Peliculas[i].director);
    }
    for (string i : Directores_Disponibles)
    {
        Directores_Disponibles_Opcion.push_back(i);
    }
    cout<< "Peliculas Dirigidas por: "<<endl;
    for ( string opcion : Directores_Disponibles_Opcion)
    {
        cout<< i<<". "<<opcion<<endl;
        i++;
    }
    cout<< "Seeccion una opcion: ";
    cin >> eleccion;
    for (int i = 0; i < Listado_Global_Peliculas.size(); i++)
    {
    if (Listado_Global_Peliculas[i].director == Directores_Disponibles_Opcion[eleccion-1])
    {
        cout<< "PELICULAS DE "<< Directores_Disponibles_Opcion[eleccion-1]<<endl;
        cout<< "==================="<<endl;
        cout <<"El titulo de la pelicula es: "<< Listado_Global_Peliculas[i].titulo<<endl;
        cout <<"El nombre del director de la pelicula es: "<< Listado_Global_Peliculas[i].director<<endl;;
        cout <<"La duracion de la pelicula es: "<< Listado_Global_Peliculas[i].duracion<<endl;
        cout <<"El anio de publicacion de la pelicula es: "<< Listado_Global_Peliculas[i].anio_estreno<<endl;
        cout <<"El genero de la pelicula es: "<< Listado_Global_Peliculas[i].genero<<endl;
    }
    }
}