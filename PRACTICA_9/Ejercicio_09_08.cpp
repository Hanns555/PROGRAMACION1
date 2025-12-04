// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 09/12/2025
// Número de ejercicio: 8
/*
8. Olimpiada Nacional
Descripción: El viceministerio de deportes hace una olimpiada a nivel nacional de
los siguientes deportes:
• Tiro con arco
• Atletismo
• Boxeo
• Ciclismo
• Natación
• Esgrima
También se registra los nombres de los atletas y que departamento representa y
que deporte practica.
Realizar un programa en C++ que simule y registre cuantas medallas ha ganado un
atleta y que me muestre el medallero final por departamento.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

struct atleta
{
    char nombre[100];
    char pais [100];
    char deporte [100];
    int medallas;
};

vector <atleta> Resgistro_Atletas();
int Simulador_Medallas();
void Mostrar_Resultados(vector <atleta> Lista_Atleta);

int main(){
    vector <atleta> LISTA_TOTAL;
    srand(time(NULL));
    LISTA_TOTAL=Resgistro_Atletas();
    Mostrar_Resultados(LISTA_TOTAL);
    return 0;
}
vector <atleta> Resgistro_Atletas()
{
   vector <atleta> Lista_Atleta;
   vector <string> Departamentos = {"La Paz", "Santa Cruz", "Cochabamba", "Oruro", "Potosi","Chuquisaca","Tarija","Pando","Beni"};
   vector <string> Deportes = {"Tiro con arco", "Atletismo", "Boxeo", "Ciclismo", "Natacion","Esgrima"};
   atleta Datos_Atleta;
   int sport,n,depa;
   cout<<"Cuantos atletas desea registrar: ";
   cin>>n;
   cin.ignore();
   for (int i = 0; i < n; i++)
   {
   cout<<"Ingrese el nombre del atleta: ";
   cin.getline(Datos_Atleta.nombre,100);
   cout<<"Ingrese el departamento del atleta: "<<endl;
   for (int i = 0; i < Departamentos.size(); i++)
   {
    cout<< i+1<<". "<<Departamentos[i]<<endl;
   }
   cin>> depa;
   strcpy(Datos_Atleta.pais, Departamentos[depa-1].c_str());
   cout<<"Ingrese el deporte del atleta: "<<endl;
   for (int i = 0; i < Deportes.size(); i++)
   {
    cout<< i+1<<". "<<Deportes[i]<<endl;
   }
   cin>> sport;
   cin.ignore();
   strcpy(Datos_Atleta.deporte, Deportes[sport-1].c_str());
   Datos_Atleta.medallas=Simulador_Medallas();
   Lista_Atleta.push_back(Datos_Atleta);
   }
   return Lista_Atleta;
}
int Simulador_Medallas(){
   int medallas = rand()%10+1;
   return medallas;
}

void Mostrar_Resultados(vector <atleta> Lista_Atleta){
   int i=0;
   vector <string> Departamentos = {"La Paz", "Santa Cruz", "Cochabamba", "Oruro", "Potosi","Chuquisaca","Tarija","Pando","Beni"};   
   int suma=0;
   cout<<"EL MEDALLERO POR DEPARTAMENTOS ES: "<< endl;
   cout<<"Departamento"<<"   "<<"Medallas"<<endl;
   for (i ; i < Departamentos.size(); i++)
   {
    cout<<Departamentos[i];
    for (int j = 0; j < Lista_Atleta.size(); j++)
    {
    if (strcmp(Departamentos[i].c_str(), Lista_Atleta[j].pais) == 0)
    {
        suma+=Lista_Atleta[j].medallas;
    }
    }
    cout<<"\t"<<suma<<endl;
    suma=0;
   }
}