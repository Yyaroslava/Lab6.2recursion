// Рекурсивний спосіб

#include <iostream> 
#include <iomanip> 
#include <time.h> 

using namespace std;

void Create_r(int* c, const int size, const int Low, const int High, int i) {
   if (i == size) {
        return;
    }
    c[i] = Low + rand() % (High - Low + 1);
    Create_r(c, size, Low, High, i + 1);
}

void Print_r(int* c, const int size, int i) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << c[i];
    Print_r(c, size, i + 1);
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

    Create_r(c, n, Low, High, 0);
    Print_r(c, n, 0);
    cout << "Average = " << Avg_r(c, n, 0) << endl;

    return 0;
}
