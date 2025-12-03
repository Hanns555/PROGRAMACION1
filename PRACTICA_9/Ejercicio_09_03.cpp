// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Siva Pardo 
// Fecha creación: 03/12/2025 
// Número de ejercicio: 3
/*
3. Estudiantes de Programación I: 
Descripción: Desarrolle una estructura que guarde los datos de los n alumnos de 
la materia Programación I y los muestres por pantalla, la estructura debe tener los 
siguientes datos: 
• cedula (entero) 
• nombre (cadena de caracteres) 
• apellido (cadena de caracteres) 
• edad (entero) 
• profesión (cadena de caracteres) 
• lugar_nacimiento (cadena de caracteres) 
• dirección (cadena de caracteres) 
• teléfono (entero)
*/

#include <iostream>
#include <vector>

using namespace std;

struct Alumnos
{
int cedula; 
char nombre [100]; 
char apellido [100]; 
int edad ;
char profesión [100]; 
char lugar_nacimiento [100]; 
char dirección [100]; 
int teléfono;
};

vector <Alumnos> Ressgitro_Alumnos();
void Mostrar_Listado(vector <Alumnos> Listado_Global_Alumnos);

int main ()
{
    vector <Alumnos> Listado_Alumnos;
    Listado_Alumnos = Ressgitro_Alumnos();
    Mostrar_Listado (Listado_Alumnos);
    return 0;
}

vector <Alumnos> Ressgitro_Alumnos()
{
    system("cls");
    vector <Alumnos>  Listado_Global_Alumnos;
    Alumnos Datos_Alumnos;
    int n;
    cout<<"Ingrese la cantidad de alumnos que desea resgitrar: ";
    cin>> n;
    for (int i = 0; i < n; i++)
    {
        cout <<"RESGITRO DE DATOS DEL ALUMNO ["<<i+1<<"]"<<endl;
        cout <<"========================================"<<endl;
        cout <<"Ingrese la cedula del alumno: ";
        cin >> Datos_Alumnos.cedula;
        cin.ignore();
        cout <<"Ingrese el nombre del alumno: ";
        cin.getline (Datos_Alumnos.nombre, 100);
        cout <<"Ingrese el apellido del alumno: ";
        cin.getline (Datos_Alumnos.apellido, 100);
        cout <<"Ingrese la edad del alumno: ";
        cin >> Datos_Alumnos.edad;
        cin.ignore();
        cout <<"Ingrese la profesion del alumno: ";
        cin.getline (Datos_Alumnos.profesión, 100);
        cout <<"Ingrese el lugar de nacimiento del alumno: ";
        cin.getline (Datos_Alumnos.lugar_nacimiento, 100);
        cout <<"Ingrese la direccion del alumno: ";
        cin.getline (Datos_Alumnos.dirección, 100);
        cout <<"Ingrese el telefono del alumno: ";
        cin >> Datos_Alumnos.teléfono;
        Listado_Global_Alumnos.push_back(Datos_Alumnos);
    }
    return Listado_Global_Alumnos;
}

void Mostrar_Listado(vector <Alumnos> Listado_Global_Alumnos)
{
    system("cls");
    cout<< "LISTADO DE ALUMNOS DE PROGRAMACION 1"<<endl;
    cout<< "===================================="<<endl;
    for (int i = 0; i < Listado_Global_Alumnos.size(); i++)
    {
    cout<< "DATOS DEL ALUMNO ["<<i+1<<"]"<<endl;
    cout<< "============================"<<endl;
    cout<< "La cedula del alumno es: "<<Listado_Global_Alumnos[i].cedula<<endl;
    cout<< "El nombre del alumno es: "<<Listado_Global_Alumnos[i].nombre<<endl;
    cout<< "El apellido del alumno es: "<<Listado_Global_Alumnos[i].apellido<<endl;
    cout<< "La edad del alumno es: "<<Listado_Global_Alumnos[i].edad<<endl;
    cout<< "La profesion del alumno es: "<<Listado_Global_Alumnos[i].profesión<<endl;
    cout<< "El lugar de nacimiento del alumno es: "<<Listado_Global_Alumnos[i].lugar_nacimiento<<endl;
    cout<< "La direccion del alumno es: "<<Listado_Global_Alumnos[i].dirección<<endl;
    cout<< "El telefono del alumno es: "<<Listado_Global_Alumnos[i].teléfono<<endl;
    cout<< "============================"<<endl;
    }
}