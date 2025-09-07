// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 06/09/2025 
// Número de ejercicio: 2
/*
2. Simular el lanzamiento de una moneda n veces y determinar el porcentaje de 
caras y el porcentaje de cruz. 
*/ 
#include <iostream>
#include <ctime>
using namespace std;
int main(){
    int  x=1, lanzamiento=0;
    double porcentaje_x=0, porcentaje_c=0, contador=0, contador2=0, moneda;
    srand(time(NULL));
    cout<< "Ingrese el numero de veces que lanzara la moneda: ";
    cin>> moneda;
    while(x<= moneda){
        // La moneda solo puede ser cara o cruz por eso utilizamos los residuos de 2 que son 0 o 1
        lanzamiento= (rand()%2)+1;
        x++;
        // El siguiente if hace que si lanzamiento es 1 suma 1 al contador de caras que es el simbolo *
        if(lanzamiento == 1){
        contador2++;
        cout << "* ";}
        // El else hace que todo lo demas aumente el contador de cruz denotado por x
        else {
        contador++;
        cout << "x ";}
    }
    cout<< endl;
    // El siguente bloque calcula el porcentaje de cuantas veces sale cruz y caras
    porcentaje_x = ((contador/moneda)*100);
    porcentaje_c = ((contador2/moneda)*100);
    cout<< "El porcentaje de caras es: "<< porcentaje_c<<"%"<<endl;
    cout<< "El porcentaje de cruz es: "<< porcentaje_x<<"%"<<endl;
    return 0;
}
