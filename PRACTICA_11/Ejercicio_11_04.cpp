// Materia: Programacion I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creacion: 11/11/2025
// Numero de ejercicio: 4

/*
Descripcion:
El programa guarda estudiantes y sus notas de habilitacion.
Campos:
Carnet, Nombres, Apellidos, Materia, Paralelo
Tres notas de habilitacion.

Reglas:
Todas las notas >= 60 -> HABILITADO
Si alguna es < 60 -> NO HABILITADO

Menu:
1. Adicionar Estudiante
2. Listado de Estudiantes Habilitados
3. Eliminar Estudiante
4. Adicionar Notas de Habilitacion
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void Ejercicio4();

struct Estudiante {
    string carnet;
    string nombres;
    string apellidos;
    string materia;
    int paralelo;

    double nota1;
    double nota2;
    double nota3;

    bool tieneNotas;
};

vector<Estudiante> leerEstudiantes();
void guardarEstudiantes(const vector<Estudiante>& v);
bool existeEstudianteCarnet(const string& carnet);

int main() {
    Ejercicio4();
    return 0;
}

void Ejercicio4() {

    while (true) {
        cout << "\nMENU NOTAS UCB\n";
        cout << "1. Adicionar Estudiante\n";
        cout << "2. Listado de Estudiantes Habilitados\n";
        cout << "3. Eliminar Estudiante\n";
        cout << "4. Adicionar notas habilitacion\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";

        string op;
        getline(cin, op);

        vector<Estudiante> est = leerEstudiantes();

        if (op == "1") {
            Estudiante e;

            cout << "Carnet: ";
            getline(cin, e.carnet);

            if (existeEstudianteCarnet(e.carnet)) {
                cout << "Estudiante ya existe\n";
                continue;
            }

            cout << "Nombres: ";
            getline(cin, e.nombres);

            cout << "Apellidos: ";
            getline(cin, e.apellidos);

            cout << "Materia: ";
            getline(cin, e.materia);

            cout << "Paralelo: ";
            string t; getline(cin, t);
            e.paralelo = stoi(t);

            e.tieneNotas = false;
            e.nota1 = e.nota2 = e.nota3 = 0;

            est.push_back(e);
            guardarEstudiantes(est);

            cout << "Estudiante agregado\n";
        }

        else if (op == "2") {
            if (est.empty()) {
                cout << "No hay estudiantes\n";
                continue;
            }

            double sumaProm = 0;
            int contador = 0;

            cout << "CARNET  NOMBRES  APELLIDOS  MATERIA  PARALELO  PROMEDIO  ESTADO\n";

            for (auto &e : est) {
                if (!e.tieneNotas) {
                    cout << e.carnet << "  " << e.nombres << "  " << e.apellidos
                         << "  " << e.materia << "  " << e.paralelo
                         << "  (sin notas)\n";
                    continue;
                }

                double promedio = (e.nota1 + e.nota2 + e.nota3) / 3.0;
                string estado = (e.nota1 >= 60 && e.nota2 >= 60 && e.nota3 >= 60)
                                ? "HABILITADO"
                                : "NO HABILITADO";

                cout << e.carnet << "  " << e.nombres << "  " << e.apellidos
                     << "  " << e.materia << "  " << e.paralelo
                     << "  " << promedio << "  " << estado << "\n";

                sumaProm += promedio;
                contador++;
            }

            if (contador > 0) {
                cout << "\nPromedio general: " << (sumaProm / contador) << "\n";
            }
        }

        else if (op == "3") {
            cout << "Carnet a eliminar: ";
            string c; getline(cin, c);

            vector<Estudiante> nuevo;
            bool found = false;

            for (auto &e : est) {
                if (e.carnet == c) found = true;
                else nuevo.push_back(e);
            }

            if (!found) {
                cout << "No existe estudiante\n";
            } else {
                guardarEstudiantes(nuevo);
                cout << "Estudiante eliminado\n";
            }
        }

        else if (op == "4") {
            cout << "Carnet: ";
            string c; getline(cin, c);

            bool found = false;

            for (auto &e : est) {
                if (e.carnet == c) {
                    found = true;

                    cout << "Nota 1: ";
                    string t; getline(cin, t);
                    e.nota1 = stod(t);

                    cout << "Nota 2: ";
                    getline(cin, t);
                    e.nota2 = stod(t);

                    cout << "Nota 3: ";
                    getline(cin, t);
                    e.nota3 = stod(t);

                    e.tieneNotas = true;
                    break;
                }
            }

            if (!found) cout << "No existe estudiante\n";
            else {
                guardarEstudiantes(est);
                cout << "Notas guardadas\n";
            }
        }

        else if (op == "5") break;
        else cout << "Opcion invalida\n";
    }
}

vector<Estudiante> leerEstudiantes() {
    vector<Estudiante> v;
    ifstream f("ESTUDIANTES.BIN", ios::binary);

    if (!f.is_open()) return v;

    while (f.peek() != EOF) {
        Estudiante e;
        size_t t;
        char buffer[200];

        // Carnet
        f.read((char*)&t, sizeof(t));
        f.read(buffer, t);
        e.carnet = string(buffer, t);

        // Nombres
        f.read((char*)&t, sizeof(t));
        f.read(buffer, t);
        e.nombres = string(buffer, t);

        // Apellidos
        f.read((char*)&t, sizeof(t));
        f.read(buffer, t);
        e.apellidos = string(buffer, t);

        // Materia
        f.read((char*)&t, sizeof(t));
        f.read(buffer, t);
        e.materia = string(buffer, t);

        // Paralelo
        f.read((char*)&e.paralelo, sizeof(e.paralelo));

        // Notas
        f.read((char*)&e.nota1, sizeof(e.nota1));
        f.read((char*)&e.nota2, sizeof(e.nota2));
        f.read((char*)&e.nota3, sizeof(e.nota3));

        // Tiene notas
        f.read((char*)&e.tieneNotas, sizeof(e.tieneNotas));

        v.push_back(e);
    }

    return v;
}

void guardarEstudiantes(const vector<Estudiante>& v) {
    ofstream f("ESTUDIANTES.BIN", ios::binary | ios::trunc);

    for (auto &e : v) {
        size_t t;

        t = e.carnet.size();
        f.write((char*)&t, sizeof(t));
        f.write(e.carnet.c_str(), t);

        t = e.nombres.size();
        f.write((char*)&t, sizeof(t));
        f.write(e.nombres.c_str(), t);

        t = e.apellidos.size();
        f.write((char*)&t, sizeof(t));
        f.write(e.apellidos.c_str(), t);

        t = e.materia.size();
        f.write((char*)&t, sizeof(t));
        f.write(e.materia.c_str(), t);

        f.write((char*)&e.paralelo, sizeof(e.paralelo));

        f.write((char*)&e.nota1, sizeof(e.nota1));
        f.write((char*)&e.nota2, sizeof(e.nota2));
        f.write((char*)&e.nota3, sizeof(e.nota3));

        f.write((char*)&e.tieneNotas, sizeof(e.tieneNotas));
    }
}

bool existeEstudianteCarnet(const string& carnet) {
    vector<Estudiante> v = leerEstudiantes();
    for (auto &e : v) if (e.carnet == carnet) return true;
    return false;
}
