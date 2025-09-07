#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

bool esPrimo(int numero);

int main(){
    int numero, x = 1, generador = 0, contador = 0;
    srand(time(NULL));  
    cout << "Ingrese la cantidad de numeros a generar: ";
    cin >> numero;
    while (x <= numero) {
        generador = (rand() % 10000) + 1;   
        if (esPrimo(generador)) {
            cout << generador << " "; 
            contador++;
        }
        x++;
    }
    cout << endl;
    cout << "Cantidad de numeros primos: " << contador << endl;
    return 0;
}
// Definimos una funcion para detectar si los numeros generados son primos
bool esPrimo(int numero) {
    // Si es negativo o 1 no es primo
    if (numero <= 1) return false;
    // Encuentra los divisores del numero si no fuera primo
    for (int i = 2; i <= sqrt(numero); i++) {
        if (numero % i == 0) return false;  
    }
    return true;  
}
