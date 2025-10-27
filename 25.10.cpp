#include <iostream>
using namespace std;
//1
int main() {
    setlocale(LC_ALL, "ru");
    const int rows = 3, cols = 4;
    int arr[rows][cols];
    int sum = 0;
    int minEl, maxEl;

    cout << "Введите элементы массива 3x4:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
            if (i == 0 && j == 0) {
                minEl = maxEl = arr[i][j];
            }
            if (arr[i][j] < minEl) minEl = arr[i][j];
            if (arr[i][j] > maxEl) maxEl = arr[i][j];
        }
    }

    double average = (double)sum / (rows * cols);

    cout << "\nСумма всех элементов: " << sum;
    cout << "\nСреднее арифметическое: " << average;
    cout << "\nМинимальный элемент: " << minEl;
    cout << "\nМаксимальный элемент: " << maxEl;

    return 0;
}
//2
int main() {
    setlocale(LC_ALL, "ru");
    const int rows = 3, cols = 4;
    int arr[rows][cols];

    cout << "Введите элементы массива 3x4:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    int totalSum = 0;
    cout << "\nРезультат:\n";
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
            rowSum += arr[i][j];
        }
        totalSum += rowSum;
        cout << "| " << rowSum << endl;
    }

    cout << "------------------------\n";
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }
        cout << colSum << "\t";
    }
    cout << "| " << totalSum << endl;

    return 0;
}
//3
#include <cstdlib> // для rand()
#include <ctime>   // для srand()
int main() {
    setlocale(LC_ALL, "ru");
    const int rows = 5, cols1 = 10, cols2 = 5;
    int arr1[rows][cols1];
    int arr2[rows][cols2];

    srand(time(0)); // генератор случайных чисел

    // Заполнение первого массива
    cout << "Первый массив (5x10):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols1; j++) {
            arr1[i][j] = rand() % 51; // от 0 до 50
            cout << arr1[i][j] << "\t";
        }
        cout << endl;
    }

    // Заполнение второго массива — сумма соседних столбцов
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols2; j++) {
            arr2[i][j] = arr1[i][j * 2] + arr1[i][j * 2 + 1];
        }
    }

    // Вывод второго массива
    cout << "\nВторой массив (5x5):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}