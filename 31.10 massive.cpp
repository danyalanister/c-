#include <iostream>
using namespace std;
//1
int main() {
    double arr[] = { -5.7, 6.0, 2.0, 0.0, -4.7, 6.0, 8.1, -4.0, 0.0 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 

    double positive = 0;
    for (int i = size - 1; i >= 0; i--) { 
        if (arr[i] > 0) {
            positive = arr[i];
            break;
        }
    }

    double negative = 0;
    for (int i = 0; i < size; i++) { 
        if (arr[i] < 0) {
            negative = arr[i];
            break;
        }
    }

    cout << "Last positive number: " << positive << endl;
    cout << "First negative number: " << negative << endl;

    return 0;
}
//2
int main() {
    
    int residents[4][5][2] = {
        {{4, 5}, {3, 6}, {5, 5}, {4, 5}, {6, 4}}, 
        {{5, 5}, {6, 4}, {4, 4}, {5, 5}, {3, 6}}, 
        {{4, 5}, {6, 4}, {5, 5}, {4, 5}, {6, 4}}, 
        {{5, 4}, {4, 6}, {5, 5}, {6, 4}, {4, 5}}  
    };

    int flat_number; 
    cout << "Enter flat number (1 to 10): ";
    cin >> flat_number;

    
    int floor = (flat_number - 1) / 2;
    int entrance = (flat_number - 1) / 2 / 5;

    
    cout << "Number of residents in flat " << flat_number << ": "
        << residents[entrance][floor][(flat_number - 1) % 2] << endl;

    
    int left_neighbor = (flat_number % 2 == 0) ? flat_number - 1 : flat_number + 1;
    int right_neighbor = (flat_number % 2 == 0) ? flat_number + 1 : flat_number - 1;
    cout << "Left neighbor: Flat " << left_neighbor << endl;
    cout << "Right neighbor: Flat " << right_neighbor << endl;

    
    int total_residents = 0;
    for (int i = 0; i < 5; i++) {
        total_residents += residents[entrance][i][0] + residents[entrance][i][1];
    }
    cout << "Total residents in entrance " << entrance + 1 << ": " << total_residents << endl;

    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 2; k++) {
                if (residents[i][j][k] > 5) {
                    cout << "Multichild family in flat " << i * 5 + j + 1 << endl;
                }
            }
        }
    }

    return 0;
}
//3
int main() {
    double temperatures[31] = {};
    double threshold = -5; 

   
    double sum = 0;
    for (int i = 0; i < 31; i++) {
        sum += temperatures[i];
    }
    double average = sum / 31;
    cout << "Average temperature for January: " << average << endl;

    
    int count = 0;
    for (int i = 0; i < 31; i++) {
        if (temperatures[i] < threshold) {
            count++;
        }
    }
    cout << "Number of days with temperature below " << threshold << ": " << count << endl;

    return 0;
}
//4
int main() {
    double prices[10] = {};
    double max_price = prices[0];
    int max_index = 0;

    
    for (int i = 1; i < 10; i++) {
        if (prices[i] > max_price) {
            max_price = prices[i];
            max_index = i;
        }
    }

    cout << "The most expensive car is car number " << max_index + 1
        << " with price " << max_price << endl;

    return 0;
}
//5
int main() {
    int arr[10] = {};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            int count = 0;
            for (int k = 0; k < size; k++) {
                if (arr[i] == arr[k]) {
                    count++;
                }
            }

            if (count >= 2) {
                cout << arr[i] << " appears " << count << " times" << endl;
            }
        }
    }

    return 0;
}