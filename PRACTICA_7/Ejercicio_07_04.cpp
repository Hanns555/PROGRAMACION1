// Materia: Programación I, Paralelo 3 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 4
/*
4. Generar la matriz para un orden nxn 
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
 
void generar_matriz(int matriz[100][100], int filas, int columnas);
void mostrar_matriz(int matriz[100][100], int filas, int columnas);

int main(){
    srand(time(0));
    int matriz [100][100];
    int filas=0,columnas=0;
    cout<< "Ingrese la matriz nxn que desea generar: ";
    cin>> filas;
    columnas = filas;
    generar_matriz(matriz,filas,columnas);
    return 0;
 }

void generar_matriz(int matriz[100][100], int filas, int columnas){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j]= rand()%10;
        }
    }
    mostrar_matriz(matriz,filas,columnas);
 }
 //Muestra la matriz
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