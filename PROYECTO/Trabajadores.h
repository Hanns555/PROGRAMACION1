#include <iostream>
#include <vector>
#include <string.h>
#include <cctype>
#include <sstream>
#include <fstream>

using namespace std;

struct Trabajadores
{
char Nombres [50];
char Apellidos [50];
char Cargo  [40];
int  Nro_CI;
int  Sueldo;
};

vector <Trabajadores> Resgistro_Trabajadores();
bool Validar_Datos_Caracteres(string Datos_Registrados);
bool Validar_Datos_Numericos(string Datos_Registrados );
void Menu_Trabajadores ();


void Imprimir_Vectores_Trabajadores(vector <Trabajadores> Lista_Trabajadores);

//FUNCIONES TRABAJADORES
vector <Trabajadores> Resgistro_Trabajadores()
{
   system ("cls");
   vector <Trabajadores> Lista_Trabajadores;
   Trabajadores Datos_Trabajador;
   string Almacenador_Datos = "";
   int numero_trabajadores = 0;
   bool verificador = true;
   do {
      cout<<"Ingrese cuantos trabajadores desea registrar: ";
      getline(cin, Almacenador_Datos);
      if (Validar_Datos_Numericos(Almacenador_Datos))
      {
      stringstream numeros(Almacenador_Datos);
      numeros>> numero_trabajadores; 
      Almacenador_Datos = "";
      verificador = true;
      }
      else
      {
      cout << "Ingrese un numero para comenzar el registro." << endl;
      Almacenador_Datos = "";
      verificador = false;
      }
      } while (verificador != true);
   for (int i = 0; i < numero_trabajadores; i++)
   {
     cout<<"Ingrese los datos del trabajador ["<<i+1<<"]"<<endl;
     do {
            cout << "Ingrese los nombres del trabajador: ";
            getline(cin, Almacenador_Datos);
            if (Validar_Datos_Caracteres(Almacenador_Datos))
            {
                strcpy(Datos_Trabajador.Nombres, Almacenador_Datos.c_str());
                Almacenador_Datos = "";
                verificador = true;
            }
            else
            {
                cout << "El nombre solo puede contener letras y espacios. Registre denuevo los nombres del trabajador." << endl;
                Almacenador_Datos = "";
                verificador = false;
            }
        } while (verificador != true);
      do {
            cout << "Ingrese los apellidos del trabajador: ";
            getline(cin, Almacenador_Datos);
            if (Validar_Datos_Caracteres(Almacenador_Datos))
            {
                strcpy(Datos_Trabajador.Apellidos, Almacenador_Datos.c_str());
                Almacenador_Datos = "";
                verificador = true;
            }
            else
            {
                cout << "El apellido solo puede contener letras y espacios. Registre denuevo los apellidos del trabajador." << endl;
                Almacenador_Datos = "";
                verificador = false;
            }
        } while (verificador != true);
        do {
            cout << "Ingrese el cargo del trabajador: ";
            getline(cin, Almacenador_Datos);
            if (Validar_Datos_Caracteres(Almacenador_Datos))
            {
                strcpy(Datos_Trabajador.Cargo, Almacenador_Datos.c_str());
                Almacenador_Datos = "";
                verificador = true;
            }
            else
            {
                cout << "El cargo solo puede contener letras y espacios. Registre denuevo el cargo del trabajador." << endl;
                Almacenador_Datos = "";
                verificador = false;
            }
        } while (verificador != true);
        do {
            cout<<"Ingrese el Nro_CI del trabajador: ";
            getline(cin, Almacenador_Datos);
            if (Validar_Datos_Numericos(Almacenador_Datos))
            {
                stringstream numeros(Almacenador_Datos);
                numeros>> Datos_Trabajador.Nro_CI; 
                Almacenador_Datos = "";
                verificador = true;
            }
            else
            {
                cout << "El Nro_CI solo puede contener numeros. Registre denuevo el Nro_CI del trabajador." << endl;
                Almacenador_Datos = "";
                verificador = false;
            }
        } while (verificador != true);
        do {
            cout<<"Ingrese el sueldo del trabajador: ";
            getline(cin, Almacenador_Datos);
            if (Validar_Datos_Numericos(Almacenador_Datos))
            {
                stringstream numeros(Almacenador_Datos);
                numeros>> Datos_Trabajador.Sueldo; 
                Almacenador_Datos = "";
                verificador = true;
            }
            else
            {
                cout << "El sueldo solo puede contener numeros. Registre denuevo el sueldo del trabajador." << endl;
                Almacenador_Datos = "";
                verificador = false;
            }
        } while (verificador != true);
     Lista_Trabajadores.push_back(Datos_Trabajador);
   }
   return Lista_Trabajadores;
}

bool Validar_Datos_Caracteres(string Datos_Registrados )
{
    if (Datos_Registrados.empty()) {
        return false;
    }
    
    for (char c : Datos_Registrados)
    {
        if (!isalpha(c) && !isspace(c))
        {
            return false; 
        }
    }
    return true; 
}

bool Validar_Datos_Numericos(string Datos_Registrados )
{
    if (Datos_Registrados.empty()) {
        return false;
    }
    
    for (char c : Datos_Registrados)
    {
        if (!isdigit(c))
        {
            return false; 
        }
    }
    return true; 
}

//MENU PRINCIPAL DE TRABAJADORES
void Menu_Trabajadores ()
{
   int opcion = 1;
   do
   {
      system("cls");
      cout<<"MENU TRABAJADORES "<<endl;
      cout<<"1. Registrar Trabajadores "<<endl;
      cout<<"2. Listar Trabajadores en un archivo .txt"<<endl;
      cout<<"3. Cargar lista de trabajadores desde un archivo .txt"<<endl;
      cout<<"0. Salir"<<endl;
      cout<<"Ingrese una opcion: ";
      cin>> opcion;
      cin.ignore();
      switch (opcion)
      {
      case 1:
         vector <Trabajadores> Lista_Trabajadores = Resgistro_Trabajadores();
         Imprimir_Vectores_Trabajadores(Lista_Trabajadores);
         system("pause");
         break;
      }
   } while (opcion != 0);
   
}

//FUINCIONES AUXILIARES
void Imprimir_Vectores_Trabajadores(vector <Trabajadores> Lista_Trabajadores)
{
  system("cls");
  for (int i = 0; i < Lista_Trabajadores.size(); i++)
  {
   cout<<"Datos del trabajador ["<<i+1<<"]"<<endl;
   cout<<"Los nombres del trabajador es: "<<Lista_Trabajadores[i].Nombres<<endl;
   cout<<"Los apelidos del trabajador es: "<<Lista_Trabajadores[i].Apellidos<<endl;
   cout<<"El Nro_CI del trabajador es: "<<Lista_Trabajadores[i].Nro_CI<<endl;
   cout<<"El cargo del trabajadr es: "<<Lista_Trabajadores[i].Cargo<<endl;
   cout<<"El sueldo del trabajador es: "<<Lista_Trabajadores[i].Sueldo<<endl;
  }
}