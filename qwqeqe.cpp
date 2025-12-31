#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Введите строку: ";
    getline(cin, s);

    // Проходим по каждому символу строки
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') { // если символ — пробел
            s[i] = '\t';   // заменяем его на табуляцию
        }
    }

    cout << "Результат: " << s << endl;
    return 0;
}

//2
#include <iostream>
#include <cctype> // для isalpha, isdigit
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Введите строку: ";
    getline(cin, s);

    int letters = 0, digits = 0, others = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isalpha(c)) {
            letters++;
        }
        else if (isdigit(c)) {
            digits++;
        }
        else {
            others++;
        }
    }

    cout << "Букв: " << letters << endl;
    cout << "Цифр: " << digits << endl;
    cout << "Остальных символов: " << others << endl;

    return 0;
}

//3
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Введите предложение: ";
    getline(cin, s);

    int wordCount = 0;
    bool inWord = false; // флаг: находимся ли мы внутри слова

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c != ' ' && c != '\t' && c != '\n') { // если символ — не пробел/табуляция/перевод строки
            if (!inWord) { // если до этого не были внутри слова — значит, началось новое слово
                wordCount++;
                inWord = true;
            }
        }
        else {
            inWord = false; // если пробел — вышли из слова
        }
    }

    cout << "Количество слов: " << wordCount << endl;
    return 0;
}

//4
#include <iostream>
#include <string>
#include <cctype> // для tolower
using namespace std;

int main() {
    string s;
    cout << "Введите строку: ";
    getline(cin, s);

    int len = s.length();
    bool isPalindrome = true;

    // Сравниваем символы с начала и с конца
    for (int i = 0; i < len / 2; i++) {
        char left = tolower(s[i]);      // левый символ (в нижнем регистре)
        char right = tolower(s[len - 1 - i]); // правый символ (в нижнем регистре)

        if (left != right) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "Строка является палиндромом." << endl;
    }
    else {
        cout << "Строка НЕ является палиндромом." << endl;
    }

    return 0;
}

