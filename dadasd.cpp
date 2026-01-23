#include <iostream>
using namespace std;
//1.1
// Объявление функций
int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div_func(int a, int b) {
    if (b == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return 0;
    }
    return a / b;
}

int main() {
    setlocale(LC_ALL, "ru");
    // Объявляем указатель на функцию
    int (*operation)(int, int);

    char op;
    int num1, num2;

    cout << "Введите два целых числа: ";
    cin >> num1 >> num2;

    cout << "Введите операцию (+, -, *, /): ";
    cin >> op;

    // Присваиваем указателю адрес соответствующей функции
    switch (op) {
    case '+':
        operation = sum;
        break;
    case '-':
        operation = sub;
        break;
    case '*':
        operation = mul;
        break;
    case '/':
        operation = div_func;
        break;
    default:
        cout << "Неверная операция!" << endl;
        return 1;
    }

    
    int result = operation(num1, num2);
    cout << "Результат: " << result << endl;

    return 0;
}

//1.2
// Функция сравнения строк в лексикографическом порядке
int compareStrings(const char* a, const char* b) {
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    return *(unsigned char*)a - *(unsigned char*)b;
}

int main() {
    setlocale(LC_ALL, "ru");
    // Объявляем указатель на функцию сравнения строк
    int (*compareFunc)(const char*, const char*) = compareStrings;

    const int MAX_LEN = 100;
    char str1[MAX_LEN], str2[MAX_LEN];

    cout << "Введите первую строку: ";
    cin.getline(str1, MAX_LEN);

    cout << "Введите вторую строку: ";
    cin.getline(str2, MAX_LEN);

    
    int result = compareFunc(str1, str2);

    
    if (result > 0) {
        cout << "Первая больше" << endl;
    }
    else if (result < 0) {
        cout << "Вторая больше" << endl;
    }
    else {
        cout << "Равны" << endl;
    }

    return 0;
}

//2.1
// Функция пузырьковой сортировки с компаратором
void bubbleSort(int arr[], int n, bool (*comp)(int, int)) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!comp(arr[j], arr[j + 1])) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


bool ascending(int a, int b) {
    return a <= b;
}


bool descending(int a, int b) {
    return a >= b;
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, n);

    
    bubbleSort(arr, n, ascending);
    cout << "По возрастанию: ";
    printArray(arr, n);

    
    bubbleSort(arr, n, descending);
    cout << "По убыванию: ";
    printArray(arr, n);

    return 0;
}

//2.2
#include <cmath>  // для sin(x)
// Функция численного интегрирования методом прямоугольников
double integrate(double a, double b, int n, double (*func)(double)) {
    double h = (b - a) / n;  // ширина каждого прямоугольника
    double sum = 0.0;

    
    for (int i = 0; i < n; ++i) {
        double x = a + i * h;
        sum += func(x) * h;
    }

    return sum;
}




double func_sin(double x) {
    return sin(x);
}


double func_x_squared(double x) {
    return x * x;
}

int main() {
    double a = 0.0, b = 2;  
    int n = 1000;  

    cout << "Интеграл sin(x) от " << a << " до " << b << ": "
        << integrate(a, b, n, func_sin) << endl;

    a = 0.0; b = 2.0;
    cout << "Интеграл x*x от " << a << " до " << b << ": "
        << integrate(a, b, n, func_x_squared) << endl;

    return 0;
}

//3.1
#include <string>
// Функции-действия (выводят сообщение)
void openFile() {
    cout << "✅ Файл открыт." << endl;
}

void saveFile() {
    cout << "💾 Файл сохранён." << endl;
}

void exitProgram() {
    cout << "👋 Выход из программы..." << endl;
    exit(0); 
}

int main() {
    setlocale(LC_ALL, "ru");
    
    void (*menuActions[])() = {
        openFile,
        saveFile,
        exitProgram
    };

    const int menuSize = 3; 

    int choice;

    while (true) {
        
        cout << "\n=== МЕНЮ ДЕЙСТВИЙ ===" << endl;
        cout << "1. Открыть файл" << endl;
        cout << "2. Сохранить файл" << endl;
        cout << "3. Выход" << endl;
        cout << "Выберите действие (1-" << menuSize << "): ";

        cin >> choice;

        
        if (choice >= 1 && choice <= menuSize) {
            
            menuActions[choice - 1](); 
        }
        else {
            cout << "❌ Неверный выбор. Попробуйте снова." << endl;
        }
    }

    return 0;
}

