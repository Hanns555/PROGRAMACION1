// Materia: Programación I, Paralelo 3 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 6
/*
6. Traspones una matriz de N x M 
*/
#include <iostream>

using namespace std;
void mostrar_matriz(int matriz[100][100], int filas, int columnas);
void transpuesta(int matriz[100][100], int filas, int columnas);
int main(){
    system("cls");
    int matriz[100][100], filas=0, columnas=0;
    cout<<"Ingrese el numero de filas: ";
    cin>>filas;
    cout<<"Ingrese el numero de columnas: ";
    cin>>columnas;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
        cout<<"Ingrese los datos de la matriz, posicion ("<<i<<","<<j<<"): ";
        cin>> matriz[i][j];
        }
    }
    mostrar_matriz(matriz,filas,columnas);
    transpuesta(matriz,filas,columnas);
    return 0;
}
void mostrar_matriz(int matriz[100][100], int filas, int columnas){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<< matriz[i][j]<<" ";
        }
    cout<<endl;
    }
 }
void transpuesta(int matriz[100][100], int filas, int columnas){
    int transpuesta[100][100];
    for (int i = 0; i < columnas; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            transpuesta[i][j]=matriz[j][i];
        }
    cout<<endl;
    }
    cout<<"La matriz traspuesta es: "<<endl;
    mostrar_matriz(transpuesta,columnas ,filas);
 }
 