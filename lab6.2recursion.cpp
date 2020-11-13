// Рекурсивний спосіб

#include <iostream> 
#include <iomanip> 
#include <time.h> 

using namespace std;

void Create(int* c, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        c[i] = Low + rand() % (High - Low + 1);
}

void Print(int* c, const int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << c[i];
    cout << endl;
}

double Avg_r(int* c, const int size, int i) {
    if (i == size)  return 0;
    double S = Avg_r(c, size, i + 1);
    if (i % 2 == 0) S += c[i];
    if (i == 0)  return S / ((size + 1) / 2);
    return S;
}

int main() {
    srand((unsigned)time(NULL));  // ініціалізація генератора випадкових чисел  
    const int n = 11;
    int c[n];

    int Low = 15;
    int High = 85;

    Create(c, n, Low, High);
    Print(c, n);
    cout << "Average = " << Avg_r(c, n, 0) << endl;

    return 0;
}
