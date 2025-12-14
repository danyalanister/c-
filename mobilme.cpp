#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    const int SIZE = 5;
    string mobile[SIZE];
    string home[SIZE];

    // Инициализация данных
    mobile[0] = "79161234567"; home[0] = "4951234567";
    mobile[1] = "79031234567"; home[1] = "8123456789";
    mobile[2] = "79261234567"; home[2] = "3831234567";
    mobile[3] = "79051234567"; home[3] = "8431234567";
    mobile[4] = "79111234567"; home[4] = "4731234567";

    int choice;
    bool running = true;

    while (running) {
        cout << "\n=== ТЕЛЕФОННЫЙ СПРАВОЧНИК ===" << endl;
        cout << "1. Отсортировать по номерам мобильных" << endl;
        cout << "2. Отсортировать по домашним номерам" << endl;
        cout << "3. Вывести данные" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        if (choice == 1) {
            // Сортировка по мобильным номерам
            for (int i = 0; i < SIZE - 1; i++) {
                for (int j = 0; j < SIZE - i - 1; j++) {
                    if (mobile[j] > mobile[j + 1]) {
                        // Меняем мобильные
                        string tempM = mobile[j];
                        mobile[j] = mobile[j + 1];
                        mobile[j + 1] = tempM;

                        // Меняем домашние соответствующим образом
                        string tempH = home[j];
                        home[j] = home[j + 1];
                        home[j + 1] = tempH;
                    }
                }
            }
            cout << "Сортировка по мобильным номерам выполнена!" << endl;
        }
        else if (choice == 2) {
            // Сортировка по домашним номерам
            for (int i = 0; i < SIZE - 1; i++) {
                for (int j = 0; j < SIZE - i - 1; j++) {
                    if (home[j] > home[j + 1]) {
                        // Меняем домашние
                        string tempH = home[j];
                        home[j] = home[j + 1];
                        home[j + 1] = tempH;

                        // Меняем мобильные соответствующим образом
                        string tempM = mobile[j];
                        mobile[j] = mobile[j + 1];
                        mobile[j + 1] = tempM;
                    }
                }
            }
            cout << "Сортировка по домашним номерам выполнена!" << endl;
        }
        else if (choice == 3) {
            // Вывод данных
            cout << "\nМобильные номера\tДомашние номера" << endl;
            cout << "----------------------------------------" << endl;
            for (int i = 0; i < SIZE; i++) {
                cout << mobile[i] << "\t\t" << home[i] << endl;
            }
        }
        else if (choice == 4) {
            cout << "Выход из программы. До свидания!" << endl;
            running = false;
        }
        else {
            cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    }

    return 0;
}

//2
int main() {
    setlocale(LC_ALL, "ru");
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    int arr[100];

    cout << "Введите " << size << " чисел: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nИсходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Усовершенствованная пузырьковая сортировка
    bool swapped;
    int totalPasses = 0;
    int totalSwaps = 0;

    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        int swapsThisPass = 0;

        // Сравниваем соседние элементы
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
                swapsThisPass++;
                totalSwaps++;
            }
        }

        totalPasses++;

        // Выводим информацию о проходе
        cout << "Проход " << i + 1 << ": " << swapsThisPass << " перестановок" << endl;

        // Если перестановок не было - массив отсортирован
        if (!swapped) {
            cout << "✓ Массив отсортирован! Остановка." << endl;
            break;
        }
    }

    cout << "\nОтсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nИтоги:" << endl;
    cout << "Сделано проходов: " << totalPasses << endl;
    cout << "Всего перестановок: " << totalSwaps << endl;

    // Сравнение с обычной пузырьковой сортировкой
    cout << "\nСравнение с обычной пузырьковой сортировкой:" << endl;
    cout << "Обычная: всегда делает " << size - 1 << " проходов" << endl;
    cout << "Усовершенствованная: сделала " << totalPasses << " проходов" << endl;

    if (totalPasses < size - 1) {
        cout << "✓ Экономия: " << (size - 1 - totalPasses) << " проходов" << endl;
    }

    return 0;
}

//3
#include <iostream>
using namespace std;

// Простая версия алгоритма сортировки оладий
int main() {
    setlocale(LC_ALL, "ru");
    int size;

    cout << "Введите количество оладий: ";
    cin >> size;

    int stack[100];

    cout << "Введите радиусы оладий: ";
    for (int i = 0; i < size; i++) {
        cin >> stack[i];
    }

    cout << "\nИсходная стопка: ";
    for (int i = 0; i < size; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;

    int flips = 0; // Счетчик переворотов

    // Алгоритм сортировки оладий
    for (int i = size; i > 1; i--) {
        // Находим самый большой оладь в текущей стопке
        int maxPos = 0;
        for (int j = 1; j < i; j++) {
            if (stack[j] > stack[maxPos]) {
                maxPos = j;
            }
        }

        // Если самый большой оладь уже на своем месте, пропускаем
        if (maxPos == i - 1) {
            continue;
        }

        // Если самый большой оладь не наверху, переворачиваем чтобы поднять его
        if (maxPos != 0) {
            // Переворачиваем стопку до максимального элемента
            cout << "\nПереворот " << ++flips << ": ";
            cout << "поднимаем оладь " << stack[maxPos] << " наверх" << endl;

            int start = 0;
            int end = maxPos;
            while (start < end) {
                int temp = stack[start];
                stack[start] = stack[end];
                stack[end] = temp;
                start++;
                end--;
            }

            // Выводим промежуточный результат
            cout << "Промежуточный результат: ";
            for (int k = 0; k < size; k++) {
                cout << stack[k] << " ";
            }
            cout << endl;
        }

        // Теперь переворачиваем всю текущую стопку
        cout << "\nПереворот " << ++flips << ": ";
        cout << "опускаем оладь " << stack[0] << " на позицию " << i - 1 << endl;

        int start = 0;
        int end = i - 1;
        while (start < end) {
            int temp = stack[start];
            stack[start] = stack[end];
            stack[end] = temp;
            start++;
            end--;
        }

        // Выводим результат после переворота
        cout << "Текущая стопка: ";
        for (int k = 0; k < size; k++) {
            cout << stack[k] << " ";
        }
        cout << endl;
    }

    cout << "\n=== РЕЗУЛЬТАТ ===" << endl;
    cout << "Отсортированная стопка (по убыванию снизу вверх): ";
    for (int i = 0; i < size; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;

    cout << "Всего выполнено переворотов: " << flips << endl;

    // Проверяем правильность сортировки
    cout << "\nПроверка сортировки (должно быть по убыванию): ";
    bool correct = true;
    for (int i = 1; i < size; i++) {
        if (stack[i] > stack[i - 1]) {
            correct = false;
            break;
        }
    }

    if (correct) {
        cout << "✓ Сортировка выполнена правильно!" << endl;
    }
    else {
        cout << "✗ Ошибка в сортировке!" << endl;
    }

    return 0;
}