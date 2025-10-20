// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 19/10/2024 
// Número de ejercicio: 6
/*
6.  Rango de calificaciones en un curso: Un maestro tiene N calificaciones de sus 
    estudiantes en un vector. Las calificaciones deben ser llenadas en forma aleatoria entre 0 
    y 100. Luego debe calcular el porcentaje de estudiantes en cada rango: 
        • 0-59 (Reprobado) 
        • 60-79 (Regular) 
        • 80-89 (Bueno) 
        • 90-100 (Excelente) 
*/  
#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <vector> 

using namespace std;

int Generar_Aleatorio(int x, int y);
int Suma(vector<int> notas);
void ponderacion(vector<int> notas);

int main (){
    system("cls");
    srand(time(NULL));
    int generar_calificaciones=0;
    vector <int> calificaciones;
    cout<< "Ingrese la cantidad de calificaciones a generar: ";
    cin>>generar_calificaciones;
    //cout<<Generar_Aleatorio(0,100);
    for (int i = 0; i < generar_calificaciones; i++)
    {
        calificaciones.push_back(Generar_Aleatorio(0,100));
    }
    for (int i : calificaciones)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    ponderacion(calificaciones);
    return 0;
}

int Generar_Aleatorio(int x, int y){
    int numero=0;
    numero=(rand()%(y-x+1))+x;
    return numero;
}
void ponderacion(vector<int> notas){
     double Total=0;
     int contador1=0, contador2=0, contador3=0, contador4=0;
     for (int i : notas)
    {
        if (0<=i && i<60)
        {
            contador1++;
        }
        else if (60<=i && i<80)
        {
            contador2++;
        }
        else if (80<=i && i<90)
        {
            contador3++;
        }
        else if (90<=i && i<101)
        {
            contador4++;
        }
    }
    Total=contador1+contador2+contador3+contador4;
    cout<<"Reprobados: "<<(contador1/Total)*100.0<<"%"<<endl;
    cout<<"Regulares: "<<(contador2/Total)*100.0<<"%"<<endl;
    cout<<"Buenos: "<<(contador3/Total)*100.0<<"%"<<endl;
    cout<<"Excelentes: "<<(contador4/Total)*100.0<<"%"<<endl;
}