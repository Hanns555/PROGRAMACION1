// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 LP
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 11/09/2025 
// Ejercicio: 11
#include <iostream>
using namespace std;

double retirarDinero (double saldo, int cantidad){
    if(saldo < cantidad){
        cout << "No tiene saldo suficiente" << endl;
        return 0.0; //cuando no alcanza la plata
    }

    if(cantidad % 10 != 0){
        cout << "La cantidad no es valida para retirar" << endl;
        return 0.0; //solo se puede sacar múltiplos de 10
    }

    cout << "El retiro es valido" << endl;
    return saldo - cantidad; //nuevo saldo después del retiro
}

int main(){
    double saldo;
    int cantidad;
    cout << "Ingrese el saldo: " << endl;
    cin >> saldo;
    cout << "Ingrese la cantidad a retirar" << endl;
    cin >> cantidad; //el usuario mete cuánto quiere retirar

    double nuevoSaldo = retirarDinero(saldo, cantidad);

    if(nuevoSaldo == 0){
        cout << "No se realizo la transaccion" << endl;
    } else {
        cout << "Su saldo actual es de: " << nuevoSaldo << endl;
    }
    return 0;
}
