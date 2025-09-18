// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 18/09/2025 
// Número de ejercicio: 7
/*
7. Sean los datos m y n enteros positivos. Elabore un diagrama de flujo para calcular el 
Máximo Común Divisor y el Mínimo Común Múltiplo de m y n. El Algoritmo de Euclides 
establece que, si m>=n, MCD(m,n) = MCD(n, m mod n).    
*/
#include <iostream>
using namespace std;
int mcd(int a, int b);
int mcm(int a, int b);
int main() {
    int numero_1=0, numero_2=0;
    cout << "Ingrese un numero_1: ";
    cin >> numero_1;
    cout << "Ingrese un numero_2: ";
    cin >> numero_2;
    // Calcular MCD
    int max_comun_divisor = mcd(numero_1, numero_2);
    // Calcular MCM
    int min_comun_multiplo = mcm(numero_1, numero_2);
    cout << "MCD(" << numero_1 << ", " << numero_2 << ") = " << max_comun_divisor << endl;
    cout << "MCM(" << numero_1 << ", " << numero_2 << ") = " << min_comun_multiplo << endl;
    return 0;
}
//Función para calcular el MCD usando el Algoritmo de Euclides
int mcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
//Función para calcular el MCM usando la fórmula: MCM(a,b) = (a * b) / MCD(a,b)
int mcm(int a, int b) {
    return (a * b) / mcd(a,b);
}
