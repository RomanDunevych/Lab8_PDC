#include <iostream>
#include <vector>
#include <algorithm>

void print_combinations(int n, int r) {
    // Створюємо початкове r-сполучення {1, 2, ..., r}
    std::vector<int> combination(r);
    for (int i = 0; i < r; ++i) {
        combination[i] = i + 1;
    }

    // Виводимо лексикографічно перше сполучення
    do {
        for (int i = 0; i < r; ++i) {
            std::cout << combination[i] << " ";
        }
        std::cout << std::endl;

        // Алгоритм пошуку наступного r-сполучення
        int i = r - 1;
        while (i >= 0 && combination[i] == n - r + i + 1) {
            --i;
        }

        if (i >= 0) {
            ++combination[i];
            for (int j = i + 1; j < r; ++j) {
                combination[j] = combination[i] + j - i;
            }
        }
        else {
            break; // Завершення генерації
        }

    } while (true);
}

int main() {
    setlocale(LC_ALL, "UKR");

    int n, r;
    std::cout << "Введiть натуральне число n i r (r ≤ n): ";
    std::cin >> n >> r;

    std::cout << "Усi r-сполучення в лексикографiчному порядку:" << std::endl;
    print_combinations(n, r);

    return 0;
}
