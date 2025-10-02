#include <iostream>
#include <vector>
using namespace std;

vector<int> combinar(const vector<int>& a, const vector<int>& b) {
    vector<int> c = a;
    c.insert(c.end(), b.begin(), b.end());
    return c;
}

int main() {
    int n;
    cout << "Dimension de los vectores: ";
    cin >> n;
    vector<int> A(n), B(n);

    cout << "Vector A: ";
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << "Vector B: ";
    for (int i = 0; i < n; i++) cin >> B[i];

    vector<int> C = combinar(A, B);

    cout << "Vector combinado: ";
    for (int x : C) cout << x << " ";
    return 0;
}
