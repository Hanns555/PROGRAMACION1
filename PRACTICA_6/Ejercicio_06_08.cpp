// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 20/10/2024 
// Número de ejercicio: 8
/*
8. Escribe un programa que valide si una cadena ingresada cumple con el formato básico 
de una dirección de correo electrónico (por ejemplo, contiene exactamente un '@' y al 
menos un punto '.' después del '@').  
*/  
#include <iostream>
#include <string>

using namespace std;

void verificacion(string cadena);

int main(){
    string correo;
    cout<<"Ingrese su correo electronico: ";
    getline(cin,correo);
    verificacion(correo);
    return 0;
}

void verificacion(string cadena){
    int a=0, b=0;
    int contador=0;
    char c='@';
    string cadena2="";
    a= cadena.find("@");
    for (char i : cadena)
    {
        if(c==i){
        contador++;}
    }
    if (contador!=1)
    {
        cout<<"Su correo es invalido"<<endl;
    }
    else{
        cadena2=cadena.erase(0,a);
        b= cadena2.find(".");
        if (b<0)
        {
            cout<<"Su correo es invalido"<<endl;
        }
        else{
            cout<<"Su correo es valido"<<endl;
        }
    }
}
