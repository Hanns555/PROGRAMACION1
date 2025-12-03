// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Siva Pardo 
// Fecha creación: 03/12/2025 
// Número de ejercicio: 5
/*
6. Gestión de empleados con funciones 
Descripción: Define una estructura llamada Empleado que contenga los siguientes 
campos: 
• nombre (cadena de caracteres) 
• id (entero) 
• sueldo (decimal) 
• antiguedad (entero, en años) 
Escribe un programa que permita: 
• Ingresar los datos de N empleados. 
• Crear una función que reciba un arreglo de empleados y un valor de sueldo y 
devuelva cuántos empleados tienen un sueldo mayor a ese valor. 
• Crear otra función que reciba el arreglo y calcule el promedio de antigüedad 
de todos los empleados. 
*/
#include <iostream>
#include <vector>

using namespace std;

struct Empleado {
   char nombre [100]; 
   int id; 
   double sueldo; 
   int antiguedad; 
};

vector <Empleado> Registro_Empleados();
void Filtrar_Sueldo_Empleado(vector <Empleado>  Listado_Global_Empleados, double sueldo);
double Promedio_Antiguedad ( vector <Empleado>  Listado_Global_Empleados);

int main(){
    int a;
    double sueldo;
    vector <Empleado> LISTA_COMPLETA = Registro_Empleados();
    cout<< "Seleccione una funcion: "<<endl;
    cout<< "1. Filtrar Por Sueldo"<<endl;
    cout<< "2. Calcular promedio de antiguedad"<<endl;
    cin>> a;
    if (a==1)
    {
    cout<<"Ingrese un sueldo para filtrar empleados: ";
    cin>>sueldo;
    Filtrar_Sueldo_Empleado(LISTA_COMPLETA, sueldo);
    }
    else
    {
    cout<<"El promedio de antiguedad es: "<<Promedio_Antiguedad(LISTA_COMPLETA);
    }
    return 0;
}

vector <Empleado> Registro_Empleados()
{
    system("cls");
    vector <Empleado>  Listado_Global_Empleados;
    Empleado Datos_Empleado;
    int n;
    cout<<"Ingrese la cantidad de empleados que desea resgitrar: ";
    cin>> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout <<"RESGITRO DE DATOS DEL EMPLEADO ["<<i+1<<"]"<<endl;
        cout <<"=================================="<<endl;
        cout <<"Ingrese el nombre del empleado: ";
        cin.getline (Datos_Empleado.nombre, 100);
        cout <<"Ingrese el ID del empleado: ";
        cin >> Datos_Empleado.id;
        cout <<"Ingrese el suedo del empleado: ";
        cin >>  Datos_Empleado.sueldo;
        cout <<"Ingrese la antiguedad del empleado: ";
        cin >> Datos_Empleado.antiguedad;
        cin.ignore();
        Listado_Global_Empleados.push_back(Datos_Empleado);
    }
    return Listado_Global_Empleados;
}

void Filtrar_Sueldo_Empleado(vector <Empleado>  Listado_Global_Empleados, double sueldo)
{
   cout<< "LOS EMPLEADOS CON SUELDO MAYOR A "<<sueldo<<" SON: "<<endl;
   for (int i = 0; i < Listado_Global_Empleados.size(); i++)
   {
     if (Listado_Global_Empleados[i].sueldo>sueldo)
     {
        cout<< "========================================"<<endl;
        cout<< "Nombre del empleado: "<<Listado_Global_Empleados[i].nombre<<endl;
        cout<< "========================================"<<endl;
        cout<< "ID del empleado: "<<Listado_Global_Empleados[i].id<<endl;
        cout<< "========================================"<<endl;
        cout<< "Suedo del empleado: "<<Listado_Global_Empleados[i].sueldo<<endl;
        cout<< "========================================"<<endl;
        cout<< "Antiguedad del empleado: "<<Listado_Global_Empleados[i].antiguedad<<endl;
     }
   }
}

double Promedio_Antiguedad ( vector <Empleado>  Listado_Global_Empleados)
{
    double suma=0, promedio =0;
    for (int i = 0; i < Listado_Global_Empleados.size(); i++)
    {
        suma+= Listado_Global_Empleados[i].antiguedad;
    }
    promedio = suma/ Listado_Global_Empleados.size();
    return promedio;
}
