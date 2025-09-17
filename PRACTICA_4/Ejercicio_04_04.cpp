// Materia: Programación I, Paralelo 4 
// Autor: Hanns Micahel Silva Pardo. 
// Fecha creación: 16/09/2025 
// Número de ejercicio: 4
/*
4. Crea dos funciones: Una función llamada “ConvertirCelsiusAFahrenheit” que reciba 
grados Celsius y devuelva la conversión a Fahrenheit. Una función llamada 
“MayorTemperatura” que reciba dos valores de temperatura y devuelva el valor mayor.  
*/
#include<iostream>
using namespace std;
double ConvertirCelsiusAFahrenheit(double x);
double R_MayorTemperatura(int x, int y );
void MayorTemperatura(int x, int y );
int main(){
    int selecion=0, T_Celcius=0, T1=0, T2=0;
    cout<<"1. Convertir temperatura de Celsius a Fahrenheit "<<endl;   
    cout<<"2. Determinar el mayor entre dos temperaturas "<<endl;
    cin>> selecion;
    switch (selecion)
    {
    case 1:
        cout<< "Ingrese su temperatura: ";
        cin>>T_Celcius;
        cout<< "La temperatura en grados Fahrenheit es: "<<ConvertirCelsiusAFahrenheit(T_Celcius);
        break;
    case 2:
        cout<< "Ingrese Temperatura T1: ";
        cin>>T1;
        cout<< "Ingrese Temperatura T2: ";
        cin>>T2;
        R_MayorTemperatura(T1, T2 );
        MayorTemperatura(T1,T2);
        break;
    default:
        break;
    }
    return 0;
}
// Funcion que convierte de Celcius a Fahrenheir
double ConvertirCelsiusAFahrenheit(double x){
    double Fahrenheit;
    Fahrenheit=((9.0/5.0)*x+32);
    return Fahrenheit;
}
// Como el ejercicio pide un retorno generamos esta funcion
double R_MayorTemperatura(int x, int y ){
    if(x>y){
     return x;
    }
    else if(x<y){
     return y;
    }
    else{
     return 0;
    }
}
void MayorTemperatura(int x, int y ){
    if(x>y){
     cout<< "La temeratura "<<x<<" es mayor que "<<y<< endl;
    }
    else if(x<y){
     cout<< "La temeratura "<<y<<" es mayor que "<<x<< endl;
    }
    else{
     cout<< "La temeratura "<<x<<" es igual a "<<y<< endl;
    }

}
