#include <iostream>

using namespace std;

void stirlingNumbers(int n, int F[20][20]) {
    for (int i = 1; i <= n; ++i) {
        F[i][1] = 1;
        F[i][i] = 1;
    }

    for (int i = 3; i <= n; ++i) {
        for (int j = 2; j < i; ++j) {
            F[i][j] = F[i - 1][j - 1] + j * F[i - 1][j];
        }
    }
}

void bellNumbers(int n, int F[20][20], unsigned long long B[20]) {
    for (int i = 1; i <= n; ++i) {
        B[i] = 0;
        for (int j = 1; j <= i; ++j) {
            B[i] += F[i][j];
        }
    }
}

int main() {
    int variant = 13;

    int n = variant + 5;

    int F[20][20] = { 0 };
    stirlingNumbers(n, F);

    unsigned long long B[20] = { 0 };  // «м≥на на unsigned long long
    bellNumbers(n, F, B);

    cout << "Stirling numbers of the second kind:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nBell numbers:\n";
    for (int i = 1; i <= n; ++i) {
        cout << "B(" << i << ") = " << B[i] << endl;
    }

    return 0;
}

