#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//1
struct Point {
    double x, y;
};

struct Rectangle {
    Point topLeft;
    double width, height;
};


void moveRectangle(Rectangle& rect, double dx, double dy) {
    rect.topLeft.x += dx;
    rect.topLeft.y += dy;
}


void resizeRectangle(Rectangle& rect, double newWidth, double newHeight) {
    if (newWidth >= 0) rect.width = newWidth;
    if (newHeight >= 0) rect.height = newHeight;
}


void printRectangle(const Rectangle& rect) {
    cout << "Прямоугольник:" << endl;
    cout << "Верхний левый угол: (" << rect.topLeft.x << ", " << rect.topLeft.y << ")" << endl;
    cout << "Ширина: " << rect.width << ", Высота: " << rect.height << endl;

    cout << "Углы: ";
    cout << "(" << rect.topLeft.x << ", " << rect.topLeft.y << ") ";
    cout << "(" << rect.topLeft.x + rect.width << ", " << rect.topLeft.y << ") ";
    cout << "(" << rect.topLeft.x << ", " << rect.topLeft.y + rect.height << ") ";
    cout << "(" << rect.topLeft.x + rect.width << ", " << rect.topLeft.y + rect.height << ")" << endl;
}

double distanceBetweenPoints(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}


struct Fraction {
    int numerator;    
    int denominator;  
};

int findGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplifyFraction(Fraction& f) {
    if (f.denominator < 0) {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }

    int divisor = findGCD(f.numerator, f.denominator);
    if (divisor != 0) {
        f.numerator /= divisor;
        f.denominator /= divisor;
    }
}

void printFraction(const Fraction& f) {
    if (f.denominator == 1) {
        cout << f.numerator;
    }
    else {
        cout << f.numerator << "/" << f.denominator;
    }
}

void printMixedFraction(const Fraction& f) {
    if (abs(f.numerator) < f.denominator || f.denominator == 1) {
        printFraction(f);
    }
    else {
        int whole = f.numerator / f.denominator;
        int remainder = abs(f.numerator) % f.denominator;

        if (whole != 0) {
            cout << whole;
        }

        if (remainder != 0) {
            if (whole != 0) cout << " ";
            cout << remainder << "/" << f.denominator;
        }
    }
}

Fraction addFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    simplifyFraction(result);
    return result;
}

Fraction subtractFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    simplifyFraction(result);
    return result;
}

Fraction multiplyFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    simplifyFraction(result);
    return result;
}

Fraction divideFractions(Fraction f1, Fraction f2) {
    Fraction result;

    if (f2.numerator == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        result.numerator = 0;
        result.denominator = 1;
        return result;
    }

    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    simplifyFraction(result);
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "1" << endl;

    Rectangle rect;
    rect.topLeft.x = 1;
    rect.topLeft.y = 2;
    rect.width = 5;
    rect.height = 3;

    cout << "Исходный прямоугольник:" << endl;
    printRectangle(rect);

    cout << "\nПосле перемещения на (2, -1):" << endl;
    moveRectangle(rect, 2, -1);
    printRectangle(rect);

    cout << "\nПосле изменения размера (7, 4):" << endl;
    resizeRectangle(rect, 7, 4);
    printRectangle(rect);

    cout << "\n2" << endl;

    Point p1, p2;
    p1.x = 1; p1.y = 1;
    p2.x = 4; p2.y = 5;

    cout << "Точка 1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "Точка 2: (" << p2.x << ", " << p2.y << ")" << endl;

    double dist = distanceBetweenPoints(p1, p2);
    cout << "Расстояние между точками: " << dist << endl;

    cout << "\n3" << endl;

    Fraction f1, f2;
    f1.numerator = 3; f1.denominator = 4;
    f2.numerator = 2; f2.denominator = 5;

    cout << "Дробь 1: ";
    printFraction(f1);
    cout << " = ";
    printMixedFraction(f1);
    cout << endl;

    cout << "Дробь 2: ";
    printFraction(f2);
    cout << " = ";
    printMixedFraction(f2);
    cout << endl;

    Fraction sum = addFractions(f1, f2);
    cout << "Сумма: ";
    printFraction(f1);
    cout << " + ";
    printFraction(f2);
    cout << " = ";
    printFraction(sum);
    cout << " = ";
    printMixedFraction(sum);
    cout << endl;

    Fraction diff = subtractFractions(f1, f2);
    cout << "Разность: ";
    printFraction(f1);
    cout << " - ";
    printFraction(f2);
    cout << " = ";
    printFraction(diff);
    cout << endl;

    Fraction prod = multiplyFractions(f1, f2);
    cout << "Произведение: ";
    printFraction(f1);
    cout << " * ";
    printFraction(f2);
    cout << " = ";
    printFraction(prod);
    cout << endl;

    Fraction quot = divideFractions(f1, f2);
    cout << "Частное: ";
    printFraction(f1);
    cout << " / ";
    printFraction(f2);
    cout << " = ";
    printFraction(quot);
    cout << endl;

    // Пример с неправильной дробью
    Fraction f3;
    f3.numerator = 7; f3.denominator = 3;
    cout << "\nПример неправильной дроби: ";
    printFraction(f3);
    cout << " = ";
    printMixedFraction(f3);
    cout << endl;

    return 0;
}