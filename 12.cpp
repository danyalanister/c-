#include <iostream>
using namespace std;
//1
int main() {
    setlocale(LC_ALL, "ru");
    int M, N;

    
    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    // Ввод элементов массивов
    cout << "Введите элементы массива A:\n";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B:\n";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Определяем максимально возможный размер для массива C 
    int* tempC = new int[M]; // временный массив максимального возможного размера
    int sizeC = 0;

    // Находим элементы A, которых нет в B
    for (int i = 0; i < M; i++) {
        bool foundInB = false;

        // Проверяем, есть ли A[i] в B
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                foundInB = true;
                break;
            }
        }

        // Если элемент не найден в B
        if (!foundInB) {
            // Проверяем на дубликат во временном массиве
            bool duplicate = false;
            for (int k = 0; k < sizeC; k++) {
                if (tempC[k] == A[i]) {
                    duplicate = true;
                    break;
                }
            }

            // Если не дубликат, добавляем во временный массив
            if (!duplicate) {
                tempC[sizeC] = A[i];
                sizeC++;
            }
        }
    }

    // Создаем массив C минимального размера
    int* C = new int[sizeC];
    for (int i = 0; i < sizeC; i++) {
        C[i] = tempC[i];
    }

    
    cout << "\nМассив C (элементы A, которых нет в B, без повторений):\n";
    cout << "Размер: " << sizeC << endl;
    cout << "Элементы: ";

    if (sizeC == 0) {
        cout << "пустой массив";
    }
    else {
        for (int i = 0; i < sizeC; i++) {
            cout << C[i] << " ";
        }
    }
    cout << endl;

    // Освобождаем память
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] tempC;

    return 0;
}

//2
#include <iostream>

using namespace std;

int main() {
    int M, N;
    
    // Ввод размеров массивов
    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;
    
    int* A = new int[M];
    int* B = new int[N];
    
    // Ввод элементов массивов
    cout << "Введите элементы массива A:\n";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    
    cout << "Введите элементы массива B:\n";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    // Максимально возможный размер - сумма размеров A и B
    int maxSize = M + N;
    int* tempC = new int[maxSize];
    int sizeC = 0;
    
    // 1. Добавляем элементы из A, которых нет в B
    for (int i = 0; i < M; i++) {
        bool foundInB = false;
        
        // Проверяем, есть ли A[i] в B
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                foundInB = true;
                break;
            }
        }
        
        // Если элемент не найден в B
        if (!foundInB) {
            // Проверяем на дубликат во временном массиве
            bool duplicate = false;
            for (int k = 0; k < sizeC; k++) {
                if (tempC[k] == A[i]) {
                    duplicate = true;
                    break;
                }
            }
            
            // Если не дубликат, добавляем
            if (!duplicate) {
                tempC[sizeC] = A[i];
                sizeC++;
            }
        }
    }
    
    // 2. Добавляем элементы из B, которых нет в A
    for (int i = 0; i < N; i++) {
        bool foundInA = false;
        
        // Проверяем, есть ли B[i] в A
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                foundInA = true;
                break;
            }
        }
        
        // Если элемент не найден в A
        if (!foundInA) {
            // Проверяем на дубликат во временном массиве
            bool duplicate = false;
            for (int k = 0; k < sizeC; k++) {
                if (tempC[k] == B[i]) {
                    duplicate = true;
                    break;
                }
            }
            
            // Если не дубликат, добавляем
            if (!duplicate) {
                tempC[sizeC] = B[i];
                sizeC++;
            }
        }
    }
    
    // Создаем массив C минимального размера
    int* C = new int[sizeC];
    for (int i = 0; i < sizeC; i++) {
        C[i] = tempC[i];
    }
    
    // Выводим результат
    cout << "\nМассив C (элементы, не общие для A и B, без повторений):\n";
    cout << "Размер: " << sizeC << endl;
    cout << "Элементы: ";
    
    if (sizeC == 0) {
        cout << "пустой массив";
    } else {
        for (int i = 0; i < sizeC; i++) {
            cout << C[i] << " ";
        }
    }
    cout << endl;
    
    // Освобождаем память
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] tempC;
    
    return 0;
}

//2
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int M, N;

    
    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    // Ввод элементов массивов
    cout << "Введите элементы массива A:\n";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B:\n";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Максимально возможный размер - сумма размеров A и B
    int maxSize = M + N;
    int* tempC = new int[maxSize];
    int sizeC = 0;

    // 1. Добавляем элементы из A, которых нет в B
    for (int i = 0; i < M; i++) {
        bool foundInB = false;

        // Проверяем, есть ли A[i] в B
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                foundInB = true;
                break;
            }
        }

        // Если элемент не найден в B
        if (!foundInB) {
            // Проверяем на дубликат во временном массиве
            bool duplicate = false;
            for (int k = 0; k < sizeC; k++) {
                if (tempC[k] == A[i]) {
                    duplicate = true;
                    break;
                }
            }

            // Если не дубликат, добавляем
            if (!duplicate) {
                tempC[sizeC] = A[i];
                sizeC++;
            }
        }
    }

    // 2. Добавляем элементы из B, которых нет в A
    for (int i = 0; i < N; i++) {
        bool foundInA = false;

        // Проверяем, есть ли B[i] в A
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                foundInA = true;
                break;
            }
        }

        // Если элемент не найден в A
        if (!foundInA) {
            // Проверяем на дубликат во временном массиве
            bool duplicate = false;
            for (int k = 0; k < sizeC; k++) {
                if (tempC[k] == B[i]) {
                    duplicate = true;
                    break;
                }
            }

            // Если не дубликат, добавляем
            if (!duplicate) {
                tempC[sizeC] = B[i];
                sizeC++;
            }
        }
    }

    // Создаем массив C минимального размера
    int* C = new int[sizeC];
    for (int i = 0; i < sizeC; i++) {
        C[i] = tempC[i];
    }

    
    cout << "\nМассив C (элементы, не общие для A и B, без повторений):\n";
    cout << "Размер: " << sizeC << endl;
    cout << "Элементы: ";

    if (sizeC == 0) {
        cout << "пустой массив";
    }
    else {
        for (int i = 0; i < sizeC; i++) {
            cout << C[i] << " ";
        }
    }
    cout << endl;

    // Освобождаем память
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] tempC;

    return 0;
}