
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <memory>
//2
enum class Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

// Функция: возвращает текстовое представление дня на русском
std::string dayToString(Day day) {
    switch (day) {
    case Day::Monday:    return "Понедельник";
    case Day::Tuesday:   return "Вторник";
    case Day::Wednesday: return "Среда";
    case Day::Thursday:  return "Четверг";
    case Day::Friday:    return "Пятница";
    case Day::Saturday:  return "Суббота";
    case Day::Sunday:    return "Воскресенье";
    default:
        throw std::invalid_argument("Неизвестный день недели");
    }
}

// Функция: проверяет, является ли день выходным
bool isWeekend(Day day) {
    return (day == Day::Saturday || day == Day::Sunday);
}

// Пример использования
int main() {
    setlocale(LC_ALL, "ru");
    try {
        Day today = Day::Saturday;

        std::cout << "Сегодня: " << dayToString(today) << std::endl;
        if (isWeekend(today)) {
            std::cout << "Это выходной день!" << std::endl;
        }
        else {
            std::cout << "Это будний день." << std::endl;
        }

        // Проверим все дни
        std::cout << "\nВсе дни недели:" << std::endl;
        for (int i = 0; i < 7; ++i) {
            Day d = static_cast<Day>(i);
            std::cout << dayToString(d)
                << " — "
                << (isWeekend(d) ? "выходной" : "будний")
                << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}

//7
enum class ConsoleColor {
    Reset = 0,      // Сброс цвета
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37
};

// Функция для вывода текста в указанном цвете
void printColoredText(ConsoleColor color, const std::string& text) {
    // ANSI escape-код: \033[<цвет>m
    std::cout << "\033[" << static_cast<int>(color) << "m" << text << "\033[0m" << std::endl;
}

// Пример использования
int main() {
    setlocale(LC_ALL, "ru");
    printColoredText(ConsoleColor::Red, "Это красный текст!");
    printColoredText(ConsoleColor::Green, "Это зелёный текст!");
    printColoredText(ConsoleColor::Blue, "Это синий текст!");
    printColoredText(ConsoleColor::Yellow, "Это жёлтый текст!");
    printColoredText(ConsoleColor::Magenta, "Это пурпурный текст!");
    printColoredText(ConsoleColor::Cyan, "Это бирюзовый текст!");
    printColoredText(ConsoleColor::White, "Это белый текст (по умолчанию).");
    printColoredText(ConsoleColor::Reset, "Цвет сброшен.");

    return 0;
}

//8
enum class SortOrder {
    Ascending,   // по возрастанию
    Descending   // по убыванию
};

// Функция сортировки массива чисел
template<typename T>
void sortArray(std::vector<T>& arr, SortOrder order) {
    if (order == SortOrder::Ascending) {
        std::sort(arr.begin(), arr.end());
    }
    else if (order == SortOrder::Descending) {
        std::sort(arr.begin(), arr.end(), std::greater<T>());
    }
}

// Вспомогательная функция для вывода массива
template<typename T>
void printArray(const std::vector<T>& arr, const std::string& label = "") {
    if (!label.empty()) {
        std::cout << label << ": ";
    }
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Пример использования
int main() {
    setlocale(LC_ALL, "ru");
    std::vector<int> numbers = { 64, 34, 25, 12, 22, 11, 90 };

    std::cout << "Исходный массив:" << std::endl;
    printArray(numbers);

    // Сортировка по возрастанию
    sortArray(numbers, SortOrder::Ascending);
    std::cout << "\nПосле сортировки по возрастанию:" << std::endl;
    printArray(numbers, "Результат");

    // Сортировка по убыванию
    sortArray(numbers, SortOrder::Descending);
    std::cout << "\nПосле сортировки по убыванию:" << std::endl;
    printArray(numbers, "Результат");

    return 0;
}

//3
enum class TrafficLight {
    Red,     // Красный
    Green,   // Зелёный
    Yellow   // Жёлтый
};

// Функция для получения текстового представления состояния
std::string toString(TrafficLight light) {
    switch (light) {
    case TrafficLight::Red:    return "Красный";
    case TrafficLight::Green:  return "Зелёный";
    case TrafficLight::Yellow: return "Жёлтый";
    default: return "Неизвестный";
    }
}

// Функция для перехода на следующее состояние по циклу
TrafficLight nextState(TrafficLight current) {
    switch (current) {
    case TrafficLight::Red:
        return TrafficLight::Green;
    case TrafficLight::Green:
        return TrafficLight::Yellow;
    case TrafficLight::Yellow:
        return TrafficLight::Red;
    default:
        return TrafficLight::Red; // На случай неожиданного значения
    }
}

// Пример использования
int main() {
    setlocale(LC_ALL, "ru");
    TrafficLight current = TrafficLight::Red;

    std::cout << "Светофор работает по циклу:" << std::endl;

    for (int i = 0; i < 8; ++i) { // Покажем несколько циклов
        std::cout << "Текущее состояние: " << toString(current) << std::endl;
        current = nextState(current);
    }

    return 0;
}

//1
enum class ErrorCode {
    Success,           // Успешное выполнение
    FileNotFound,      // Отсутствие файла
    AccessDenied,      // Отказ в доступе
    OutOfMemory        // Нехватка памяти
};

// Функция, возвращающая соответствующий код ошибки в зависимости от условия
ErrorCode getErrorCode(const std::string& condition) {
    if (condition == "success") {
        return ErrorCode::Success;
    }
    else if (condition == "file_not_found") {
        return ErrorCode::FileNotFound;
    }
    else if (condition == "access_denied") {
        return ErrorCode::AccessDenied;
    }
    else if (condition == "out_of_memory") {
        return ErrorCode::OutOfMemory;
    }
    else {
        return ErrorCode::Success; // По умолчанию — успех (или можно бросить исключение)
    }
}

// Вспомогательная функция: перевод кода ошибки в строку
std::string errorCodeToString(ErrorCode code) {
    switch (code) {
    case ErrorCode::Success:
        return "Успешно";
    case ErrorCode::FileNotFound:
        return "Ошибка: файл не найден";
    case ErrorCode::AccessDenied:
        return "Ошибка: доступ запрещён";
    case ErrorCode::OutOfMemory:
        return "Ошибка: нехватка памяти";
    default:
        return "Неизвестная ошибка";
    }
}

// Пример использования с имитацией условий
int main() {
    setlocale(LC_ALL, "ru");
    // Имитируем различные ситуации
    std::cout << "Тестирование кодов ошибок:" << std::endl;

    std::cout << "  • Успешное выполнение: "
        << errorCodeToString(getErrorCode("success")) << std::endl;

    std::cout << "  • Файл не найден: "
        << errorCodeToString(getErrorCode("file_not_found")) << std::endl;

    std::cout << "  • Доступ запрещён: "
        << errorCodeToString(getErrorCode("access_denied")) << std::endl;

    std::cout << "  • Нехватка памяти: "
        << errorCodeToString(getErrorCode("out_of_memory")) << std::endl;

    std::cout << "  • Неизвестное условие: "
        << errorCodeToString(getErrorCode("unknown")) << std::endl;

    // Пример реального использования — попытка выделить память
    try {
        std::cout << "\nПопытка выделить память..." << std::endl;
        auto ptr = std::make_unique<int[]>(1000000000); // Попробуем выделить много памяти
        std::cout << "✅ Память выделена успешно." << std::endl;
    }
    catch (const std::bad_alloc&) {
        std::cout << "❌ " << errorCodeToString(ErrorCode::OutOfMemory) << std::endl;
    }

    return 0;
}