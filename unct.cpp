#include <iostream>
#include <cstring>
using namespace std;

void removeCharAtPosition(char str[], int position) {
    int length = strlen(str);

    if (position < 0 || position >= length) {
        cout << "Неверная позиция!" << endl;
        return;
    }

    // Сдвигаем все символы после позиции на одну позицию влево
    for (int i = position; i < length; i++) {
        str[i] = str[i + 1];
    }

    cout << "Символ на позиции " << position << " удален." << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    char str[100];
    int position;

    cout << "Введите строку: ";
    cin.getline(str, 100);

    cout << "Введите номер символа для удаления (начиная с 0): ";
    cin >> position;

    cout << "Исходная строка: " << str << endl;
    removeCharAtPosition(str, position);
    cout << "Результат: " << str << endl;

    return 0;
}

//2
void removeAllOccurrences(char str[], char ch) {
    int length = strlen(str);
    int j = 0; // Индекс для новой строки

    for (int i = 0; i <= length; i++) {
        if (str[i] != ch) {
            str[j] = str[i];
            j++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    char str[100];
    char ch;

    cout << "Введите строку: ";
    cin.getline(str, 100);

    cout << "Введите символ для удаления: ";
    cin >> ch;

    cout << "Исходная строка: " << str << endl;
    removeAllOccurrences(str, ch);
    cout << "Результат (после удаления всех '" << ch << "'): " << str << endl;

    return 0;
}

//3
void insertCharAtPosition(char str[], char ch, int position) {
    int length = strlen(str);

    if (position < 0 || position > length) {
        cout << "Неверная позиция!" << endl;
        return;
    }

    // Сдвигаем символы вправо, начиная с конца
    for (int i = length; i >= position; i--) {
        str[i + 1] = str[i];
    }

    // Вставляем новый символ
    str[position] = ch;

    cout << "Символ '" << ch << "' вставлен на позицию " << position << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    char str[100];
    char ch;
    int position;

    cout << "Введите строку: ";
    cin.getline(str, 100);

    cout << "Введите символ для вставки: ";
    cin >> ch;

    cout << "Введите позицию для вставки (начиная с 0): ";
    cin >> position;

    cout << "Исходная строка: " << str << endl;
    insertCharAtPosition(str, ch, position);
    cout << "Результат: " << str << endl;

    return 0;
}

//4
void replaceDotsWithExclamation(char str[]) {
    int length = strlen(str);
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (str[i] == '.') {
            str[i] = '!';
            count++;
        }
    }

    cout << "Заменено " << count << " точек на восклицательные знаки." << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    char str[100];

    cout << "Введите строку (можно с точками): ";
    cin.getline(str, 100);

    cout << "Исходная строка: " << str << endl;
    replaceDotsWithExclamation(str);
    cout << "Результат: " << str << endl;

    // Пример
    cout << "\nПример работы:" << endl;
    char example[] = "Hello. World. Today is a good day.";
    cout << "До:   " << example << endl;
    replaceDotsWithExclamation(example);
    cout << "После: " << example << endl;

    return 0;
}

//5
int countCharacterOccurrences(char str[], char ch) {
    int length = strlen(str);
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (str[i] == ch) {
            count++;
        }
    }

    return count;
}

int main() {
    setlocale(LC_ALL, "ru");
    char str[100];
    char ch;

    cout << "Введите строку: ";
    cin.getline(str, 100);

    cout << "Введите символ для поиска: ";
    cin >> ch;

    int occurrences = countCharacterOccurrences(str, ch);

    cout << "Строка: " << str << endl;
    cout << "Символ '" << ch << "' встречается " << occurrences << " раз(а)" << endl;

    // Дополнительно: показываем позиции вхождений
    cout << "Позиции вхождения: ";
    bool found = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ch) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "не найдены";
    }
    cout << endl;

    return 0;
}