#include <iostream>
using namespace std;

int main() {
    int v[10], n = 0;
    int num;

    cout << "Ingrese numeros (negativo para terminar):" << endl;
    while (n < 10) {
        cin >> num;
        if (num < 0) break;
        v[n++] = num;
    }

    cout << "Vector ingresado: ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}
