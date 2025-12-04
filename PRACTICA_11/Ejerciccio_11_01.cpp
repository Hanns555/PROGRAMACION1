// Materia: Programacion I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creacion: 04/12/2025
// Numero de ejercicio: 1

/*
Descripcion:
Programa con menu:
1. Ingreso de estudiantes
2. Ingreso de notas
3. Reporte
Usa archivos binarios Estudiantes.bin y Notas.bin
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante {
    string ci;
    string nombres;
    string apellidos;
};

struct Nota {
    string ci;
    string materia;
    int nota;
};

void Ejercicio1();
void guardarEstudiante(const Estudiante&);
bool existeEstudiante(const string&);
void guardarNota(const Nota&);
bool existeNota(const string&, const string&);
vector<Estudiante> leerEstudiantes();
vector<Nota> leerNotas();

int main() {
    Ejercicio1();
    return 0;
}

void Ejercicio1() {

    while (true) {
        cout << "\nMENU\n";
        cout << "1. Ingreso de datos estudiantes\n";
        cout << "2. Ingreso de materias y notas\n";
        cout << "3. Reporte de estudiantes y notas\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";

        string op;
        getline(cin, op);

        if (op == "1") {
            Estudiante e;
            cout << "CI: "; getline(cin, e.ci);
            if (existeEstudiante(e.ci)) {
                cout << "Estudiante ya existe\n";
                continue;
            }
            cout << "Nombres: "; getline(cin, e.nombres);
            cout << "Apellidos: "; getline(cin, e.apellidos);

            guardarEstudiante(e);
            cout << "Guardado\n";
        }

        else if (op == "2") {
            Nota n;
            cout << "CI estudiante: "; getline(cin, n.ci);

            if (!existeEstudiante(n.ci)) {
                cout << "No existe estudiante\n";
                continue;
            }

            cout << "Materia: "; getline(cin, n.materia);

            if (existeNota(n.ci, n.materia)) {
                cout << "Ya existe nota para esa materia\n";
                continue;
            }

            cout << "Nota: ";
            string t; getline(cin, t);
            n.nota = stoi(t);

            guardarNota(n);
            cout << "Nota guardada\n";
        }

        else if (op == "3") {
            auto est = leerEstudiantes();
            auto nots = leerNotas();

            for (auto &e : est) {
                cout << "\nCI: " << e.ci << " - " << e.nombres << " " << e.apellidos << "\n";
                cout << "Notas:\n";
                bool encontrado = false;

                for (auto &n : nots) {
                    if (n.ci == e.ci) {
                        cout << "  " << n.materia << ": " << n.nota << "\n";
                        encontrado = true;
                    }
                }
                if (!encontrado) cout << "  Sin notas\n";
            }
        }

        else if (op == "4") {
            break;
        }

        else {
            cout << "Opcion invalida\n";
        }
    }
}

void guardarEstudiante(const Estudiante& e) {
    ofstream arch("Estudiantes.bin", ios::binary | ios::app);
    size_t t;

    t = e.ci.size(); arch.write((char*)&t, sizeof(t)); arch.write(e.ci.c_str(), t);
    t = e.nombres.size(); arch.write((char*)&t, sizeof(t)); arch.write(e.nombres.c_str(), t);
    t = e.apellidos.size(); arch.write((char*)&t, sizeof(t)); arch.write(e.apellidos.c_str(), t);
}

void guardarNota(const Nota& n) {
    ofstream arch("Notas.bin", ios::binary | ios::app);
    size_t t;

    t = n.ci.size(); arch.write((char*)&t, sizeof(t)); arch.write(n.ci.c_str(), t);
    t = n.materia.size(); arch.write((char*)&t, sizeof(t)); arch.write(n.materia.c_str(), t);
    arch.write((char*)&n.nota, sizeof(n.nota));
}

bool existeEstudiante(const string& ci) {
    auto v = leerEstudiantes();
    for (auto &e : v) if (e.ci == ci) return true;
    return false;
}

bool existeNota(const string& ci, const string& mat) {
    auto v = leerNotas();
    for (auto &n : v) if (n.ci == ci && n.materia == mat) return true;
    return false;
}

vector<Estudiante> leerEstudiantes() {
    vector<Estudiante> v;
    ifstream arch("Estudiantes.bin", ios::binary);
    if (!arch.is_open()) return v;

    while (arch.peek() != EOF) {
        Estudiante e;
        size_t t;
        char buffer[200];

        // CI
        arch.read((char*)&t, sizeof(t));
        arch.read(buffer, t);
        e.ci = string(buffer, t);

        // nombres
        arch.read((char*)&t, sizeof(t));
        arch.read(buffer, t);
        e.nombres = string(buffer, t);

        // apellidos
        arch.read((char*)&t, sizeof(t));
        arch.read(buffer, t);
        e.apellidos = string(buffer, t);

        v.push_back(e);
    }
    return v;
}

vector<Nota> leerNotas() {
    vector<Nota> v;
    ifstream arch("Notas.bin", ios::binary);
    if (!arch.is_open()) return v;

    while (arch.peek() != EOF) {
        Nota n;
        size_t t;
        char buffer[200];

        arch.read((char*)&t, sizeof(t));
        arch.read(buffer, t);
        n.ci = string(buffer, t);

        arch.read((char*)&t, sizeof(t));
        arch.read(buffer, t);
        n.materia = string(buffer, t);

        arch.read((char*)&n.nota, sizeof(n.nota));

        v.push_back(n);
    }
    return v;
}
