// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 09/12/2025
// Número de ejercicio: 9
/*
9. Calificaciones Curso
Desarrollo: Se desea calcular las notas finales de N alumnos de un curso, así
como también el promedio, mínimo y máximo de éstas. Se recibirá el número de
alumnos y las notas parciales de cada uno de éstos. Las notas parciales
corresponden a la T1, T2, T3, T4 y EF. La nota final se calcula empleando la
fórmula:
NF = 0.7*NP + 0.3*EF
En donde NP es la nota de presentación calculada como:
NP = (T1+T2+T3+T4)/4
*/

#include <iostream>
#include <vector>

using namespace std;

struct Alumnos_Notas
{
  int T1;
  int T2;
  int T3;
  int T4;
  int EF;
};

void funciones(vector <double> nota_final);
vector <double> calculadora_nota_final (vector<Alumnos_Notas> Datos_Alumnos);
vector<Alumnos_Notas> Registro_Notas();

int main(){
    vector<Alumnos_Notas> NOTAS;
    vector <double> Notas_Finales;
    NOTAS = Registro_Notas();
    Notas_Finales = calculadora_nota_final (NOTAS);
    funciones(Notas_Finales);
    return 0;
}

vector<Alumnos_Notas> Registro_Notas()
{
    vector<Alumnos_Notas> Datos_Alumnos;
    Alumnos_Notas NOTAS;
    int n;
    cout<< "Cuantos alumnos quiere ingresar notas: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese la nota del T1: ";
        cin>> NOTAS.T1;
        cout<<"Ingrese la nota del T2: ";
        cin>> NOTAS.T2;
        cout<<"Ingrese la nota del T3: ";
        cin>> NOTAS.T3;
        cout<<"Ingrese la nota del T4: ";
        cin>> NOTAS.T4;
        cout<<"Ingrese la nota del EF: ";
        cin>> NOTAS.EF;
        Datos_Alumnos.push_back(NOTAS);
    }
    return Datos_Alumnos;
}

vector <double> calculadora_nota_final (vector<Alumnos_Notas> Datos_Alumnos){
   double suma=0.0,NP=0.0, NF=0.0;
   vector <double> nota_final;
    for (Alumnos_Notas X : Datos_Alumnos){
    suma += X.T1+X.T2+X.T3+X.T4;
    NP = suma / 4;
    NF = 0.7*NP + 0.3*X.EF ;
    nota_final.push_back(NF);
    suma = 0.0;
    }
    return nota_final;
}

void funciones(vector <double> nota_final)
{
   double nota_promedio=0.0;
   double minimo=99999.0;
   double maximo=0.0;
   for (int i = 0; i < nota_final.size(); i++)
   {
    nota_promedio += nota_final[i];
   }
   cout<<"El promedio de los N alumnos son: "<<nota_promedio/nota_final.size()<<endl;
   for (int i = 0; i < nota_final.size(); i++)
   {
    if (minimo>=nota_final[i])
    {
        minimo=nota_final[i];
    }
    if (maximo<=nota_final[i])
    {
        maximo=nota_final[i];
    }
   }
   cout<<"La nota minima es: "<<minimo<<endl;
   cout<<"La nota maxima es: "<<maximo<<endl;
}