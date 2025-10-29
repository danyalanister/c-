#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*//1
int main() {
	char sym = 'A';
	cout << sym << endl;
	return 0;
}

//2
int main() {
	setlocale(LC_ALL, "ru");
	int number;
	cout << "Введите число: ";
	cin >> number;
	if (number % 2 == 0) {
		cout << "Число чётное" << endl;
	}
	else {
		cout << "Число нечётное" << endl;
		return 0;
	}
}

//3
int main() {
	setlocale(LC_ALL, "ru");
	cout << "Кубы первых десяти чисел: " << endl;
	for (int i = 1; i <= 10; i++) {
		cout << i << " куб= " << i * i * i << endl;
		return 0;
	}
}

//4
int findMaxElement() {
	const int SIZE = 8;
	int arr[SIZE];
	srand(time(NULL));
	cout << "Массив: ";
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << " ";
	}
	int max = arr[0];
	for (int i = 1; i < SIZE; i++) {
		if (arr[i] > max) {
			max = arr[i];

		}

	}
	cout << "Максимальный элемент: " << max << endl;
	return 0;
}

int main() {
	setlocale(LC_ALL, "ru");
	findMaxElement();
	return 0;
}
*/
//5
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	const int SIZE = 4;
	int arr[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			arr[i][j] = rand() % 20 + 1;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			sum += arr[i][j];

		}
	}
	cout << "Сумма элементов в двурмерном массиве: " << sum << endl;
	int count = SIZE * SIZE;
	double average = static_cast<double>(sum) / static_cast<double>(count);
	cout << "Среднее арифметическое элементов в двумерном: " << average << endl;

	int max = arr[0][0];
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (max < arr[i][j]) {
				max = arr[i][j];
			}
		}
	}
	cout << "Максимальный элемент в двумерном: " << max << endl;

	int min = arr[0][0];
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (min > arr[i][j]) {
				min = arr[i][j];
			}
		}
	}
	cout << "Минимальный элемент в двумерном: " << min << endl;
	return 0;
}
