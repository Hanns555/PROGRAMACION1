// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 4
/*
4. Leer 2 vectores de dimensión N y calcule la multiplicación de los mismos en otro 
vector. 
*/
#include<iostream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;
void multiplicacion(vector<int>x, vector<int>y);
int main(){
    system("cls");
    vector <int> lista_1;
    vector <int> lista_2;
    string datos1;
    string datos2;
    int reemplazo1;
    int reemplazo2;
    int N=0;
    cout<<"Ingrese el tamanio de los vectores: ";
    cin>> N;
    cin.ignore();
    cout<< "Ingrese los datos de lista_1: ";
    getline(cin, datos1);
    stringstream ss(datos1);
    while (ss>> reemplazo1)
    {
        lista_1.push_back(reemplazo1);
    }
    /*
    for (int i : lista_1)
    {
        cout<< i<<" ";
    }
    */
    //cout<< endl;
    cout<< "Ingrese los datos de lista_2: ";
    getline(cin, datos2);
    stringstream aa(datos2);
    while (aa>> reemplazo2)
    {
        lista_2.push_back(reemplazo2);
    }
    /*
    for (int i : lista_2)
    {
        cout<< i<<" ";
    }
    */
    //cout<<endl;
    multiplicacion(lista_1, lista_2);
    return 0;
}

void multiplicacion(vector<int>x, vector<int>y){
  int producto;
  vector <int> multi;
  cout<<"El vector multiplicacion de lista_1 y lista_2 es: ";
  for (int i = 0; i < x.size(); i++)
  {
    producto= x[i]*y[i];
    multi.push_back(producto);
  }
  for (int i : multi)
  {
    cout<< i<<" ";
  }
}