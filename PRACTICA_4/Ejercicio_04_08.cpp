// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 17/09/2025 
// Número de ejercicio: 8
/*
8. La comercial 'La Estrella' vende n productos en un día, de los cuales factura al precio 
de cada uno con un IVA del 13%, y si el monto final se excede en 2500 Bs se aplica un 
descuento del 5%. 
Obtener la suma total de las ventas realizadas en el día y calcular el pago del IVA del 13% 
al servicio de Impuestos Nacionales. 
El precio de los productos debe ser generado en forma aleatoria entre 20 y 50.    
*/
#include<iostream>
#include<ctime>
using namespace std;
void Algoritmo(int x);
int main(){
    int Productos=0, Precio_Generado=0, Ganancia=0;
    srand(time(NULL));
    cout<< "Ingrese la cantidad de productos vendidos: ";
    cin >>Productos;
    for (int i = 1; i < Productos; i++)
    {
        Precio_Generado= (rand()%31)+20;
      //cout<< Precio_Generado<<" ";
        Ganancia+=Precio_Generado;
    }
        cout<<endl;
        cout<<"La Ganancia en el dia fue: "<<Ganancia<<endl;
        Algoritmo(Ganancia);
    return 0;
}
void Algoritmo(int x){
    int Descuento1=0,Descuento2=0;
    if(x<=2500){
        Descuento1= x*0.13;
        cout<<"El pago del IVA con un descuento del 13 porciento es: "<<Descuento1<<endl;
    }
    else{
        Descuento2= x*0.05;
        cout<<"El pago del IVA con un descuento del 5 porciento es: "<<Descuento2<<endl;
    } 
}