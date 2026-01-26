#include <iostream>
#include <string>
using namespace std;
//1

struct Complex {
    double real;
    double imag;
};


Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}


Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}


Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}


Complex divide(Complex a, Complex b) {
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;

    if (denominator == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        result.real = 0;
        result.imag = 0;
        return result;
    }

    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}


void printComplex(Complex c) {
    if (c.imag >= 0) {
        cout << c.real << " + " << c.imag << "i" << endl;
    }
    else {
        cout << c.real << " - " << -c.imag << "i" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    Complex num1 = { 3, 2 };  // 3 + 2i
    Complex num2 = { 1, 7 };  // 1 + 7i

    cout << "Первое число: ";
    printComplex(num1);

    cout << "Второе число: ";
    printComplex(num2);

    cout << "\nРезультаты операций:" << endl;

    cout << "Сумма: ";
    printComplex(add(num1, num2));

    cout << "Разность: ";
    printComplex(subtract(num1, num2));

    cout << "Умножение: ";
    printComplex(multiply(num1, num2));

    cout << "Деление: ";
    printComplex(divide(num1, num2));

    return 0;
}

//2
enum TransmissionType {
    MANUAL,    
    AUTOMATIC,  
    ROBOTIC,    
    CVT         
};

// Структура для автомобиля
struct Car {
    double length;          
    double groundClearance; 
    double engineVolume;    
    int enginePower;        
    int wheelDiameter;      
    string color;           
    TransmissionType transmission; 
};

// Функция для задания значений автомобиля
void setCarValues(Car& car) {
    cout << "Введите длину автомобиля (м): ";
    cin >> car.length;

    cout << "Введите клиренс (мм): ";
    cin >> car.groundClearance;

    cout << "Введите объем двигателя (л): ";
    cin >> car.engineVolume;

    cout << "Введите мощность двигателя (л.с.): ";
    cin >> car.enginePower;

    cout << "Введите диаметр колес (дюймы): ";
    cin >> car.wheelDiameter;

    cout << "Введите цвет: ";
    cin >> car.color;

    cout << "Выберите тип коробки передач (0-Мех., 1-Авт., 2-Робот, 3-Вариатор): ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 0: car.transmission = MANUAL; break;
    case 1: car.transmission = AUTOMATIC; break;
    case 2: car.transmission = ROBOTIC; break;
    case 3: car.transmission = CVT; break;
    default: car.transmission = MANUAL;
    }
}

// Функция для отображения значений автомобиля
void displayCar(Car car) {
    cout << "\n=== Характеристики автомобиля ===" << endl;
    cout << "Длина: " << car.length << " м" << endl;
    cout << "Клиренс: " << car.groundClearance << " мм" << endl;
    cout << "Объем двигателя: " << car.engineVolume << " л" << endl;
    cout << "Мощность двигателя: " << car.enginePower << " л.с." << endl;
    cout << "Диаметр колес: " << car.wheelDiameter << " дюймов" << endl;
    cout << "Цвет: " << car.color << endl;

    cout << "Тип коробки передач: ";
    switch (car.transmission) {
    case MANUAL: cout << "Механическая"; break;
    case AUTOMATIC: cout << "Автоматическая"; break;
    case ROBOTIC: cout << "Роботизированная"; break;
    case CVT: cout << "Вариатор"; break;
    }
    cout << endl;
}

// Функция для поиска автомобилей по характеристикам
void searchByParameter(Car cars[], int count) {
    int choice;
    cout << "\n=== Поиск автомобилей ===" << endl;
    cout << "Поиск по: " << endl;
    cout << "1. Минимальной мощности двигателя" << endl;
    cout << "2. Максимальному объему двигателя" << endl;
    cout << "3. Цвету" << endl;
    cout << "4. Типу коробки передач" << endl;
    cout << "Выберите критерий поиска: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int minPower;
        cout << "Введите минимальную мощность (л.с.): ";
        cin >> minPower;

        cout << "\nНайденные автомобили:" << endl;
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (cars[i].enginePower >= minPower) {
                displayCar(cars[i]);
                found = true;
            }
        }
        if (!found) cout << "Автомобили не найдены!" << endl;
        break;
    }

    case 2: {
        double maxVolume;
        cout << "Введите максимальный объем (л): ";
        cin >> maxVolume;

        cout << "\nНайденные автомобили:" << endl;
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (cars[i].engineVolume <= maxVolume) {
                displayCar(cars[i]);
                found = true;
            }
        }
        if (!found) cout << "Автомобили не найдены!" << endl;
        break;
    }

    case 3: {
        string searchColor;
        cout << "Введите цвет: ";
        cin >> searchColor;

        cout << "\nНайденные автомобили:" << endl;
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (cars[i].color == searchColor) {
                displayCar(cars[i]);
                found = true;
            }
        }
        if (!found) cout << "Автомобили не найдены!" << endl;
        break;
    }

    case 4: {
        int typeChoice;
        cout << "Выберите тип коробки (0-Мех., 1-Авт., 2-Робот, 3-Вариатор): ";
        cin >> typeChoice;

        TransmissionType searchType;
        switch (typeChoice) {
        case 0: searchType = MANUAL; break;
        case 1: searchType = AUTOMATIC; break;
        case 2: searchType = ROBOTIC; break;
        case 3: searchType = CVT; break;
        default: searchType = MANUAL;
        }

        cout << "\nНайденные автомобили:" << endl;
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (cars[i].transmission == searchType) {
                displayCar(cars[i]);
                found = true;
            }
        }
        if (!found) cout << "Автомобили не найдены!" << endl;
        break;
    }

    default:
        cout << "Неверный выбор!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    const int MAX_CARS = 10;
    Car cars[MAX_CARS];
    int carCount = 0;
    int choice;

    do {
        cout << "\n=== Меню ===" << endl;
        cout << "1. Добавить автомобиль" << endl;
        cout << "2. Показать все автомобили" << endl;
        cout << "3. Поиск автомобилей" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (carCount < MAX_CARS) {
                cout << "\nДобавление автомобиля №" << carCount + 1 << endl;
                setCarValues(cars[carCount]);
                carCount++;
            }
            else {
                cout << "Достигнуто максимальное количество автомобилей!" << endl;
            }
            break;

        case 2:
            if (carCount == 0) {
                cout << "Нет добавленных автомобилей!" << endl;
            }
            else {
                for (int i = 0; i < carCount; i++) {
                    cout << "\nАвтомобиль №" << i + 1 << ":";
                    displayCar(cars[i]);
                }
            }
            break;

        case 3:
            if (carCount == 0) {
                cout << "Нет добавленных автомобилей!" << endl;
            }
            else {
                searchByParameter(cars, carCount);
            }
            break;

        case 0:
            cout << "Выход из программы..." << endl;
            break;

        default:
            cout << "Неверный выбор!" << endl;
        }

    } while (choice != 0);

    return 0;
}