// Materia: Programación I, Paralelo 4 
// Autor: Hanns Micahel Silva Pardo. 
// Fecha creación: 16/09/2025 
// Número de ejercicio: 5
/*
5. Realizar un programa que reciba las horas trabajadas de un trabajador, la tarifa por 
hora y una bonificación si trabaja más de 8 horas , solamente a las horas extra. Debe dar 
como resultado.  
• Salario del trabajador  
• Salario bonificación si es que tuviera.   
*/
#include<iostream>
using namespace std;
int salario(int x, int y);
int bonificacion(int a, int b);
int main(){
    int horas_trabajadas=0,tarifa=0, horas_extras=0, tarifa2=0;
    cout<<"Ingrese las horas trabajadas: ";
    cin>>horas_trabajadas;
    cout<<"La tarifa por hora es: ";
    cin>>tarifa;
    cout<<"La tarifa extra por hora es: ";
    cin>>tarifa2;
    if(horas_trabajadas<=8){
    cout<<"-Salario del trabajador: "<<salario(horas_trabajadas,tarifa)<< endl;
    }
    else if(horas_trabajadas>8){
    horas_extras=horas_trabajadas-8;
    cout<<"-Salario del trabajador: "<<salario(8,tarifa)<<endl;
    cout<<"-Salario bonificacion: "<<bonificacion(horas_extras,tarifa2)<<endl;
    }
    return 0;
}
//Funcion para calcular salario
int salario(int x, int y){
    int monto=0;
    monto=x*y;
    return monto;
}
//Funcion calcular bono
int bonificacion(int a, int b){
    int aumento=0;
    aumento=a*b;
    return aumento;

}

