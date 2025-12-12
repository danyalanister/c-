#include <iostream>
using namespace std;
//1
// Рекурсивная функция для вычисления степени
double power(double base, int exponent) {
    // Базовый случай: любое число в степени 0 равно 1
    if (exponent == 0) {
        return 1;
    }
    // Если степень отрицательная
    else if (exponent < 0) {
        return 1 / power(base, -exponent);
    }
    // Рекурсивный случай: base^exponent = base * base^(exponent-1)
    else {
        return base * power(base, exponent - 1);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    double base;
    int exponent;

    cout << "Введите число: ";
    cin >> base;
    cout << "Введите степень: ";
    cin >> exponent;

    double result = power(base, exponent);
    cout << base << " в степени " << exponent << " = " << result << endl;

    // Примеры для иллюстрации
    cout << "\nПримеры:" << endl;
    cout << "2^3 = " << power(2, 3) << endl;
    cout << "5^0 = " << power(5, 0) << endl;
    cout << "3^(-2) = " << power(3, -2) << endl;

    return 0;
}

//2
// Рекурсивная функция для вывода N звезд
void printStars(int n) {
    // Базовый случай: если осталось 0 звезд - заканчиваем
    if (n <= 0) {
        return;
    }

    // Выводим одну звезду
    cout << "* ";

    // Рекурсивно вызываем для оставшихся (n-1) звезд
    printStars(n - 1);
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество звезд: ";
    cin >> n;

    if (n < 0) {
        cout << "Количество звезд не может быть отрицательным!" << endl;
    }
    else {
        cout << "Ряд из " << n << " звезд:" << endl;
        printStars(n);
        cout << endl;
    }

    // Демонстрация работы функции
    cout << "\nДемонстрация:" << endl;
    cout << "5 звезд: ";
    printStars(5);
    cout << endl;
    cout << "3 звезды: ";
    printStars(3);
    cout << endl;
    cout << "1 звезда: ";
    printStars(1);
    cout << endl;

    return 0;
}

//3
// Рекурсивная функция для суммы чисел от a до b
int sumRange(int a, int b) {
    // Базовый случай: если a > b, сумма пустого диапазона = 0
    if (a > b) {
        return 0;
    }
    // Рекурсивный случай: сумма от a до b = a + сумма от (a+1) до b
    else {
        return a + sumRange(a + 1, b);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int a, b;

    cout << "Введите начало диапазона (a): ";
    cin >> a;
    cout << "Введите конец диапазона (b): ";
    cin >> b;

    int result = sumRange(a, b);
    cout << "Сумма чисел от " << a << " до " << b << " = " << result << endl;

    // Примеры для иллюстрации
    cout << "\nПримеры:" << endl;
    cout << "Сумма от 1 до 5 = " << sumRange(1, 5) << " (1+2+3+4+5 = 15)" << endl;
    cout << "Сумма от 10 до 10 = " << sumRange(10, 10) << " (10 = 10)" << endl;
    cout << "Сумма от 5 до 3 = " << sumRange(5, 3) << " (пустой диапазон = 0)" << endl;

    return 0;
}

//4
#include <cstdlib>
#include <ctime>
// Рекурсивная функция для поиска позиции с минимальной суммой 10 чисел
int findMinSumPosition(int arr[], int size, int currentPos, int minSum, int minPos) {
    // Базовый случай: если не хватает элементов для последовательности из 10
    if (currentPos > size - 10) {
        return minPos;
    }

    // Вычисляем сумму 10 чисел, начиная с текущей позиции
    int currentSum = 0;
    for (int i = 0; i < 10; i++) {
        currentSum += arr[currentPos + i];
    }

    // Если это первая последовательность или сумма меньше минимальной
    if (currentPos == 0 || currentSum < minSum) {
        minSum = currentSum;
        minPos = currentPos;
    }

    // Рекурсивно проверяем следующую позицию
    return findMinSumPosition(arr, size, currentPos + 1, minSum, minPos);
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    const int SIZE = 100;
    int arr[SIZE];

    // Заполняем массив случайными числами
    cout << "Массив из 100 случайных чисел (первые 20 элементов):" << endl;
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;  // числа от 0 до 99

        // Показываем только первые 20 элементов для наглядности
        if (i < 20) {
            cout << arr[i] << " ";
        }
    }
    cout << "... (и еще 80 чисел)" << endl;

    // Находим позицию с минимальной суммой 10 чисел
    int position = findMinSumPosition(arr, SIZE, 0, 0, 0);

    // Вычисляем сумму для найденной позиции
    int minSum = 0;
    cout << "\nПоследовательность из 10 чисел с минимальной суммой начинается с позиции " << position << ":" << endl;
    cout << "Элементы: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[position + i] << " ";
        minSum += arr[position + i];
    }
    cout << endl;
    cout << "Сумма этих 10 чисел: " << minSum << endl;

    // Дополнительно: показываем несколько последовательностей для сравнения
    cout << "\nСравнение с другими последовательностями:" << endl;
    for (int i = 0; i < 5; i++) {
        int testPos = i * 10;
        if (testPos <= SIZE - 10) {
            int testSum = 0;
            for (int j = 0; j < 10; j++) {
                testSum += arr[testPos + j];
            }
            cout << "Позиция " << testPos << ": сумма = " << testSum;
            if (testSum < minSum) cout << " (ОШИБКА!)";
            cout << endl;
        }
    }

    return 0;
}