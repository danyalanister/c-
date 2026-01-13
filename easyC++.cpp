//1.1
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a << "+ " << b << "= " << a + b << endl;
    return 0;
}

//1.2
int main() {
    double c;
    cin >> c;
    double f = c * 9 / 5 + 32;
    cout << c << "°C= " << f << "°F" << endl;
    return 0;
}

//2.1
int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << n << "- четное число." << endl;
    else
        cout << n << "- нечетное число." << endl;
    return 0;
}

//2.2
int main() {
    setlocale(LC_ALL, "ru");
    int year;
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        cout << year << "- високосный год." << endl;
    else
        cout << year << "- не високосный год." << endl;
    return 0;
}

//3.1
int main() {
    setlocale(LC_ALL, "ru");
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        sum += i;
    cout << "Сумма чисел от 1 до " << n << " равна " << sum << "." << endl;
    return 0;
}

//3.2
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 10; i++)
        cout << n << " x " << i << "= " << n * i << endl;
    return 0;
}

//4.1
int main() {
    setlocale(LC_ALL, "ru");
    int arr[10];
    for (int i = 0; i < 10; i++)
        cin >> arr[i];

    int min_val = arr[0];
    for (int i = 1; i < 10; i++)
        if (arr[i] < min_val) min_val = arr[i];

    cout << "Минимальный элемент: " << min_val << endl;
    return 0;
}

//4.2
int main() {
    setlocale(LC_ALL, "ru");
    int matrix[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++)
            sum += matrix[i][j];
        cout << "Сумма строки " << i + 1 << ": " << sum << endl;
    }
    return 0;
}

//5.1
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    setlocale(LC_ALL, "ru");
    int a, b;
    cin >> a >> b;
    cout << "Наибольшее число: " << max(a, b) << endl;
    return 0;
}

//5.2
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cin >> n;
    if (isPrime(n))
        cout << n << "- простое число." << endl;
    else
        cout << n << "- не простое число." << endl;
    return 0;
}

//6.1
int main() {
    setlocale(LC_ALL, "ru");
    int a = 10, b = 20;
    cout << "До: a= " << a << ", b= " << b << endl;

    int* pa = &a;
    int* pb = &b;
    int temp = *pa;
    *pa = *pb;
    *pb = temp;

    cout << "После: a= " << a << ", b= " << b << endl;
    return 0;
}

//6.2
int main() {
    setlocale(LC_ALL, "ru");
    int arr[5] = { 1, 2, 3, 4, 5 };
    int sum = 0;
    int* p = arr;

    for (int i = 0; i < 5; i++)
        sum += *(p + i);

    cout << "Сумма элементов: " << sum << endl;
    return 0;
}

//7.1
int main() {
    setlocale(LC_ALL, "ru");
    char str[100];
    cin.getline(str, 100);
    int len = 0;
    while (str[len] != '\0') len++;
    cout << "Длина строки\"" << str << "\" равна " << len << " символам." << endl;
    return 0;
}
