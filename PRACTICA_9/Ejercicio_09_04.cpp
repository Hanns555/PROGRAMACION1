// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Siva Pardo 
// Fecha creación: 03/12/2025 
// Número de ejercicio: 4
/*
4. Personal de la UCB 
Descripción: Se tiene una lista de empleados de la UCB y esta se almacena en 
una variable tipo struct llamada “empleado”. La información con la que se cuenta 
es: 
• nombre (cadena de caracteres) 
• genero (cadena de caracteres) 
• salario (decimal) 
Realizar un programa en C++ que lea un array de estructuras los datos de los N 
trabajadores de la empresa e imprima los datos de los empleados con menor y 
mayor salario.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Empleado
{
    char nombre [100];
    char genero [100]; 
    double salario ; 
};

vector <Empleado> Listado_Empleados();
bool compararPorSalario(const Empleado& a, const Empleado& b); 
void Mostrar_Lista_Trabajadores_UCB(vector <Empleado> Resgistro_Trabajadores_UCB);

int main()
{
    vector <Empleado> Registro_Trabajador;
    Registro_Trabajador = Listado_Empleados();
    Mostrar_Lista_Trabajadores_UCB(Registro_Trabajador);
    return 0;
}

vector <Empleado> Listado_Empleados()
{
    system("cls");
    vector <Empleado> Resgistro_Trabajadores_UCB;
    Empleado Trabajador_UCB;
    int n;
    cout<<"Ingrese la cantidad de trabajadores: ";
    cin >>n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout<<"Datos del trabajador ["<<i+1<<"]"<<endl;
        cout<<"================================="<<endl;
        cout<<"Ingrese el nombre del trabajador: ";
        cin.getline(Trabajador_UCB.nombre,100);
        cout<<"Ingrese el genero del trabajador: ";
        cin.getline(Trabajador_UCB.genero,100);
        cout<<"Ingrese el salario del trabajador: ";
        cin>> Trabajador_UCB.salario;
        cin.ignore();
        Resgistro_Trabajadores_UCB.push_back(Trabajador_UCB);
    }
    sort (Resgistro_Trabajadores_UCB.begin(),Resgistro_Trabajadores_UCB.end(),compararPorSalario);
    return Resgistro_Trabajadores_UCB;
}

bool compararPorSalario(const Empleado& a, const Empleado& b) 
{
    return a.salario < b.salario; // menor a mayor
}

void Mostrar_Lista_Trabajadores_UCB(vector <Empleado> Resgistro_Trabajadores_UCB)
{
   system("cls");
    cout<< "LISTADO DE TRABAJADORES DE MENOR A MAYOR"<<endl;
    cout<< "===================================="<<endl;
    for (int i = 0; i < Resgistro_Trabajadores_UCB.size(); i++)
    {
    cout<< "DATOS DEL TRABAJADOR ["<<i+1<<"]"<<endl;
    cout<< "============================"<<endl;
    cout<< "El nombre del trabajador es: "<<Resgistro_Trabajadores_UCB[i].nombre<<endl;
    cout<< "El genero del trabajador es: "<<Resgistro_Trabajadores_UCB[i].genero<<endl;
    cout<< "El salario del trabajador es: "<<Resgistro_Trabajadores_UCB[i].salario<<endl;
    cout<< "============================"<<endl;
    }
}