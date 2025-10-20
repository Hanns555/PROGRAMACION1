// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 12/10/2024 
// Número de ejercicio: 2
/*
2. Un arreglo constante contiene la producción en toneladas métricas de 6 minerales, y 
   otro contiene los nombres de estos minerales, para obtener: 
    • Buscar por nombre de mineral y desplegar la producción 
    • Ordenar del mayor al menor (producción) y mostrar: 
*/      

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include <algorithm>

using namespace std;
void menu(int x, vector<string>minerales_v, vector<double>produccion_toneladas);
int main(){
    system("cls");
    double produccion;
    int a=0;
    double mayor;
    string minerals;
    string n;
    vector<double>produccion_toneladas;
    vector<string>minerales_v;
    string minerales;
    string toneladas;
    cout<< "Ingrese el nombre de los mineales (max. 6): ";
    getline(cin, minerales);
    stringstream sm(minerales);
    while (sm>>minerals)
    {
        minerales_v.push_back(minerals);
    }
    cout<< "Ingrese la cantidad en toneladas de cada mineral: ";
    getline(cin, toneladas);
    stringstream ss(toneladas);
    while (ss>>produccion)
    {
        produccion_toneladas.push_back(produccion);
    }
    system("cls");
    cout<< "Ingrese el mineral que desea ver su produccion ("<<minerales<<"): ";
    cin>> n;
    auto it = find(minerales_v.begin(), minerales_v.end(), n);
    a=(it - minerales_v.begin());
    menu(a,minerales_v,produccion_toneladas);
    return 0;
}
void menu(int x, vector<string>minerales_v, vector<double>produccion_toneladas){
     switch (x)
    {
    case 0:
        cout<< "La produccion de "<<minerales_v[0]<<" es " <<produccion_toneladas[0]<<" toneladas";
        break;
    case 1:
        cout<< "La produccion de "<<minerales_v[1]<<" es " <<produccion_toneladas[1]<<" toneladas";
        break;
    case 2:
        cout<< "La produccion de "<<minerales_v[2]<<" es " <<produccion_toneladas[2]<<" toneladas";
        break;
    case 3:
        cout<< "La produccion de "<<minerales_v[3]<<" es " <<produccion_toneladas[3]<<" toneladas";
        break;
    case 4:
        cout<< "La produccion de "<<minerales_v[4]<<" es " <<produccion_toneladas[4]<<" toneladas";
        break;
    case 5:
        cout<< "La produccion de "<<minerales_v[5]<<" es " <<produccion_toneladas[5]<<" toneladas";
        break;
    default:
        // Combinar minerales y producciones en un solo vector de pares
        vector<pair<double, string>> combinado;
        for (int i = 0; i < minerales_v.size(); i++) {
            combinado.push_back(make_pair(produccion_toneladas[i], minerales_v[i]));
        }

        // Ordenar de mayor a menor (por producción, que es .first)
        sort(combinado.begin(), combinado.end(), 
             [](const pair<double, string>& a, const pair<double, string>& b) {
                 return a.first > b.first;
             });

        // Mostrar encabezado
        cout << "\tMineral"<<"      "<<"Produccion" << endl;
        cout << "\t----------------------------------" << endl;

        // Mostrar cada mineral con su produccion ordenada
        for (const auto& item : combinado) {
            cout << "\t  "<<item.second << "            " << item.first << " toneladas" << endl;
        }
        break;
    }
}