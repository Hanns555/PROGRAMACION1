// Materia: Programación I, Paralelo 3 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 18/10/2024 
// Número de ejercicio: 3
/*
a) Mostrar la matriz que describe el área.  
b) Mostrar el número de filas y columnas que no tienen un muerto viviente.  
c) Determinar las coordenadas de los muertos vivientes en la matriz. Utilice 
vectores paralelos para almacenar la posición de los muertos vivientes. Un 
vector almacenara el índice de la fila y otro vector almacenara el índice de la 
columna.  
d) La cantidad de muertos vivientes que existen en toda la matriz.  
e) Determinar si dos o más muertos vivientes se encuentran en la primera 
columna. Si es así imprimir “no es posible entrar al complejo” de otro modo 
imprimir “es posible entrar al complejo”.  
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//Funciones para que funcione complejo
void Generar_Terreno(char matriz[100][100],int filas,int columnas);
void Mostrar_Matriz(char matriz[100][100],int filas,int columnas);
void Mostrar_zona_segura(char matriz[100][100],int filas,int columnas);
void Mostrar_zona_nosegura(char matriz[100][100],int filas,int columnas);
void Zombis(char matriz[100][100],int filas,int columnas);
int suma_z(int matriz[100][100],int filas,int columnas);
int suma_1racolumna(int matriz[100][100],int filas,int columnas);

int main(){
    system("cls");
    srand(time(0));
    char matriz [100][100];
    int filas, columnas;
    cout<<"Ingrese el largo del complejo: ";
    cin>>filas;
    cout<<"Ingrese el ancho del complejo: ";
    cin>>columnas;
    Generar_Terreno(matriz,filas,columnas);
    return 0;
}

void Generar_Terreno(char matriz[100][100],int filas,int columnas){
    int a=0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            a=rand()%2;
          if (a==0)
          {
            matriz[i][j]='x';
          }
          else{
            matriz[i][j]='o';
          }
        }
    }
    Mostrar_Matriz(matriz,filas,columnas);
    Mostrar_zona_segura(matriz,filas,columnas);
    Mostrar_zona_nosegura(matriz,filas,columnas);
    Zombis(matriz,filas,columnas);
}

void Mostrar_Matriz(char matriz[100][100],int filas,int columnas){
    cout<<"Si ve una 'x' la zona no es segura "<<endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
         cout<<"\t"<<matriz[i][j]<<"\t";
        }
        cout<< endl;
    }
}

void Mostrar_zona_segura(char matriz[100][100],int filas,int columnas){
    char seguro='o';
    int contador=0;
    cout<< "Las zonas seguras se encuentran en las posiciones: ";
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
         if (seguro==matriz[i][j])
         {
            cout<< "("<<i<<","<<j<<") ";
            contador++;
         }
        }
    }
    cout<<endl;
    cout<<"El total de zonas seguras es: "<<contador<<endl;
}

void Mostrar_zona_nosegura(char matriz[100][100],int filas,int columnas){
    char noseguro='x';
    int contador=0;
    cout<< "Las zonas noseguras se encuentran en las posiciones: ";
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
         if (noseguro==matriz[i][j])
         {
            cout<< "("<<i<<","<<j<<") ";
            contador++;
         }
        }
    }
    cout<<endl;
    cout<<"El total de zonas noseguras es: "<<contador<<endl;
}

void Zombis(char matriz[100][100],int filas,int columnas){
    char noseguro='x';
    int Zmatriz[100][100];
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
         if (noseguro==matriz[i][j])
         {
            Zmatriz[i][j]=rand()%5;
         }
        }
    }
    cout<<"Todos los zombis en el complejo son: "<<suma_z(Zmatriz, filas, columnas)<<endl;
    cout<<"Los zombis en la primera columna son: "<<suma_1racolumna(Zmatriz, filas, columnas)<<endl;
    int a=suma_1racolumna(Zmatriz, filas, columnas);
    if (a<2)
    {
        cout<<"Se puede ingresar al complejo"<<endl;
    }
    else{
        cout<<"No se puede ingresar al complejo"<<endl;
    }   
}

int suma_z(int matriz[100][100],int filas,int columnas){
    int suma=0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
         suma+=matriz[i][j];
        }
    }
    return suma;
}
int suma_1racolumna(int matriz[100][100],int filas,int columnas){
    int suma=0;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
         suma+=matriz[i][j];
        }
    }
    return suma;
}