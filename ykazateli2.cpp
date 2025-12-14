#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    const int SIZE = 5;
    int source[SIZE] = { 10, 20, 30, 40, 50 };
    int destination[SIZE];

    // Создаем указатели на начало массивов
    int* ptrSource = source;      // эквивалентно &source[0]
    int* ptrDest = destination;   // эквивалентно &destination[0]

    cout << " КОПИРОВАНИЕ МАССИВА " << endl;
    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << source[i] << " ";
    }
    cout << endl;

    // Копируем элементы с использованием указателей
    for (int i = 0; i < SIZE; i++) {
        // Используем разыменование и арифметику указателей
        *(ptrDest + i) = *(ptrSource + i);
    }

    cout << "Скопированный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << destination[i] << " ";
    }
    cout << endl;

    // Демонстрация арифметики указателей
    cout << "\n ДЕМОНСТРАЦИЯ АРИФМЕТИКИ УКАЗАТЕЛЕЙ " << endl;
    cout << "Адрес source[0]: " << ptrSource << endl;
    cout << "Адрес source[1]: " << ptrSource + 1 << endl;
    cout << "Адрес source[2]: " << ptrSource + 2 << endl;
    cout << "Размер int: " << sizeof(int) << " байта" << endl;

    cout << "\nЗначения через указатели:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "*(ptrSource + " << i << ") = " << *(ptrSource + i) << endl;
    }

    return 0;
}

//2
int main() {
    setlocale(LC_ALL, "ru");
    const int SIZE = 6;
    int arr[SIZE] = { 1, 2, 3, 4, 5, 6 };

    // Создаем указатели на начало и конец массива
    int* ptrStart = arr;               // начало массива
    int* ptrEnd = arr + SIZE - 1;      // конец массива

    cout << " РЕВЕРС МАССИВА " << endl;
    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Реверсируем массив с помощью двух указателей
    while (ptrStart < ptrEnd) {
        // Меняем местами элементы через указатели
        int temp = *ptrStart;
        *ptrStart = *ptrEnd;
        *ptrEnd = temp;

        // Перемещаем указатели
        ptrStart++;  // двигаемся вперед от начала
        ptrEnd--;    // двигаемся назад от конца
    }

    cout << "Реверсированный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Демонстрация работы указателей
    cout << "\n ПРОЦЕСС РЕВЕРСА " << endl;

    // Восстанавливаем массив для демонстрации
    int arr2[SIZE] = { 1, 2, 3, 4, 5, 6 };
    int* start = arr2;
    int* end = arr2 + SIZE - 1;
    int step = 1;

    while (start < end) {
        cout << "\nШаг " << step++ << ":" << endl;
        cout << "Меняем местами *start=" << *start;
        cout << " и *end=" << *end << endl;

        int temp = *start;
        *start = *end;
        *end = temp;

        cout << "Массив после обмена: ";
        for (int i = 0; i < SIZE; i++) {
            cout << arr2[i] << " ";
        }
        cout << endl;

        start++;
        end--;
    }

    return 0;
}

//3
int main() {
    setlocale(LC_ALL, "ru");
    const int SIZE = 7;
    int source[SIZE] = { 10, 20, 30, 40, 50, 60, 70 };
    int destination[SIZE];

    // Создаем указатели
    int* ptrSourceStart = source;          // начало исходного массива
    int* ptrDestEnd = destination + SIZE - 1; // конец целевого массива

    cout << " КОПИРОВАНИЕ С РЕВЕРСОМ " << endl;
    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << source[i] << " ";
    }
    cout << endl;

    // Копируем в обратном порядке
    for (int i = 0; i < SIZE; i++) {
        // Копируем из начала исходного в конец целевого
        *(ptrDestEnd - i) = *(ptrSourceStart + i);
    }

    cout << "Результат (скопировано в обратном порядке): ";
    for (int i = 0; i < SIZE; i++) {
        cout << destination[i] << " ";
    }
    cout << endl;

    // Альтернативный способ с двумя указателями
    cout << "\n АЛЬТЕРНАТИВНЫЙ СПОСОБ " << endl;

    int destination2[SIZE];
    int* srcPtr = source;
    int* destPtr = destination2 + SIZE - 1; // указатель на конец

    // Копируем до тех пор, пока не скопируем все элементы
    for (int i = 0; i < SIZE; i++) {
        *destPtr = *srcPtr;
        srcPtr++;    // двигаемся вперед по исходному
        destPtr--;   // двигаемся назад по целевому
    }

    cout << "Результат альтернативным способом: ";
    for (int i = 0; i < SIZE; i++) {
        cout << destination2[i] << " ";
    }
    cout << endl;

    // Подробная демонстрация
    cout << "\n ПОДРОБНАЯ ДЕМОНСТРАЦИЯ " << endl;
    int demoSource[5] = { 1, 2, 3, 4, 5 };
    int demoDest[5];

    int* src = demoSource;
    int* dest = demoDest + 4; // указываем на последний элемент

    cout << "Процесс копирования:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Шаг " << i + 1 << ": ";
        cout << "*(dest - " << i << ") = *(src + " << i << ")" << endl;
        cout << "  " << *(dest - i) << " = " << *(src + i) << "?" << " Нет! Присваиваем!" << endl;

        *(dest - i) = *(src + i);

        cout << "  Промежуточный результат: ";
        for (int j = 0; j < 5; j++) {
            cout << demoDest[j] << " ";
        }
        cout << endl;
    }

    cout << "\nАдреса и значения:" << endl;
    cout << "Адрес demoSource[0]: " << &demoSource[0] << endl;
    cout << "Адрес demoDest[4]: " << &demoDest[4] << endl;
    cout << "src (указатель): " << src << endl;
    cout << "dest (указатель): " << dest << endl;

    return 0;
}