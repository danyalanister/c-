//1
#include <iostream>
using namespace std;

// Функция для инициализации матрицы (int)
void initMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1; // заполняем по порядку
        }
    }
}

// Функция для инициализации матрицы (double)
void initMatrix(double matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i * cols + j + 1) * 1.5; // заполняем дробными числами
        }
    }
}

// Функция для вывода матрицы (int)
void printMatrix(int matrix[][3], int rows, int cols) {
    cout << "Матрица (int):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функция для вывода матрицы (double)
void printMatrix(double matrix[][3], int rows, int cols) {
    cout << "Матрица (double):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функция для поиска максимума и минимума на главной диагонали (int)
void findDiagMinMax(int matrix[][3], int size, int& maxVal, int& minVal) {
    maxVal = matrix[0][0];
    minVal = matrix[0][0];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
    }
}

// Функция для поиска максимума и минимума на главной диагонали (double)
void findDiagMinMax(double matrix[][3], int size, double& maxVal, double& minVal) {
    maxVal = matrix[0][0];
    minVal = matrix[0][0];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
    }
}

// Функция для сортировки строки по возрастанию (int)
void sortRow(int row[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (row[i] > row[j]) {
                int temp = row[i];
                row[i] = row[j];
                row[j] = temp;
            }
        }
    }
}

// Функция для сортировки строки по возрастанию (double)
void sortRow(double row[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (row[i] > row[j]) {
                double temp = row[i];
                row[i] = row[j];
                row[j] = temp;
            }
        }
    }
}

// Основная программа
int main() {
    const int SIZE = 3;
    int intMatrix[SIZE][SIZE];
    double doubleMatrix[SIZE][SIZE];

    // Инициализация
    initMatrix(intMatrix, SIZE, SIZE);
    initMatrix(doubleMatrix, SIZE, SIZE);

    // Вывод
    printMatrix(intMatrix, SIZE, SIZE);
    printMatrix(doubleMatrix, SIZE, SIZE);

    // Поиск макс/мин на диагонали
    int maxInt, minInt;
    double maxDouble, minDouble;
    findDiagMinMax(intMatrix, SIZE, maxInt, minInt);
    findDiagMinMax(doubleMatrix, SIZE, maxDouble, minDouble);

    cout << "\nНа главной диагонали (int): max=" << maxInt << ", min=" << minInt << endl;
    cout << "На главной диагонали (double): max=" << maxDouble << ", min=" << minDouble << endl;

    // Сортировка строк
    for (int i = 0; i < SIZE; i++) {
        sortRow(intMatrix[i], SIZE);
        sortRow(doubleMatrix[i], SIZE);
    }

    cout << "\nПосле сортировки строк:\n";
    printMatrix(intMatrix, SIZE, SIZE);
    printMatrix(doubleMatrix, SIZE, SIZE);

    return 0;
}

//2
#include <iostream>
using namespace std;

// Рекурсивная функция для нахождения НОД (алгоритм Евклида)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); // рекурсивный вызов
}

int main() {
    int num1, num2;
    cout << "Введите два целых числа: ";
    cin >> num1 >> num2;

    int result = gcd(num1, num2);
    cout << "Наибольший общий делитель (" << num1 << ", " << num2 << ") = " << result << endl;

    return 0;
}