#include <vector>
#include <string>
#include <iostream>

void addStringToEnd(std::vector<std::string>& arr, const std::string& str) {
    arr.push_back(str);
}

void addStringToBeginning(std::vector<std::string>& arr, const std::string& str) {
    arr.insert(arr.begin(), str);
}

void addStringAtPosition(std::vector<std::string>& arr, const std::string& str, size_t pos) {
    if (pos > arr.size()) {
        arr.push_back(str);
    }
    else {
        arr.insert(arr.begin() + pos, str);
    }
}

bool removeStringByIndex(std::vector<std::string>& arr, size_t index) {
    if (index >= arr.size()) {
        return false;
    }
    arr.erase(arr.begin() + index);
    return true;
}

void printArray(const std::vector<std::string>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "[" << i << "] " << arr[i] << std::endl;
    }
    std::cout << "-------------------" << std::endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<std::string> matrix;

    std::cout << "Исходный массив:" << std::endl;
    printArray(matrix);

    addStringToEnd(matrix, "Первая строка");
    addStringToBeginning(matrix, "Начало");
    addStringAtPosition(matrix, "Середина", 1);
    addStringAtPosition(matrix, "Конец", 100); // выходит за границу — добавится в конец

    std::cout << "После добавлений:" << std::endl;
    printArray(matrix);

    if (removeStringByIndex(matrix, 2)) {
        std::cout << "Удалена строка под индексом 2." << std::endl;
    }
    else {
        std::cout << "Ошибка: индекс 2 не существует." << std::endl;
    }

    std::cout << "После удаления:" << std::endl;
    printArray(matrix);

    return 0;
}