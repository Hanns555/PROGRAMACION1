// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 29/09/2025
// Número de ejercicio: 3
/*
3. Escriba un programa para introducir los N números enteros en un arreglo llamado 
   calificaciones. 
   Después que todos los números son introducidos obtener: 
        • La suma total de calificaciones, 
        • El promedio de los números 
        • Use el promedio para determinar la desviación de cada valor del promedio.  
          Almacene cada desviación en un arreglo llamado desviación. Cada desviación se 
          obtiene como el valor del elemento menos el promedio de todos los datos. Haga 
          que su programa despliegue cada desviación al lado de su elemento 
          correspondiente del arreglo calificaciones. 
        • Calcule la varianza de los datos usados. La varianza se obtiene elevando al 
          cuadrado cada desviación individual y dividiendo la suma de las desviaciones 
          cuadradas entre el número de desviaciones.
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip> 

using namespace std;
double suma ( vector <double> x);
double promedio ( vector <double> y, double z);
void calculos(vector<double>t, double s);
int main(){
    system("cls");
    string notas;
    vector<double>calificaciones;
    double nota_ingresada;
    double suma_total=0,  promedio_total=0;
    cout<< "Ingrese las notas a ponderar: ";
    getline(cin, notas);
    stringstream ss(notas);
    while(ss>>nota_ingresada){
        calificaciones.push_back(nota_ingresada);
    }
    /*
    // Verificar que se guare correctamente en el vector calificaciones
    for (int i : calificaciones)
    {
        cout<< i<< " ";
    }
    cout<< endl;
    */
    // Suma todos los elementos del vector calificaciones
    suma_total=suma(calificaciones);
    promedio_total=promedio(calificaciones,suma_total);
    cout<< "La suma de todas las calificaciones es: "<< suma_total<<endl;
    cout<< "El promedio de las calificaciones es: "<< promedio_total<<endl;
    calculos(calificaciones, promedio_total);
    return 0;
}

double suma ( vector <double> x){
    double suma = 0;
    for (int i = 0; i < x.size(); i++)
    {
        suma+=x[i];    
    }
    return suma;
}
double promedio ( vector <double> y, double z){
    double promedio = 0;
    promedio= z/ y.size();
    return promedio;
}
void calculos(vector<double>t, double s){
    vector<double>desviacion_v;
    vector<double>varianza_v;
    double varianza_total=0;
    double desviacion;
    double varianza;
    double suma2=0;
    // Crea un vector para el calculo de desviaiones
    for (int a = 0; a < t.size(); a++)
    {
       desviacion= t[a]-s;
       desviacion_v.push_back(desviacion);
    }
    cout<<"Las desviaciones de las calificaciones es: ";
    for (double y : desviacion_v)
    {
        cout<< fixed<< setprecision(2);
        cout<< y<<" ";
    }
    cout<< endl;
    for (int q = 0; q < desviacion_v.size(); q++)
    {
        varianza= desviacion_v[q]*desviacion_v[q];
        varianza_v.push_back(varianza);
    }
    for (double z : varianza_v)
    {
       // cout<< fixed<< setprecision(2);
       // cout<< z<<" ";
        suma2+=z;
    }
    varianza_total=suma2/varianza_v.size();
    cout<< "La varianza de los datos es: ";
    cout<<varianza_total<<endl;
}