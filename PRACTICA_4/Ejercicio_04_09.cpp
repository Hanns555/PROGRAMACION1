// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 17/09/2025 
// Número de ejercicio: 8
/*
9. Un negocio de 'Cosméticos' de belleza contratará a n vendedoras para la venta de sus 
productos. 
Cada vendedora en promedio debe vender 10 productos en un mes. 
La cancelación de los sueldos a las vendedoras se realiza cada fin de mes bajo las 
siguientes características: 
• Una vendedora recibe un sueldo básico de acuerdo a su antigüedad y además se 
añade un sueldo extra por comisión de ventas del 10% del total vendido. 
• La propietaria del negocio desea conocer cuánto de sueldo debe cancelar a cada 
una de sus vendedoras y cuánto de comisión recibirá como extra.    
*/
#include<iostream>
#include<ctime>
#include <cstdlib>  
using namespace std;
double sueldo(double x, double y);
double comision(double x, double y);
int main(){
    int Trabajadores=0;
    int Ventas=0,Antiguedad=0;
    srand(time(NULL));
    cout<<"Ingrese la cantidad de trabajadores contratados: ";
    cin>> Trabajadores;
    for (int i = 1; i <= Trabajadores; i++)
    {
        Antiguedad=(rand()%5)+1;
        Ventas= (rand()%100)+10;
        cout<<"El trabajador "<<i<<" hizo: "<<Ventas<<" ventas"<<endl;
        cout<<"El trabajador "<<i<<" su sueldo es: "<< sueldo(Antiguedad,Ventas)<<endl;
        cout<<"El trabajador "<<i<<" su comision es: "<< comision(Antiguedad,Ventas)<<endl;
    }

    return 0;
}
double sueldo(double x, double y){
   double sueldo, comision, Total_sueldo=0;  
   sueldo= x*0.05*2750.0+2750.0;
   return sueldo;
}
double comision(double x, double y){
   double sueldo, comision, Total_sueldo=0;  
   sueldo= x*2750.0+2750.0;
   comision= y*0.1;
   return comision;
}