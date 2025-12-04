// Materia: Programacion I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creacion: 04/12/2025
// Numero de ejercicio: 2

/*
Descripcion:
Registrar productos en PRODUCTOS.BIN
Registrar ventas en VENTAS.txt
Menu:
1. Adicionar Producto
2. Listado de Productos
3. Buscar un producto
4. Modificar un producto
5. Adicionar venta
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void Ejercicio2();

struct Producto {
    int codigo;
    string nombre;
    int cantidad;
    double precio;
};

vector<Producto> leerProductos();
void guardarProductos(const vector<Producto>&);
bool existeCodigo(int codigo);
void guardarVentaTXT(int codigo, int cantidad, const string& ci, const string& nombreCliente);

int main() {
    Ejercicio2();
    return 0;
}

void Ejercicio2() {
    while (true) {

        cout << "\nMENU FARMACIA CHAVEZ\n";
        cout << "1. Adicionar Producto\n";
        cout << "2. Listado de Productos\n";
        cout << "3. Buscar por codigo\n";
        cout << "4. Modificar producto\n";
        cout << "5. Registrar venta\n";
        cout << "6. Salir\nOpcion: ";

        string op;
        getline(cin, op);

        // Cargar productos
        vector<Producto> productos = leerProductos();

        if (op == "1") {
            Producto p;
            cout << "Codigo: ";
            string t; getline(cin, t);
            p.codigo = stoi(t);

            if (existeCodigo(p.codigo)) {
                cout << "Ya existe ese codigo\n";
                continue;
            }

            cout << "Nombre: "; getline(cin, p.nombre);
            cout << "Cantidad inicial: "; getline(cin, t); p.cantidad = stoi(t);
            cout << "Precio unitario: "; getline(cin, t); p.precio = stod(t);

            productos.push_back(p);
            guardarProductos(productos);

            cout << "Producto agregado\n";
        }

        else if (op == "2") {
            // Leer ventas
            ifstream vs("VENTAS.txt");
            vector<int> cods;
            vector<int> cants;

            if (vs.is_open()) {
                string linea;
                while (getline(vs, linea)) {
                    stringstream ss(linea);
                    string part;
                    vector<string> P;

                    while (getline(ss, part, ';')) {
                        // quitar espacios
                        size_t a = 0; while (a < part.size() && isspace((unsigned char)part[a])) a++;
                        size_t b = part.size(); while (b > a && isspace((unsigned char)part[b-1])) b--;
                        P.push_back(part.substr(a, b-a));
                    }

                    if (P.size() >= 4) {
                        int c = stoi(P[2]);
                        int q = stoi(P[3]);
                        bool found = false;

                        for (size_t i=0;i<cods.size();i++) {
                            if (cods[i] == c) {
                                cants[i] += q;
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cods.push_back(c);
                            cants.push_back(q);
                        }
                    }
                }
            }

            cout << "CODIGO  NOMBRE  CANTIDAD  PRECIO  VENDIDOS  TOTAL\n";
            for (auto &p : productos) {
                int vendido = 0;

                for (size_t i=0;i<cods.size();i++) {
                    if (cods[i] == p.codigo) vendido = cants[i];
                }

                double total = vendido * p.precio;

                cout << p.codigo << "  "
                     << p.nombre << "  "
                     << p.cantidad << "  "
                     << p.precio << "  "
                     << vendido << "  "
                     << total << "\n";
            }
        }

        else if (op == "3") {
            cout << "Codigo: ";
            string t; getline(cin, t);
            int cod = stoi(t);

            bool found = false;
            for (auto &p : productos) {
                if (p.codigo == cod) {
                    found = true;
                    cout << "Producto encontrado:\n";
                    cout << "Nombre: " << p.nombre << "\n";
                    cout << "Cantidad: " << p.cantidad << "\n";
                    cout << "Precio: " << p.precio << "\n";
                    break;
                }
            }
            if (!found) cout << "No existe producto\n";
        }

        else if (op == "4") {
            cout << "Codigo: ";
            string t; getline(cin, t);
            int cod = stoi(t);

            bool found = false;
            for (auto &p : productos) {
                if (p.codigo == cod) {
                    found = true;
                    cout << "Nuevo nombre (enter mantiene): ";
                    string x; getline(cin, x);
                    if (!x.empty()) p.nombre = x;

                    cout << "Nueva cantidad (enter mantiene): ";
                    getline(cin, x);
                    if (!x.empty()) p.cantidad = stoi(x);

                    cout << "Nuevo precio (enter mantiene): ";
                    getline(cin, x);
                    if (!x.empty()) p.precio = stod(x);

                    break;
                }
            }

            if (!found) cout << "No existe\n";
            else {
                guardarProductos(productos);
                cout << "Producto modificado\n";
            }
        }

        else if (op == "5") {
            string ci, nom;
            cout << "CI cliente: "; getline(cin, ci);
            cout << "Nombre cliente: "; getline(cin, nom);

            cout << "Codigo producto: ";
            string t; getline(cin, t);
            int cod = stoi(t);

            if (!existeCodigo(cod)) {
                cout << "No existe producto\n";
                continue;
            }

            cout << "Cantidad: ";
            getline(cin, t);
            int cant = stoi(t);

            guardarVentaTXT(cod, cant, ci, nom);

            cout << "Venta registrada\n";
        }

        else if (op == "6") break;
        else cout << "Opcion invalida\n";
    }
}

vector<Producto> leerProductos() {
    vector<Producto> v;
    ifstream f("PRODUCTOS.BIN", ios::binary);
    if (!f.is_open()) return v;

    while (f.peek() != EOF) {
        Producto p;
        size_t t;
        char buffer[200];

        f.read((char*)&p.codigo, sizeof(p.codigo));

        f.read((char*)&t, sizeof(t));
        f.read(buffer, t);
        p.nombre = string(buffer, t);

        f.read((char*)&p.cantidad, sizeof(p.cantidad));
        f.read((char*)&p.precio, sizeof(p.precio));

        v.push_back(p);
    }
    return v;
}

void guardarProductos(const vector<Producto> &v) {
    ofstream f("PRODUCTOS.BIN", ios::binary | ios::trunc);

    for (auto &p : v) {
        size_t t;

        f.write((char*)&p.codigo, sizeof(p.codigo));

        t = p.nombre.size();
        f.write((char*)&t, sizeof(t));
        f.write(p.nombre.c_str(), t);

        f.write((char*)&p.cantidad, sizeof(p.cantidad));
        f.write((char*)&p.precio, sizeof(p.precio));
    }
}

bool existeCodigo(int codigo) {
    vector<Producto> v = leerProductos();
    for (auto &p : v) if (p.codigo == codigo) return true;
    return false;
}

void guardarVentaTXT(int codigo, int cantidad, const string& ci, const string& nombreCliente) {
    ofstream v("VENTAS.txt", ios::app);
    v << ci << "; " << nombreCliente << "; " << codigo << "; " << cantidad << "\n";
}
