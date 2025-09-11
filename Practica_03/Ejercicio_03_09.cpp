// Materia: Programación I, Paralelo 4 
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 LP
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 11/09/2025 
// Ejercicio: 9
#include <iostream>
using namespace std;

double tiempoTrabajado(int minutos){
    double horas = minutos / 60.0;
    return horas - 8.0; //calcula cuántas horas sobran o faltan
}

void mostrarResultado () {
    cout << "Ingrese la cantidad de minutos trabajados" << endl;
    int minutos;
    cin >> minutos; //aquí el usuario mete los minutos trabajados

    double horas = tiempoTrabajado(minutos);

    if(horas == 0){
        cout << "Ha trabajado 8 horas exactas" << endl;
    } else if (horas < 0){
        cout << "Ha trabajado menos horas" << endl;
        cout << "Le debe a la empresa: " << (-1) * horas << " horas de trabajo" << endl;
    } else if (horas > 0){
        cout << "Ha trabajado horas extra" << endl;
        cout << "La empresa le debe pagar " << horas << " horas extra" << endl;
    }
}

int main(){
    mostrarResultado(); //ejecuta la funcion que pide los minutos y muestra el resultado
    return 0;
}