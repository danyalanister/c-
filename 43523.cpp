#include <iostream>
using namespace std;

int main() {
    int M, N;
    cout << "Введите размер первого массива M: ";
    cin >> M;
    cout << "Введите размер второго массива N: ";
    cin >> N;

    int A[100], B[100], C[200]; // максимум 100 элементов в каждом
    int sizeC = 0; // текущий размер третьего массива

    // Ввод первого массива
    cout << "Введите элементы массива A (" << M << " чисел): ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    // Ввод второго массива
    cout << "Введите элементы массива B (" << N << " чисел): ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Копируем все элементы A в C
    for (int i = 0; i < M; i++) {
        C[sizeC] = A[i];
        sizeC++;
    }

    // Копируем все элементы B в C
    for (int i = 0; i < N; i++) {
        C[sizeC] = B[i];
        sizeC++;
    }

    // Вывод результата
    cout << "\nТретий массив C (объединённый): ";
    for (int i = 0; i < sizeC; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}

//2
#include <iostream>
using namespace std;

int main() {
    int M;
    cout << "Введите размер массива M: ";
    cin >> M;

    int A[100]; // максимум 100 элементов

    // Ввод массива
    cout << "Введите элементы массива A (" << M << " чисел): ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    // Меню выбора
    int choice;
    cout << "\nЧто удалить?\n";
    cout << "1. Чётные числа\n";
    cout << "2. Нечётные числа\n";
    cout << "Выберите (1 или 2): ";
    cin >> choice;

    // Создаем временный массив для результата
    int result[100];
    int newSize = 0;

    if (choice == 1) {
        // Удаляем чётные — оставляем нечётные
        for (int i = 0; i < M; i++) {
            if (A[i] % 2 != 0) { // если нечётное — сохраняем
                result[newSize] = A[i];
                newSize++;
            }
        }
    }
    else if (choice == 2) {
        // Удаляем нечётные — оставляем чётные
        for (int i = 0; i < M; i++) {
            if (A[i] % 2 == 0) { // если чётное — сохраняем
                result[newSize] = A[i];
                newSize++;
            }
        }
    }
    else {
        cout << "Неверный выбор!" << endl;
        return 1;
    }

    // Вывод результата
    cout << "\nМассив после удаления: ";
    for (int i = 0; i < newSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}