#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;


struct Employee {
    int id;
    string lastName;
    string firstName;
    string middleName;
    int age;
    string position;
    double salary;
};

class EmployeeSystem {
private:
    vector<Employee> employees;
    int nextId;
    string currentFilename;

    string toLower(const string& str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    bool startsWith(const string& str, char letter) {
        if (str.empty()) return false;
        return tolower(str[0]) == tolower(letter);
    }

public:
    EmployeeSystem() : nextId(1) {}

    bool loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Не удалось открыть файл: " << filename << endl;
            return false;
        }

        employees.clear();
        nextId = 1;

        Employee emp;
        while (file >> emp.id >> emp.lastName >> emp.firstName >> emp.middleName
            >> emp.age >> emp.position >> emp.salary) {
            employees.push_back(emp);
            if (emp.id >= nextId) {
                nextId = emp.id + 1;
            }
        }

        file.close();
        currentFilename = filename;
        cout << "Данные загружены из файла: " << filename << endl;
        cout << "Загружено сотрудников: " << employees.size() << endl;
        return true;
    }

    bool saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Не удалось создать файл: " << filename << endl;
            return false;
        }

        for (const auto& emp : employees) {
            file << emp.id << " " << emp.lastName << " " << emp.firstName << " "
                << emp.middleName << " " << emp.age << " " << emp.position << " "
                << emp.salary << endl;
        }

        file.close();
        cout << "Данные сохранены в файл: " << filename << endl;
        cout << "Сохранено сотрудников: " << employees.size() << endl;
        return true;
    }

    bool autoSave() {
        if (currentFilename.empty()) {
            cout << "Не указан файл для сохранения" << endl;
            return false;
        }
        return saveToFile(currentFilename);
    }

    void addEmployee() {
        Employee emp;
        emp.id = nextId++;

        cout << "\n=== Добавление нового сотрудника ===" << endl;
        cout << "Фамилия: ";
        cin >> emp.lastName;
        cout << "Имя: ";
        cin >> emp.firstName;
        cout << "Отчество: ";
        cin >> emp.middleName;
        cout << "Возраст: ";
        cin >> emp.age;
        cout << "Должность: ";
        cin.ignore();
        getline(cin, emp.position);
        cout << "Зарплата: ";
        cin >> emp.salary;

        employees.push_back(emp);
        cout << "Сотрудник успешно добавлен! ID: " << emp.id << endl;
    }

    void editEmployee() {
        int id;
        cout << "\n=== Редактирование сотрудника ===" << endl;
        cout << "Введите ID сотрудника для редактирования: ";
        cin >> id;

        auto it = find_if(employees.begin(), employees.end(),
            [id](const Employee& emp) { return emp.id == id; });

        if (it == employees.end()) {
            cout << "Сотрудник с ID " << id << " не найден!" << endl;
            return;
        }

        cout << "\nТекущие данные сотрудника:" << endl;
        displayEmployee(*it);

        cout << "\nВведите новые данные (оставьте пустым, чтобы не изменять):" << endl;

        string input;
        cout << "Фамилия (" << it->lastName << "): ";
        cin >> input;
        if (!input.empty()) it->lastName = input;

        cout << "Имя (" << it->firstName << "): ";
        cin >> input;
        if (!input.empty()) it->firstName = input;

        cout << "Отчество (" << it->middleName << "): ";
        cin >> input;
        if (!input.empty()) it->middleName = input;

        cout << "Возраст (" << it->age << "): ";
        cin >> input;
        if (!input.empty()) it->age = stoi(input);

        cout << "Должность (" << it->position << "): ";
        cin.ignore();
        getline(cin, input);
        if (!input.empty()) it->position = input;

        cout << "Зарплата (" << it->salary << "): ";
        cin >> input;
        if (!input.empty()) it->salary = stod(input);

        cout << "Данные сотрудника обновлены!" << endl;
    }

    void deleteEmployee() {
        int id;
        cout << "\n=== Удаление сотрудника ===" << endl;
        cout << "Введите ID сотрудника для удаления: ";
        cin >> id;

        auto it = find_if(employees.begin(), employees.end(),
            [id](const Employee& emp) { return emp.id == id; });

        if (it == employees.end()) {
            cout << "Сотрудник с ID " << id << " не найден!" << endl;
            return;
        }

        cout << "Вы действительно хотите удалить сотрудника?" << endl;
        displayEmployee(*it);
        cout << "1 - Да, 0 - Нет: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            employees.erase(it);
            cout << "Сотрудник удален!" << endl;
        }
        else {
            cout << "Удаление отменено." << endl;
        }
    }

    void searchByLastName() {
        string lastName;
        cout << "\n=== Поиск по фамилии ===" << endl;
        cout << "Введите фамилию для поиска: ";
        cin >> lastName;

        vector<Employee> foundEmployees;
        for (const auto& emp : employees) {
            if (toLower(emp.lastName) == toLower(lastName)) {
                foundEmployees.push_back(emp);
            }
        }

        if (foundEmployees.empty()) {
            cout << "Сотрудники с фамилией '" << lastName << "' не найдены!" << endl;
        }
        else {
            cout << "\nНайдено сотрудников: " << foundEmployees.size() << endl;
            displayEmployeeList(foundEmployees);

            
            cout << "\nСохранить результаты поиска в файл? (1 - Да, 0 - Нет): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "Введите имя файла для сохранения: ";
                string filename;
                cin >> filename;
                saveSearchResults(foundEmployees, filename);
            }
        }
    }

    void displayByAge() {
        int age;
        cout << "\n=== Сотрудники по возрасту ===" << endl;
        cout << "Введите возраст: ";
        cin >> age;

        vector<Employee> foundEmployees;
        for (const auto& emp : employees) {
            if (emp.age == age) {
                foundEmployees.push_back(emp);
            }
        }

        if (foundEmployees.empty()) {
            cout << "Сотрудники возраста " << age << " лет не найдены!" << endl;
        }
        else {
            cout << "\nСотрудники возраста " << age << " лет:" << endl;
            cout << "Найдено: " << foundEmployees.size() << endl;
            displayEmployeeList(foundEmployees);

            cout << "\nСохранить результаты в файл? (1 - Да, 0 - Нет): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "Введите имя файла для сохранения: ";
                string filename;
                cin >> filename;
                saveSearchResults(foundEmployees, filename);
            }
        }
    }

    void displayByFirstLetter() {
        char letter;
        cout << "\n=== Сотрудники по первой букве фамилии ===" << endl;
        cout << "Введите букву: ";
        cin >> letter;

        vector<Employee> foundEmployees;
        for (const auto& emp : employees) {
            if (startsWith(emp.lastName, letter)) {
                foundEmployees.push_back(emp);
            }
        }

        if (foundEmployees.empty()) {
            cout << "Сотрудники с фамилией на букву '" << letter << "' не найдены!" << endl;
        }
        else {
            cout << "\nСотрудники с фамилией на букву '" << letter << "':" << endl;
            cout << "Найдено: " << foundEmployees.size() << endl;
            displayEmployeeList(foundEmployees);

            cout << "\nСохранить результаты в файл? (1 - Да, 0 - Нет): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "Введите имя файла для сохранения: ";
                string filename;
                cin >> filename;
                saveSearchResults(foundEmployees, filename);
            }
        }
    }

    void displayAllEmployees() {
        cout << "\n=== Все сотрудники ===" << endl;
        cout << "Общее количество: " << employees.size() << endl;

        if (employees.empty()) {
            cout << "Список сотрудников пуст!" << endl;
        }
        else {
            displayEmployeeList(employees);
        }
    }

    void displayEmployee(const Employee& emp) {
        cout << "ID: " << emp.id << endl;
        cout << "ФИО: " << emp.lastName << " " << emp.firstName << " " << emp.middleName << endl;
        cout << "Возраст: " << emp.age << " лет" << endl;
        cout << "Должность: " << emp.position << endl;
        cout << "Зарплата: " << fixed << setprecision(2) << emp.salary << " руб." << endl;
    }

    void displayEmployeeList(const vector<Employee>& empList) {
        cout << "\n" << string(80, '-') << endl;
        cout << left << setw(5) << "ID"
            << setw(15) << "Фамилия"
            << setw(15) << "Имя"
            << setw(15) << "Отчество"
            << setw(10) << "Возраст"
            << setw(20) << "Должность"
            << setw(12) << "Зарплата" << endl;
        cout << string(80, '-') << endl;

        for (const auto& emp : empList) {
            cout << left << setw(5) << emp.id
                << setw(15) << emp.lastName
                << setw(15) << emp.firstName
                << setw(15) << emp.middleName
                << setw(10) << emp.age
                << setw(20) << emp.position
                << setw(12) << fixed << setprecision(2) << emp.salary << endl;
        }
        cout << string(80, '-') << endl;
    }

    void saveSearchResults(const vector<Employee>& results, const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Не удалось создать файл: " << filename << endl;
            return;
        }

        file << "Результаты поиска\n";
        file << "Найдено сотрудников: " << results.size() << "\n\n";

        for (const auto& emp : results) {
            file << "ID: " << emp.id << "\n";
            file << "ФИО: " << emp.lastName << " " << emp.firstName << " " << emp.middleName << "\n";
            file << "Возраст: " << emp.age << " лет\n";
            file << "Должность: " << emp.position << "\n";
            file << "Зарплата: " << fixed << setprecision(2) << emp.salary << " руб.\n";
            file << string(40, '-') << "\n";
        }

        file.close();
        cout << "Результаты поиска сохранены в файл: " << filename << endl;
    }

    void run() {
        cout << "=== Информационная система 'Сотрудники' ===\n" << endl;

        cout << "Введите имя файла для загрузки данных: ";
        string filename;
        cin >> filename;

        if (!loadFromFile(filename)) {
            cout << "Создать новый файл? (1 - Да, 0 - Нет): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                currentFilename = filename;
                cout << "Готово к работе с новым файлом." << endl;
            }
            else {
                return;
            }
        }

        int choice;
        do {
            cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << endl;
            cout << "1. Добавить сотрудника" << endl;
            cout << "2. Редактировать сотрудника" << endl;
            cout << "3. Удалить сотрудника" << endl;
            cout << "4. Поиск по фамилии" << endl;
            cout << "5. Показать всех сотрудников" << endl;
            cout << "6. Показать сотрудников по возрасту" << endl;
            cout << "7. Показать сотрудников по первой букве фамилии" << endl;
            cout << "8. Сохранить данные в файл" << endl;
            cout << "0. Выход" << endl;
            cout << "Выберите действие: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                editEmployee();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                searchByLastName();
                break;
            case 5:
                displayAllEmployees();
                break;
            case 6:
                displayByAge();
                break;
            case 7:
                displayByFirstLetter();
                break;
            case 8:
                cout << "Введите имя файла для сохранения: ";
                cin >> filename;
                saveToFile(filename);
                break;
            case 0:
                cout << "Выход из программы..." << endl;
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
            }
        } while (choice != 0);

        
        cout << "\nАвтоматическое сохранение данных..." << endl;
        autoSave();
        cout << "Программа завершена." << endl;
    }
};

int main() {
    
    setlocale(LC_ALL, "ru");

    EmployeeSystem system;
    system.run();

    return 0;
}