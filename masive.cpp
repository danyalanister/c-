#include <iostream>
#include <cstdlib>  // для rand()
#include <ctime>    // для time()
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Инициализация генератора случайных чисел
    srand(time(0));

    // Создаем массив длиной 10
    int arr[10];
    int sum = 0;

    // Заполняем массив случайными числами от 1 до 100
    cout << "Массив из 10 случайных чисел:" << endl;
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100 + 1;  // % 100 дает 0-99, +1 дает 1-100
        cout << arr[i] << " ";
        sum += arr[i];  // добавляем к сумме
    }

    // Вычисляем среднее арифметическое
    double average = sum / 10.0;  // используем 10.0 для вещественного деления

    cout << endl << endl;
    cout << "Сумма всех элементов: " << sum << endl;
    cout << "Среднее арифметическое: " << average << endl;

    return 0;
}

//2
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    // Создаем массив длиной 15 для символов
    char arr[15];

    // Счетчики для каждого символа
    int countA = 0;
    int countB = 0;
    int countC = 0;

    // Заполняем массив случайными символами 'А', 'В', 'С'
    cout << "Массив из 15 случайных символов:" << endl;
    for (int i = 0; i < 15; i++) {
        int randomNum = rand() % 3;  // получаем 0, 1 или 2

        // В зависимости от случайного числа выбираем символ
        if (randomNum == 0) {
            arr[i] = 'A';
            countA++;  // увеличиваем счетчик для 'A'
        }
        else if (randomNum == 1) {
            arr[i] = 'B';
            countB++;  // увеличиваем счетчик для 'B'
        }
        else {
            arr[i] = 'C';
            countC++;  // увеличиваем счетчик для 'C'
        }

        cout << arr[i] << " ";
    }

    // Выводим результаты подсчета
    cout << endl << endl;
    cout << "Частота символов:" << endl;
    cout << "Символ 'A': " << countA << " раз" << endl;
    cout << "Символ 'B': " << countB << " раз" << endl;
    cout << "Символ 'C': " << countC << " раз" << endl;

    return 0;
}

//3
#include <iomanip>  // для setprecision
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    // Создаем массив для 20 вещественных чисел
    double arr[20];

    // Заполняем массив случайными числами от -1 до +1
    cout << "Исходный массив (20 чисел от -1 до +1):" << endl;
    for (int i = 0; i < 20; i++) {
        // Генерируем число от -1000 до +1000, затем делим на 1000
        arr[i] = (rand() % 2001 - 1000) / 1000.0;
        cout << fixed << setprecision(3) << arr[i] << " ";
    }

    // Сортировка по убыванию (метод пузырька)
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19 - i; j++) {
            // Сравниваем соседние элементы
            if (arr[j] < arr[j + 1]) {
                // Меняем местами, если текущий меньше следующего
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Выводим отсортированный массив
    cout << endl << endl;
    cout << "Массив после сортировки по убыванию:" << endl;
    for (int i = 0; i < 20; i++) {
        cout << fixed << setprecision(3) << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//4
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    const int SIZE = 20;
    int arr[SIZE];

    // Заполняем массив случайными числами от 1 до 50
    cout << "Исходный массив (20 чисел от 1 до 50):" << endl;
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 50 + 1;  // от 1 до 50
        cout << arr[i] << " ";
    }

    // Создаем новый массив для четных чисел
    int evenArr[SIZE];  // максимально может быть SIZE элементов
    int evenCount = 0;  // счетчик четных чисел

    // Проходим по исходному массиву и копируем только четные числа
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {  // проверяем, четное ли число
            evenArr[evenCount] = arr[i];  // сохраняем четное число
            evenCount++;  // увеличиваем счетчик
        }
    }

    // Выводим результат
    cout << endl << endl;
    cout << "Массив без нечетных чисел (только четные):" << endl;
    for (int i = 0; i < evenCount; i++) {
        cout << evenArr[i] << " ";
    }

    cout << endl << endl;
    cout << "Было найдено " << evenCount << " четных чисел." << endl;
    cout << "Было удалено " << (SIZE - evenCount) << " нечетных чисел." << endl;

    return 0;
}

//5
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    const int LENGTH = 10;
    char letters[LENGTH];

    // Заполняем массив случайными буквами английского алфавита
    cout << "Последовательность из 10 случайных букв:" << endl;
    for (int i = 0; i < LENGTH; i++) {
        // Генерируем случайную букву от 'A' до 'Z'
        // 'A' имеет код 65, 'Z' - 90, всего 26 букв
        letters[i] = 'A' + rand() % 26;
        cout << letters[i] << " ";
    }

    // Проверяем, является ли последовательность палиндромом
    bool isPalindrome = true;  // сначала предполагаем, что это палиндром

    // Сравниваем симметричные элементы (первый с последним, второй с предпоследним и т.д.)
    for (int i = 0; i < LENGTH / 2; i++) {
        if (letters[i] != letters[LENGTH - 1 - i]) {
            isPalindrome = false;  // нашли несовпадение
            break;  // дальше проверять не нужно
        }
    }

    // Выводим результат проверки
    cout << endl << endl;
    if (isPalindrome) {
        cout << "ЭТО ПАЛИНДРОМ!" << endl;
        cout << "Последовательность читается одинаково слева направо и справа налево." << endl;
    }
    else {
        cout << "ЭТО НЕ ПАЛИНДРОМ!" << endl;
        cout << "Последовательность читается по-разному в разных направлениях." << endl;
    }

    // Дополнительно: показываем сравнение
    cout << endl << "Сравнение симметричных элементов:" << endl;
    for (int i = 0; i < LENGTH; i++) {
        cout << "letters[" << i << "] = " << letters[i];
        cout << "  <->  ";
        cout << "letters[" << LENGTH - 1 - i << "] = " << letters[LENGTH - 1 - i];

        if (letters[i] == letters[LENGTH - 1 - i]) {
            cout << "  совпадают" << endl;
        }
        else {
            cout << "  не совпадают" << endl;
        }
    }

    return 0;
}