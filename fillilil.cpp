#include <iostream>

using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))

#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define SQUARE(x) ((x) * (x))

#define POWER(x, n) ({\
    double result = 1.0;\
    int _n = (n);\
    double _x = (x);\
    for(int i = 0; i < _n; i++) {\
        result *= _x;\
    }\
    result;\
})

#define IS_EVEN(x) ((x) % 2 == 0)

#define IS_ODD(x) ((x) % 2 != 0)

#define POWER_SAFE(x, n) pow_safe(x, n)
inline double pow_safe(double x, int n) {
    double result = 1.0;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

int main() {

    cout << "=== Демонстрация работы макросов ===\n" << endl;

    int a = 10, b = 20;
    cout << "MIN(" << a << ", " << b << ") = " << MIN(a, b) << endl;
    cout << "MAX(" << a << ", " << b << ") = " << MAX(a, b) << endl;

    double c = 7.5, d = 3.2;
    cout << "MIN(" << c << ", " << d << ") = " << MIN(c, d) << endl;
    cout << "MAX(" << c << ", " << d << ") = " << MAX(c, d) << endl;

    int num1 = 5;
    double num2 = 3.5;
    cout << "\nSQUARE(" << num1 << ") = " << SQUARE(num1) << endl;
    cout << "SQUARE(" << num2 << ") = " << SQUARE(num2) << endl;

    int x = 5;
    cout << "SQUARE(" << x << " + 1) = " << SQUARE(x + 1) << " (ожидается 36)" << endl;

    int base1 = 2, exponent1 = 3;
    double base2 = 1.5;
    int exponent2 = 4;

    cout << "\nPOWER(" << base1 << ", " << exponent1 << ") = "
        << POWER(base1, exponent1) << endl;
    cout << "POWER(" << base2 << ", " << exponent2 << ") = "
        << POWER(base2, exponent2) << endl;

    cout << "\nPOWER_SAFE(" << base1 << ", " << exponent1 << ") = "
        << POWER_SAFE(base1, exponent1) << endl;
    cout << "POWER_SAFE(" << base2 << ", " << exponent2 << ") = "
        << POWER_SAFE(base2, exponent2) << endl;

    cout << "\nПроверка на четность/нечетность:" << endl;

    int numbers[] = { 0, 1, 2, 3, 4, 5, 10, 11 };
    for (int num : numbers) {
        cout << "Число " << num << ": ";
        if (IS_EVEN(num)) {
            cout << "четное";
        }
        if (IS_ODD(num)) {
            cout << "нечетное";
        }
        cout << endl;
    }

    cout << "\n=== Дополнительные примеры ===" << endl;

    cout << "MIN(MAX(5, 3), 10) = " << MIN(MAX(5, 3), 10) << endl;
    cout << "SQUARE(MIN(7, 4)) = " << SQUARE(MIN(7, 4)) << endl;

    int test_num = 15;
    if (IS_ODD(test_num)) {
        cout << "\nЧисло " << test_num << " является нечетным" << endl;
    }

    int p = 6, q = 9;
    cout << "\nДля чисел " << p << " и " << q << ":" << endl;
    cout << "Минимум в квадрате: " << SQUARE(MIN(p, q)) << endl;
    cout << "Разность максимума и минимума: " << MAX(p, q) - MIN(p, q) << endl;

    return 0;
}