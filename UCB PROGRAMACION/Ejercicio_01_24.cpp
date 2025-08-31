// Materia: Programación I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Carnet: 8357097 L.P.
// Carrera del estudiante: Ingeniería Biomedica
// Fecha creación: 29/08/2025
// Número de ejercicio: 24
/*24. Mostrar un menú con opciones:
      1. Opción 1
      2. Opción 2
      3. Opción 3
      0. Salir
      El programa muestra la opción seleccionada y luego el menú hasta que el usuario
      elija 0 (Salir).*/

#include <iostream>
using namespace std;
int main (){
    int opcion_selecionada=-1;
    //Minetras que no se coloque de input 0, se seguira mostrando el menu
    while(opcion_selecionada !=0 ){
    cout<< "1. Opcion 1 "<<endl;
    cout<< "2. Opcion 2 "<<endl;
    cout<< "3. Opcion 3 "<<endl;
    cout<< "0. Salir "<<endl;
    cout<< "Selecione una opcion: ";
    cin>> opcion_selecionada;
    //Aqui comienza para hacer el menu con switch
    switch (opcion_selecionada)
    {
    case 1:
        cout<< "Has selecionado: 1. Opcion 1"<<endl;
        break;
    case 2:
        cout<< "Has selecionado: 2. Opción 2"<<endl;
        break;
    case 3:
        cout<< "Has selecionado: 3. Opción 3"<<endl;
        break;  
    case 0:
        cout<< "Has selecionado: 0.Salir"<<endl;
        break;
    default:
        cout<< "Opcion no valida"<<endl;
        break;
    }}
}