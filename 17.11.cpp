#include <iostream>
#include <cmath>
using namespace std;
//1

int main() {
    setlocale(LC_ALL, "ru");

    double base;
    int exponent;

    cout << "Введите основание степени: ";
    cin >> base;
    cout << "Введите показатель степени: ";
    cin >> exponent;

    double result = pow(base, exponent);
    cout << "Результат: " << result << endl;

    return 0;
}
//2
int sum_in_range(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "ru");

    int start, end;
    cout << "Введите два целых числа: ";
    cin >> start >> end;

    cout << "Сумма чисел между ними: " << sum_in_range(start, end) << endl;

    return 0;
}
//3
bool is_perfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int main() {
    setlocale(LC_ALL, "ru");

    int start, end;
    cout << "Введите интервал чисел: ";
    cin >> start >> end;

    cout << "Совершенные числа в интервале: ";
    for (int i = start; i <= end; ++i) {
        if (is_perfect(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
//4
void print_card(string card) {
    cout << "Игровая карта: " << card << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    string card;
    cout << "Введите игровую карту: ";
    cin >> card;

    print_card(card);

    return 0;
}
//5
bool is_lucky(int number) {
    int first_half = number / 1000;
    int second_half = number % 1000;

    int sum_first = 0, sum_second = 0;

    while (first_half > 0) {
        sum_first += first_half % 10;
        first_half /= 10;
    }

    while (second_half > 0) {
        sum_second += second_half % 10;
        second_half /= 10;
    }

    return sum_first == sum_second;
}

int main() {
    setlocale(LC_ALL, "ru");

    int number;
    cout << "Введите шестизначное число: ";
    cin >> number;

    if (is_lucky(number)) {
        cout << "Число счастливое!" << endl;
    }
    else {
        cout << "Число не счастливое!" << endl;
    }

    return 0;
}
