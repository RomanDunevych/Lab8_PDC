#include <iostream>
#include <algorithm> 

using namespace std;

void performSetOperations() {

    setlocale(LC_ALL, "UKR");

    int n;
    cout << "Введiть кiлькiсть елементiв унiверсуму U: ";
    cin >> n;

    int U[100], A[100], B[100];
    int Abit[100] = { 0 }, Bbit[100] = { 0 };

    cout << "Введiть елементи унiверсуму U: ";
    for (int i = 0; i < n; ++i) {
        cin >> U[i];
    }

    // Впорядковуємо універсум
    sort(U, U + n);

    int ka;
    cout << "Введiть кiлькiсть елементiв множини A: ";
    cin >> ka;

    cout << "Введiть елементи множини A: ";
    for (int i = 0; i < ka; ++i) {
        cin >> A[i];
    }

    int kb;
    cout << "Введiть кiлькiсть елементiв множини B: ";
    cin >> kb;

    cout << "Введiть елементи множини B: ";
    for (int i = 0; i < kb; ++i) {
        cin >> B[i];
    }

    // Створюємо бітовий рядок для множини A
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < ka; ++j) {
            if (U[i] == A[j]) {
                Abit[i] = 1;
                break;
            }
        }
    }

    // Створюємо бітовий рядок для множини B
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < kb; ++j) {
            if (U[i] == B[j]) {
                Bbit[i] = 1;
                break;
            }
        }
    }

    // Операції
    int notA[100], AperB[100], AobB[100], ArizB[100], AxorB[100];

    for (int i = 0; i < n; ++i) {
        notA[i] = 1 - Abit[i];            // Доповнення множини A
        AperB[i] = Abit[i] & Bbit[i];     // Перетин A і B
        AobB[i] = Abit[i] | Bbit[i];      // Об'єднання A і B
        ArizB[i] = Abit[i] & ~Bbit[i];    // Різниця A \ B
        AxorB[i] = Abit[i] ^ Bbit[i];     // Симетрична різниця A ⊕ B
    }

    // Виведення результатів
    cout << "Бiтовий рядок A: ";
    for (int i = 0; i < n; ++i) {
        cout << Abit[i] << " ";
    }

    cout << "\nБiтовий рядок B: ";
    for (int i = 0; i < n; ++i) {
        cout << Bbit[i] << " ";
    }

    cout << "\nnot A: ";
    for (int i = 0; i < n; ++i) {
        cout << notA[i] << " ";
    }

    cout << "\nA перетин B: ";
    for (int i = 0; i < n; ++i) {
        cout << AperB[i] << " ";
    }

    cout << "\nA об'єднання B: ";
    for (int i = 0; i < n; ++i) {
        cout << AobB[i] << " ";
    }

    cout << "\nA \\ B: ";
    for (int i = 0; i < n; ++i) {
        cout << ArizB[i] << " ";
    }

    cout << "\nA ⊕ B: ";
    for (int i = 0; i < n; ++i) {
        cout << AxorB[i] << " ";
    }

    cout << endl;
}

int main() {
    performSetOperations();
    return 0;
}
