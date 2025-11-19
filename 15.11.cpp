#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
//1
string convertToBase(int number, int base) {
    if (base < 2 || base > 36) {
        return "Error!";
    }

    string result = "";
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (number > 0) {
        result += digits[number % base];
        number /= base;
    }

    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}
//2
int rollDice() {
    return rand() % 6 + 1;
}

void displayDice(int value) {
    cout << "[" << value << "] ";
}

void playDiceGame() {
    srand(time(0));

    int humanTotal = 0, computerTotal = 0;
    bool humanFirst = true; // true - человек ходит первым

    cout << "=== game ===\n";

    for (int round = 1; round <= 5; round++) {
        cout << "\n--- round " << round << " ---\n";

        int humanRoll, computerRoll;

        if (humanFirst) {
            humanRoll = rollDice();
            cout << "your: ";
            displayDice(humanRoll);
            humanTotal += humanRoll;

            computerRoll = rollDice();
            cout << "\ncompucter: ";
            displayDice(computerRoll);
            computerTotal += computerRoll;
        }
        else {
            computerRoll = rollDice();
            cout << "compucter: ";
            displayDice(computerRoll);
            computerTotal += computerRoll;

            humanRoll = rollDice();
            cout << "\nyour: ";
            displayDice(humanRoll);
            humanTotal += humanRoll;
        }

        cout << "\n";
    }

 
    cout << "\n=== result ===\n";
    cout << "your sum: " << humanTotal << " (srednee: " << humanTotal / 5.0 << ")\n";
    cout << "compucter sum: " << computerTotal << " (srednee: " << computerTotal / 5.0 << ")\n";

    if (humanTotal > computerTotal) {
        cout << "you win!\n";
    }
    else if (computerTotal > humanTotal) {
        cout << "compucter win!\n";
    }
    else {
        cout << "nichya!\n";
    }
}
//3
void drawRectangle(int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}
//4
long long factorial(int n) {
    if (n < 0) return -1; // Ошибка для отрицательных чисел
    if (n == 0 || n == 1) return 1;

    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
//5
bool isPrime(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}