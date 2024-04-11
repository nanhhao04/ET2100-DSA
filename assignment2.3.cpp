#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 1000000;

// Hàm ki?m tra s? nguyên t?
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

// Hàm ki?m tra s? Blum
bool isBlum(int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0 && isPrime(i) && isPrime(num / i)) {
            return true;
        }
    }
    return false;
}

// Hàm t?o m?ng các s? Blum nh? hon N và d?m s? lu?ng
int generateBlumNumbers(int N, int* blumNumbers) {
    int count = 0;
    for (int i = 2; i < N; ++i) {
        if (isBlum(i)) {
            blumNumbers[count++] = i;
        }
    }
    return count;
}

// Hàm ki?m tra c?p s? Blum th?a mãn di?u ki?n
int countBlumPairs(int* blumNumbers, int count) {
    int pairCount = 0;
    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            int sum = blumNumbers[i] + blumNumbers[j];
            if (sum < MAX_N && isBlum(sum)) {
                pairCount++;
            }
        }
    }
    return pairCount;
}

int main() {
    int N = pow(10, 6);
    int* blumNumbers = new int[MAX_N];
    int count = generateBlumNumbers(N, blumNumbers);

    cout << "Tong so Blum nho hon " << N << ": " << count << endl;

    int numBlumPairs = countBlumPairs(blumNumbers, count);
    cout << "So luong cap Blum thoa man dieu kien: " << numBlumPairs << endl;

    int M = 65537;
    if (isBlum(M)) {
        cout << M << " la so Blum." << endl;
    } else {
        cout << M << " khong phai la so Blum." << endl;
    }

    delete[] blumNumbers;

    return 0;
}

