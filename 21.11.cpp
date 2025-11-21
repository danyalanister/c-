#include <iostream>
#include <algorithm>
using namespace std;
//1
int main() {
    setlocale(LC_ALL, "ru");
    int arr[] = { 5, 3, 8, 4, 2 };
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
//2
int main() {
    setlocale(LC_ALL, "ru");
    int arr[] = { 5, 3, 8, 4, 2 };
    int n = 5;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
//3
int main() {
    setlocale(LC_ALL, "ru");
    int grades[10];
    cout << "Введите 10 оценок: ";
    for (int i = 0; i < 10; i++) {
        cin >> grades[i];
    }

    int choice;
    do {
        cout << "\n1 - Вывод оценок\n2 - Пересдача\n3 - Стипендия\n0 - Выход\n";
        cin >> choice;
        if (choice == 1) {
            for (int i = 0; i < 10; i++) {
                cout << grades[i] << " ";
            }
            cout << endl;
        }
        else if (choice == 2) {
            int index, newGrade;
            cout << "Введите номер элемента (0-9): ";
            cin >> index;
            cout << "Введите новую оценку: ";
            cin >> newGrade;
            grades[index] = newGrade;
        }
        else if (choice == 3) {
            double sum = 0;
            for (int i = 0; i < 10; i++) {
                sum += grades[i];
            }
            double average = sum / 10;
            cout << "Средний балл: " << average << endl;
            if (average >= 10.7) {
                cout << "Стипендия выходит!\n";
            }
            else {
                cout << "Стипендия не выходит.\n";
            }
        }
    } while (choice != 0);

    return 0;
}
//4
#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

int main() {
    setlocale(LC_ALL, "ru");
    int arr[] = { 5, 3, 8, 4, 2 };
    int n = 5;

    quickSort(arr, 0, n - 1);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
//5
int main() {
    setlocale(LC_ALL, "ru");
    int arr[] = { 5, -3, 8, -4, 2, 7, 1, -1, 6, 0 };
    int n = 10;

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int sortLimit;
    if (sum / n > 0) {
        sortLimit = (2 * n) / 3; // Первые 2/3
    }
    else {
        sortLimit = n / 3; // Первая 1/3
    }

    // Сортировка выбранной части
    for (int i = 0; i < sortLimit - 1; i++) {
        for (int j = 0; j < sortLimit - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Обратный порядок для оставшейся части
    for (int i = sortLimit; i < (sortLimit + n) / 2; i++) {
        swap(arr[i], arr[n - 1 - i + sortLimit]);
    }

    cout << "Результат: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}