// Materia: Programación I, Paralelo 1
// Autor: Hanns Michael Silva Pardo
// Fecha creación: 20/10/2024
// Número de ejercicio: 7
/*
7. Compresión de datos en una imagen en escala de grises: 
Dada una imagen en escala de grises representada por un vector de N valores entre 0 y 255 
(estos valores deben ser generados aleatoriamente), agrupa los valores en segmentos de 10 unidades 
y muestra cuántos píxeles hay en cada rango.
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int Generar_pixeles(int Limite_Superior, int Limite_Inferior);
vector <int> pixeles_generado(vector <int>& pixeles, int tamanio);
void mostrar(vector <int>& pixeles);

int main(){
    srand(time(NULL));
    vector <int> pixeles;
    int tamanio=0;
    int i=0, a=0;
    cout<<"Ingrese el tamanio del vector: ";
    cin>>tamanio;
    pixeles_generado(pixeles,tamanio);
    mostrar(pixeles);
    cout<<endl;
    //Creamos el vector de contadores (26 rangos)
    vector<int> contador(26,0);
    //Clasificamos cada píxel en su rango
    for(int i = 0; i < tamanio; i++){
        int indice = pixeles[i] / 10; // 0-25
        if(indice > 25) indice = 25;   // por si es 255
        contador[indice]++;
    }
    int inicio = 0;
    int fin = 9;
    for(int i = 0; i < 26; i++){
        cout << inicio << "-" << fin << ": " << contador[i] << " pixeles" << endl;
        inicio += 10;
        fin += 10;
    }
    return 0;
}

int Generar_pixeles(int Limite_Superior, int Limite_Inferior){
    int numero=0;
    numero=(rand()%(Limite_Superior-Limite_Inferior+1))+Limite_Inferior;
    return numero;
}

vector <int> pixeles_generado(vector <int>& pixeles, int tamanio){
    for (int i = 0; i < tamanio; i++)
    {
        pixeles.push_back(Generar_pixeles(255,0));
    }
    return pixeles;
}
void mostrar(vector <int>& pixeles){
    cout<<"Pixeles: ";
    for (int i : pixeles)
    {
        cout<< i<<" ";
    }
}

