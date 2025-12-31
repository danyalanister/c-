#include <iostream>
#include <cctype>  // для isalpha, isdigit и т.д.
using namespace std;

int main() {
    int choice;
    cout << "Выберите номер задания (1-7): ";
    cin >> choice;
    cin.ignore();  // очистить буфер после ввода числа

    string s;

    if (choice == 1) {
        // Задание 1: Реверс строки
        cout << "Введите строку: ";
        getline(cin, s);
        string rev = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            rev += s[i];
        }
        cout << "Результат: " << rev << endl;
    }

    else if (choice == 2) {
        // Задание 2: Подсчёт символов
        cout << "Введите строку: ";
        getline(cin, s);
        int letters = 0, digits = 0, spaces = 0, others = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isalpha(c)) letters++;
            else if (isdigit(c)) digits++;
            else if (c == ' ') spaces++;
            else others++;
        }
        cout << "Буквы: " << letters << endl;
        cout << "Цифры: " << digits << endl;
        cout << "Пробелы: " << spaces << endl;
        cout << "Другие: " << others << endl;
    }

    else if (choice == 3) {
        // Задание 3: Удалить повторяющиеся символы (оставить первое вхождение)
        cout << "Введите строку: ";
        getline(cin, s);
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            bool found = false;
            for (int j = 0; j < result.length(); j++) {
                if (s[i] == result[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result += s[i];
            }
        }
        cout << "Результат: " << result << endl;
    }

    else if (choice == 4) {
        // Задание 4: Проверка префикса и суффикса
        string str, pref, suff;
        cout << "Введите строку: ";
        getline(cin, str);
        cout << "Введите префикс: ";
        getline(cin, pref);
        cout << "Введите суффикс: ";
        getline(cin, suff);

        // Проверка префикса
        bool starts = true;
        if (pref.length() > str.length()) starts = false;
        else {
            for (int i = 0; i < pref.length(); i++) {
                if (str[i] != pref[i]) {
                    starts = false;
                    break;
                }
            }
        }

        // Проверка суффикса
        bool ends = true;
        if (suff.length() > str.length()) ends = false;
        else {
            int start = str.length() - suff.length();
            for (int i = 0; i < suff.length(); i++) {
                if (str[start + i] != suff[i]) {
                    ends = false;
                    break;
                }
            }
        }

        cout << "Начинается с \"" << pref << "\": " << (starts ? "да" : "нет") << endl;
        cout << "Заканчивается на \"" << suff << "\": " << (ends ? "да" : "нет") << endl;
    }

    else if (choice == 5) {
        // Задание 5: Формат имени — Фамилия И.О.
        cout << "Введите полное имя (Фамилия Имя Отчество): ";
        string f, i, o;
        cin >> f >> i >> o;  // прочитает 1–3 слова

        cout << "Результат: " << f << " " << i[0] << ".";
        if (cin.peek() != '\n') { // если было введено отчество (или больше слов)
            cout << o[0] << ".";
        }
        cout << endl;
        // Примечание: работает для 2 или 3 слов. Для 1 слова — только фамилия.
    }

    else if (choice == 6) {
        // Задание 6: Форматирование телефонного номера (только цифры!)
        cout << "Введите номер (цифры, можно с символами): ";
        getline(cin, s);
        string digits = "";
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) digits += s[i];
        }

        // Оставляем только 10 цифр (если 11 — отбрасываем первую, если это 7 или 8)
        if (digits.length() == 11 && (digits[0] == '7' || digits[0] == '8')) {
            digits = digits.substr(1);
        }

        if (digits.length() != 10) {
            cout << "Ошибка: номер должен содержать 10 или 11 цифр (начиная с 7/8)." << endl;
        }
        else {
            cout << "+7 ("
                << digits[0] << digits[1] << digits[2] << ") "
                << digits[3] << digits[4] << digits[5] << "-"
                << digits[6] << digits[7] << "-"
                << digits[8] << digits[9] << endl;
        }
    }

    else if (choice == 7) {
        // Задание 7: Анализ текста — упрощённо (только слова из букв, без знаков)
        cout << "Введите текст (одно предложение, слова через пробел): ";
        getline(cin, s);

        string words[100];  // максимум 100 слов
        int count = 0;

        string word = "";
        for (int i = 0; i <= s.length(); i++) {
            char c = (i == s.length()) ? ' ' : s[i];
            if (isalpha(c)) {
                word += tolower(c);
            }
            else if (word != "") {
                words[count] = word;
                count++;
                word = "";
            }
        }

        // Подсчёт статистики
        int total = count;
        int unique = 0;
        string longest = "", shortest = "          "; // 10 пробелов — заведомо длинно
        string mostFreqWord = "";
        int maxFreq = 0;

        // Для подсчёта уникальных и частоты — простой перебор
        for (int i = 0; i < total; i++) {
            // длина
            if (words[i].length() > longest.length()) longest = words[i];
            if (words[i].length() < shortest.length()) shortest = words[i];

            // частота
            int freq = 0;
            for (int j = 0; j < total; j++) {
                if (words[i] == words[j]) freq++;
            }
            if (freq > maxFreq) {
                maxFreq = freq;
                mostFreqWord = words[i];
            }
        }

        // уникальные — перебором без повторов
        for (int i = 0; i < total; i++) {
            bool isNew = true;
            for (int j = 0; j < i; j++) {
                if (words[i] == words[j]) {
                    isNew = false;
                    break;
                }
            }
            if (isNew) unique++;
        }

        cout << "Всего слов: " << total << endl;
        cout << "Уникальных слов: " << unique << endl;
        cout << "Самое длинное слово: \"" << longest << "\" (" << longest.length() << " букв)" << endl;
        cout << "Самое короткое слово: \"" << shortest << "\" (" << shortest.length() << " буква)" << endl;
        cout << "Самое частое слово: \"" << mostFreqWord << "\" (" << maxFreq << " раз)" << endl;
    }

    else {
        cout << "Неверный номер задания." << endl;
    }

    return 0;
}