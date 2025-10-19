// Materia: Programación I, Paralelo 3 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 1 
/*
1. Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por la fila 
n. 
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void llenarMatriz(int matriz[100][100], int filas, int columnas);
void mostrarMatriz(int matriz[100][100], int filas, int columnas);
void InvertirMatriz(int matriz[100][100], int filas, int columnas);
int main(){
    system("cls");
    srand(time(0));
    int matriz [100][100];
    int filas=0, columnas =0;
    cout<<"Ingrese el numero de filas de la matriz nxm: ";
    cin>>filas;
    cout<<"Ingrese el numero de columnas de la matriz nxm: ";
    cin>>columnas;
    llenarMatriz(matriz,filas,columnas);
    mostrarMatriz(matriz,filas,columnas);
    cout<< "La matriz con fila 1 cambiada por fila n es: "<<endl;
    InvertirMatriz(matriz,filas,columnas);
    return 0;
}

// Llena la matriz con números aleatorios del 0 al 9
void llenarMatriz(int matriz[100][100], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
}
// Muestra la matriz por pantalla
void mostrarMatriz(int matriz[100][100], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
void InvertirMatriz(int matriz[100][100], int filas, int columnas){
int invertido[100][100];
for (int i = filas-1; i<filas ; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
        invertido[0][j]=matriz[i][j];
        }
    }
    for (int i = 1; i<filas-1 ; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
        invertido[i][j]=matriz[i][j];
        }
    }
    for (int i = 0; i<1 ; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
        invertido[filas-1][j]=matriz[i][j];
        }
    }
    mostrarMatriz(invertido,filas,columnas);
}