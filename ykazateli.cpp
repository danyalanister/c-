#include <iostream>
using namespace std;
//1
int main() {
    setlocale(LC_ALL, "ru");
    int a, b;

    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;

    // Создаем указатели
    int* ptrA = &a;
    int* ptrB = &b;

    // Используем оператор разыменования для сравнения
    if (*ptrA > *ptrB) {
        cout << "Наибольшее число: " << *ptrA << endl;
        cout << "Оно хранится по адресу: " << ptrA << endl;
    }
    else if (*ptrB > *ptrA) {
        cout << "Наибольшее число: " << *ptrB << endl;
        cout << "Оно хранится по адресу: " << ptrB << endl;
    }
    else {
        cout << "Числа равны: " << *ptrA << endl;
    }

    return 0;
}

//2
int main() {
    setlocale(LC_ALL, "ru");
    int number;

    cout << "Введите число: ";
    cin >> number;

    // Создаем указатель на число
    int* ptr = &number;

    // Определяем знак с помощью указателя
    cout << "Вы ввели число: " << *ptr << endl;
    cout << "Адрес числа в памяти: " << ptr << endl;

    if (*ptr > 0) {
        cout << "Это положительное число" << endl;
    }
    else if (*ptr < 0) {
        cout << "Это отрицательное число" << endl;
    }
    else {
        cout << "Это ноль" << endl;
    }

    // Дополнительно: показываем как работает разыменование
    cout << "\nДемонстрация работы указателя:" << endl;
    cout << "Адрес переменной number: " << &number << endl;
    cout << "Значение по указателю ptr: " << *ptr << endl;
    cout << "Адрес в указателе ptr: " << ptr << endl;

    return 0;
}

//3
int main() {
    setlocale(LC_ALL, "ru");
    int x, y;

    cout << "Введите значение для переменной x: ";
    cin >> x;
    cout << "Введите значение для переменной y: ";
    cin >> y;

    cout << "\nДо обмена:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // Создаем указатели
    int* ptrX = &x;
    int* ptrY = &y;

    // Обмен значений с использованием указателей
    int temp = *ptrX;  // сохраняем значение x во временной переменной
    *ptrX = *ptrY;     // копируем значение y в x
    *ptrY = temp;      // копируем сохраненное значение x в y

    cout << "\nПосле обмена:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // Показываем адреса
    cout << "\nАдреса переменных:" << endl;
    cout << "Адрес x: " << &x << " (хранится в ptrX: " << ptrX << ")" << endl;
    cout << "Адрес y: " << &y << " (хранится в ptrY: " << ptrY << ")" << endl;

    return 0;
}

//4
int main() {
    setlocale(LC_ALL, "ru");
    double num1, num2, result;
    char operation;

    cout << "=== ПРИМИТИВНЫЙ КАЛЬКУЛЯТОР ===" << endl;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите операцию (+, -, *, /): ";
    cin >> operation;
    cout << "Введите второе число: ";
    cin >> num2;

    // Создаем указатели
    double* ptr1 = &num1;
    double* ptr2 = &num2;
    double* ptrResult = &result;
    char* ptrOp = &operation;

    // Выполняем операцию с использованием указателей
    switch (*ptrOp) {
    case '+':
        *ptrResult = *ptr1 + *ptr2;
        break;
    case '-':
        *ptrResult = *ptr1 - *ptr2;
        break;
    case '*':
        *ptrResult = *ptr1 * *ptr2;
        break;
    case '/':
        if (*ptr2 != 0) {
            *ptrResult = *ptr1 / *ptr2;
        }
        else {
            cout << "Ошибка: деление на ноль!" << endl;
            return 1;
        }
        break;
    default:
        cout << "Ошибка: неизвестная операция!" << endl;
        return 1;
    }

    // Выводим результат
    cout << "\n=== РЕЗУЛЬТАТ ===" << endl;
    cout << *ptr1 << " " << *ptrOp << " " << *ptr2 << " = " << *ptrResult << endl;

    // Дополнительная информация об указателях
    cout << "\n=== ИНФОРМАЦИЯ ОБ УКАЗАТЕЛЯХ ===" << endl;
    cout << "Адрес num1: " << ptr1 << ", значение: " << *ptr1 << endl;
    cout << "Адрес num2: " << ptr2 << ", значение: " << *ptr2 << endl;
    cout << "Адрес operation: " << (void*)ptrOp << ", значение: " << *ptrOp << endl;
    cout << "Адрес result: " << ptrResult << ", значение: " << *ptrResult << endl;

    // Демонстрация вычислений через указатели
    cout << "\n=== ВЫЧИСЛЕНИЯ ЧЕРЕЗ УКАЗАТЕЛИ ===" << endl;
    double temp;
    double* ptrTemp = &temp;

    if (*ptrOp == '+') {
        *ptrTemp = *ptr1 + *ptr2;
        cout << *ptr1 << " + " << *ptr2 << " = " << *ptrTemp << endl;
    }

    return 0;
}