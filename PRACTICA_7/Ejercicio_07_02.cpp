// Materia: Programación I, Paralelo 3 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 2
/*
2. Generar una matriz de N x N con números al azar entre A y B, y determinar: 
    • La suma de la última columna 
    • El producto total de la última fila 
    • Obtener el mayor valor y su posición 
    • Obtener la desviación estándar de todos los elementos de la matriz 
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;
void LlenarMatriz(int matriz[100][100], int filas, int columnas);
int producto(int matriz[100][100], int filas, int columnas);
int suma(int matriz[100][100], int filas, int columnas);
int mayor(int matriz[100][100],int filas, int columnas);
void buscar_posicion(int matriz[100][100],int filas, int columnas);
int main(){
    srand(time(0));
    int matriz[100][100];
    int filas=0, columnas=0, ultima_filap=0, ultima_filas=0, mayor_elemento=0;
    cout<<"Ingrese el  numero de filas: ";
    cin>> filas;
    cout<<"Ingrese el  numero de columnas: ";
    cin>> columnas;
    LlenarMatriz(matriz,filas,columnas);
    ultima_filas=suma(matriz,filas,columnas);
    cout<< "La suma de la ultima fila es: "<<ultima_filas<<endl;
    ultima_filap=producto(matriz,filas,columnas);
    cout<< "El producto de la ultima fila es: "<<ultima_filap<<endl;
    mayor_elemento=mayor(matriz,filas,columnas);
    cout<< "El mayor elemento de la matriz "<<filas<<" x "<<columnas<<" es: "<<mayor_elemento<<endl;
    buscar_posicion(matriz,filas,columnas);
    return 0;
}

void LlenarMatriz(int matriz[100][100], int filas, int columnas){
    double suma_elementos=0, contador1=0, media_aritmetica=0, a=0;
    double calculo=0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j]=rand()%10;
            suma_elementos+=matriz[i][j]; //suma de elementos
            contador1=filas*columnas; //n
            media_aritmetica=suma_elementos/contador1; //media aritmetica
            a+=pow((matriz[i][j]-media_aritmetica),2);
            cout<< matriz[i][j]<<" ";
        }
    cout<< endl;    
    }
    calculo=sqrt(a/contador1);
    cout<< "La desviacion tipica es: "<<calculo<<endl;
}

int producto(int matriz[100][100], int filas, int columnas){
    int resultado=1;
    for (int i = filas-1; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            resultado*=matriz[i][j];
        }
    }
    return resultado;
}
int suma(int matriz[100][100], int filas, int columnas){
    int resultado_s=0;
    for (int i = filas-1; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            resultado_s+=matriz[i][j];
        }
    }
    return resultado_s;
}

int mayor(int matriz[100][100],int filas, int columnas){
    int n_mayor=0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if(n_mayor<=matriz[i][j]){
                n_mayor= matriz[i][j];
            }
        }
    }
    return n_mayor;
}
void buscar_posicion(int matriz[100][100],int filas, int columnas){
   int elemento=mayor(matriz,filas, columnas);
   cout<< "El mayor elemento se encuentra en las posiciones: " ;
   for (int i = 0; i < filas; i++)
   {
    for (int j = 0; j < columnas; j++)
    {
        if (elemento==matriz[i][j])
        {
        cout<< "("<<i<<","<<j<<")"<<" ";
        }
    }
   }
}