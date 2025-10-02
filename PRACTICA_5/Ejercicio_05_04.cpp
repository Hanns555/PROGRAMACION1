#include <iostream>
#include <vector>
using namespace std;

vector<int> multiplicarVectores(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size());
    for (size_t i = 0; i < a.size(); i++) c[i] = a[i] * b[i];
    return c;
}

int main() {
    int n;
    cout << "Dimension de los vectores: ";
    cin >> n;
    vector<int> A(n), B(n);

    cout << "Ingrese valores del vector A:" << endl;
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Ingrese valores del vector B:" << endl;
    for (int i = 0; i < n; i++) cin >> B[i];

    vector<int> C = multiplicarVectores(A, B);

    cout << "Resultado de la multiplicacion:" << endl;
    for (int x : C) cout << x << " ";
    return 0;
}
