// Materia: Programación I, Paralelo 1 
// Autor: Hanns Michael Silva Pardo. 
// Fecha creación: 19/10/2024 
// Número de ejercicio: 14
/*
14. Realizar el ejercicio de este video (Contando cada vocal en una frase): 
https://www.youtube.com/watch?v=CuQzFZGqTP8 
*/  
#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <vector> 
#include <string>

using namespace std;

int main (){
string frase;
int a=0,e=0,vocal_i=0,o=0,u=0;
cout<<"Ingrese una frase: ";
getline(cin,frase);
for (int i = 0; i < frase.size(); i++)
{
    switch (frase[i])
    {
    case 'a':
        a++;
        break;
    case 'e':
        e++;
        break;
    case 'i':
        vocal_i++;
        break;
    case 'o':
        o++;
        break;
    case 'u':
        u++;
        break;
    default:
        break;
    }
}
cout<<"Vocal a fue encontrada: "<<a<<endl;
cout<<"Vocal e fue encontrada: "<<e<<endl;
cout<<"Vocal i fue encontrada: "<<vocal_i<<endl;
cout<<"Vocal o fue encontrada: "<<o<<endl;
cout<<"Vocal u fue encontrada: "<<u<<endl;
return 0;
}