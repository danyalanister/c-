#include <iostream>
using namespace std;
//1
int main() {
    setlocale(LC_ALL, "ru");
    int rows, cols, num;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;
    cout << "Введите начальное число: ";
    cin >> num;

    int arr[10][10]; // ограничим до 10x10 для простоты
    arr[0][0] = num;

    // Заполнение массива
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0)
                arr[i][j] = num;
            else if (j == 0)
                arr[i][j] = arr[i - 1][cols - 1] * 2;
            else
                arr[i][j] = arr[i][j - 1] * 2;
        }
    }

    // Вывод массива
    cout << "\nМассив:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
//2
int main() {
    setlocale(LC_ALL, "ru");
    int rows, cols, num;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;
    cout << "Введите начальное число: ";
    cin >> num;

    int arr[10][10];
    arr[0][0] = num;

    // Заполнение массива
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0)
                arr[i][j] = num;
            else if (j == 0)
                arr[i][j] = arr[i - 1][cols - 1] + 1;
            else
                arr[i][j] = arr[i][j - 1] + 1;
        }
    }

    // Вывод массива
    cout << "\nМассив:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}