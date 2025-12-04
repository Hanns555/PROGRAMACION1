// Materia: Programacion I, Paralelo 4
// Autor: Hanns Michael Silva Pardo
// Fecha creacion: 04/12/2025
// Numero de ejercicio: 3

/*
Descripcion:
Pizzeria ELIS necesita registrar pizzas:
Codigo, Nombre, Tipo (TRADICIONAL/ESPECIAL), Tamano, Precio

Archivo binario: PRODUCTO.BIN
Archivo de ventas: VENTAS.TXT

Menu:
1. Adicionar Pizza
2. Listado de Pizzas
3. Modificar precio de Pizza
4. Eliminar Pizza
5. Registrar Venta de Pizza

La pizza ESPECIAL incrementa 10% el precio de la TRADICIONAL.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void Ejercicio3();

struct Pizza {
    int codigo;
    string nombre;
    string tipo;
    string tamano;
    double precio;
};

vector<Pizza> leerPizzas();
void guardarPizzas(const vector<Pizza>& v);
bool existeCodigoPizza(int cod);
void guardarVentaPizza(const string& carnet, int cod, const string& tamano, int cantidad);

int main() {
    Ejercicio3();
    return 0;
}

void Ejercicio3() {
    while (true) {

        cout << "\nMENU PIZZERIA ELIS\n";
        cout << "1. Adicionar Pizza\n";
        cout << "2. Listado de Pizzas\n";
        cout << "3. Modificar precio de Pizza\n";
        cout << "4. Eliminar Pizza\n";
        cout << "5. Registrar Venta\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";

        string op;
        getline(cin, op);

        vector<Pizza> pizzas = leerPizzas();

        if (op == "1") {
            Pizza p;

            cout << "Codigo: ";
            string t; getline(cin, t);
            p.codigo = stoi(t);

            if (existeCodigoPizza(p.codigo)) {
                cout << "Codigo ya existe\n";
                continue;
            }

            cout << "Nombre: "; getline(cin, p.nombre);
            cout << "Tipo (TRADICIONAL/ESPECIAL): "; getline(cin, p.tipo);
            cout << "Tamano: "; getline(cin, p.tamano);
            cout << "Precio base (para tradicional): ";
            getline(cin, t);
            p.precio = stod(t);

            pizzas.push_back(p);
            guardarPizzas(pizzas);

            cout << "Pizza agregada\n";
        }

        else if (op == "2") {
            // Leer ventas
            ifstream vt("VENTAS.TXT");
            vector<int> codigos;
            vector<int> cantidades;

            if (vt.is_open()) {
                string linea;
                while (getline(vt, linea)) {
                    stringstream ss(linea);
                    string part;
                    vector<string> P;

                    while (getline(ss, part, ';')) {
                        size_t a = 0; while (a < part.size() && isspace((unsigned char)part[a])) a++;
                        size_t b = part.size(); while (b > a && isspace((unsigned char)part[b-1])) b--;
                        P.push_back(part.substr(a, b-a));
                    }

                    if (P.size() >= 4) {
                        int c = stoi(P[1]);
                        int q = stoi(P[3]);
                        bool found = false;

                        for (size_t i=0;i<codigos.size();i++) {
                            if (codigos[i] == c) {
                                cantidades[i] += q;
                                found = true;
                                break;
                            }
                        }

                        if (!found) {
                            codigos.push_back(c);
                            cantidades.push_back(q);
                        }
                    }
                }
            }

            cout << "CODIGO  NOMBRE  TIPO  TAMANO  PRECIO  VENDIDOS  TOTAL\n";

            for (auto &p : pizzas) {
                int vendidos = 0;

                for (size_t i=0;i<codigos.size();i++) {
                    if (codigos[i] == p.codigo) vendidos = cantidades[i];
                }

                double precioFinal = p.precio;

                if (p.tipo == "ESPECIAL") precioFinal = p.precio * 1.10;

                double total = precioFinal * vendidos;

                cout << p.codigo << "  "
                     << p.nombre << "  "
                     << p.tipo << "  "
                     << p.tamano << "  "
                     << precioFinal << "  "
                     << vendidos << "  "
                     << total << "\n";
            }
        }

        else if (op == "3") {
            cout << "Codigo: ";
            string t; getline(cin, t);
            int cod = stoi(t);

            bool found = false;

            for (auto &p : pizzas) {
                if (p.codigo == cod) {
                    found = true;
                    cout << "Nuevo precio base: ";
                    getline(cin, t);
                    p.precio = stod(t);
                    break;
                }
            }

            if (!found) cout << "No existe\n";
            else {
                guardarPizzas(pizzas);
                cout << "Precio modificado\n";
            }
        }

        else if (op == "4") {
            cout << "Codigo a eliminar: ";
            string t; getline(cin, t);
            int cod = stoi(t);

            bool found = false;
            vector<Pizza> nuevo;

            for (auto &p : pizzas) {
                if (p.codigo == cod) found = true;
                else nuevo.push_back(p);
            }

            if (!found) cout << "No existe\n";
            else {
                guardarPizzas(nuevo);
                cout << "Pizza eliminada\n";
            }
        }

        else if (op == "5") {
            string carnet, tamano;
            cout << "Carnet cliente: "; getline(cin, carnet);

            cout << "Codigo pizza: ";
            string t; getline(cin, t);
            int cod = stoi(t);

            if (!existeCodigoPizza(cod)) {
                cout << "No existe esa pizza\n";
                continue;
            }

            cout << "Tamano: "; getline(cin, tamano);

            cout << "Cantidad: ";
            getline(cin, t);
            int cant = stoi(t);

            guardarVentaPizza(carnet, cod, tamano, cant);

            cout << "Venta registrada\n";
        }

        else if (op == "6") break;
        else cout << "Opcion invalida\n";
    }
}

vector<Pizza> leerPizzas() {
    vector<Pizza> v;
    ifstream f("PRODUCTO.BIN", ios::binary);

    if (!f.is_open()) return v;

    while (f.peek() != EOF) {
        Pizza p;
        size_t t;
        char buffer[200];

        f.read((char*)&p.codigo, sizeof(p.codigo));

        f.read((char*)&t, sizeof(t));
        f.read(buffer, t);
        p.nombre = string(buffer, t);

        f.read((char*)&t, sizeof(t));
        f.read(buffer, t);
        p.tipo = string(buffer, t);

        f.read((char*)&t, sizeof(t));
        f.read(buffer, t);
        p.tamano = string(buffer, t);

        f.read((char*)&p.precio, sizeof(p.precio));

        v.push_back(p);
    }
    return v;
}

void guardarPizzas(const vector<Pizza>& v) {
    ofstream f("PRODUCTO.BIN", ios::binary | ios::trunc);

    for (auto &p : v) {
        size_t t;

        f.write((char*)&p.codigo, sizeof(p.codigo));

        t = p.nombre.size();
        f.write((char*)&t, sizeof(t));
        f.write(p.nombre.c_str(), t);

        t = p.tipo.size();
        f.write((char*)&t, sizeof(t));
        f.write(p.tipo.c_str(), t);

        t = p.tamano.size();
        f.write((char*)&t, sizeof(t));
        f.write(p.tamano.c_str(), t);

        f.write((char*)&p.precio, sizeof(p.precio));
    }
}

bool existeCodigoPizza(int cod) {
    vector<Pizza> v = leerPizzas();
    for (auto &p : v) if (p.codigo == cod) return true;
    return false;
}

void guardarVentaPizza(const string& carnet, int cod, const string& tamano, int cantidad) {
    ofstream f("VENTAS.TXT", ios::app);
    f << carnet << "; " << cod << "; " << tamano << "; " << cantidad << "\n";
}
