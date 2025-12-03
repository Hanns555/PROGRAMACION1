// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Siva Pardo 
// Fecha creación: 03/12/2025 
// Número de ejercicio: 2
/*
2. Datos de un atleta 
Descripción: Crea una estructura llamada Atleta que contenga los siguientes 
campos: 
• nombre (cadena de caracteres) 
• pais (cadena de caracteres) 
• edad (entero) 
• mejor_tiempo (entero, en segundos) 
Escribe un programa que permita al usuario ingresar los datos de N atletas y, al final, 
muestre el nombre y país del atleta con el mejor tiempo registrado. 
*/
#include <iostream>
#include <vector>

using namespace std;

struct Atleta
{
  char Nombre[100];
  char Pais [100];
  int Edad;
  int Mejor_Tiempo;
};

vector <Atleta> Resgistro_Atletas ();
void Mostrar_Mejor_Tiempo(vector <Atleta> Resgistro_Global);

int main ()
{
  vector<Atleta> Lista_Atletas;
  Lista_Atletas=Resgistro_Atletas();
  Mostrar_Mejor_Tiempo(Lista_Atletas);
  return 0;
}

vector <Atleta> Resgistro_Atletas ()
{
  system("cls");
  vector <Atleta> Resgistro_Global;
  Atleta Datos_Atleta;
  int n=0;
  cout<<"Ingrese el numero de atletas que desea resgistrar: ";
  cin >>n;
  cin.ignore();
  for (int i = 0; i < n; i++)
  {
  system("cls");
  cout<<"DATOS ATLETA ["<<i+1<<"]"<<endl;
  cout<<"============"<<endl;
  cout<<"Ingrese el nombre del Atleta: ";
  cin.getline(Datos_Atleta.Nombre,100);
  cout<<"Ingrese el pais del Atleta: ";
  cin.getline(Datos_Atleta.Pais,100);
  cout<<"Ingrese la edad del Atleta: ";
  cin>>Datos_Atleta.Edad;
  cout<<"Ingrese el mejor tiempo del Atleta en segundos: ";
  cin>>Datos_Atleta.Mejor_Tiempo;
  cin.ignore();
  Resgistro_Global.push_back(Datos_Atleta); 
  }
  return  Resgistro_Global;
}

void Mostrar_Mejor_Tiempo(vector <Atleta> Resgistro_Global)
{
  system ("cls");
  Atleta Mejor_Atleta;
  int n = 999999;
  for (int i = 0; i < Resgistro_Global.size(); i++)
  {
    if (n >= Resgistro_Global[i].Mejor_Tiempo)
    {
      n = Resgistro_Global[i].Mejor_Tiempo;
      Mejor_Atleta = Resgistro_Global[i];
    }
  }
  
  cout<<"DATOS DEL MEJOR ATLETA CON MEJOR TIEMPO"<<endl;
  cout<<"======================================="<<endl;
  cout<<"Nombre del atleta: "<<Mejor_Atleta.Nombre<<endl;
  cout<<"Pais del atleta: "<<Mejor_Atleta.Pais<<endl;
  cout<<"Edad del atleta: "<<Mejor_Atleta.Edad<<endl;
  cout<<"Mejor tiempo del atleta: "<<Mejor_Atleta.Mejor_Tiempo<<"[s]"<<endl;
}