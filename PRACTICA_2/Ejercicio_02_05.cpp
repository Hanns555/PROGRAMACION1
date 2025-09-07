// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo 
// Carnet: 8357097 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 06/09/2025 
// Número de ejercicio: 5
/*
5. Genere N números aleatorios entre 1 y 1000 y realice los siguientes cálculos: 
a. Sumatoria de todos los números 
b. Promedio 
c. Mayor valor generado 
d. Menor valor generado 
*/ 
#include <iostream>
#include <ctime>
using namespace std;
int main(){
    srand(time(NULL));
    int numero, x=1, random=0, maximo=0, minimo=0;
    double sumatoria=0, promedio=0;
    cout<< "Ingrese la cantidad de numeros aleatorios a generar: ";
    cin>> numero;
    // El siguiente while genera numeros randoms numero-veces 
    while(x<=numero){
        // El umero solo puede ser entre 1-1000
        random=(rand()%1000)+1;
        sumatoria+=random;        
        promedio= sumatoria/ numero;
        // El siguiente bloque hace que detecte los maximos y minimos de los numeros generados
        if(x == 1){
          maximo = random;
          minimo = random;}
        if(random > maximo){
          maximo = random;}
        if(random < minimo){
          minimo = random;}
        x++;
    }
    cout<< endl;
    cout<< "a. Sumatoria de todos los numeros: "<< sumatoria<< endl;
    cout<< "b. Promedio: "<<promedio<< endl;
    cout<< "c. Mayor valor generado: "<<maximo<< endl;
    cout<< "d. Menor valor generado: "<<minimo<< endl;
    return 0;
}
