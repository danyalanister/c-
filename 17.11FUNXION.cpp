#include <iostream>
using namespace std;

//Задание 1
void printRectangle(int N, int K) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

//Задание 2
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

//Задание 3
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

//Задание4
double cube(double x) {
    return x * x * x;
}

//Задание5
int maxOfTwo(int a, int b) {
    return (a > b) ? a : b;
}

//Задание6
bool isPositive(int x) {
    return x > 0;
}
