// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 24/08/2025 
// Número de ejercicio: 4
#include <iostream>
//libreria cmath para poner la constante pi
#include <cmath> 
using namespace std;
int main(){
    long double r, Volumen;
    cout<<"Colocoque el radio de su esfera: ";
    cin>>r;
    Volumen = (4.0/3.0)*M_PI * r *r *r ;
    cout<<"El volumen es: "<<Volumen;
    return 0;

}

