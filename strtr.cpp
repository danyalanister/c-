#include <iostream>
#include <string>
using namespace std;


struct VideoStore {
    string title;       
    string director;    
    string genre;       
    double rating;      
    double price;      
};

VideoStore movies[100];
int movieCount = 0;  
void addMovie() {
    setlocale(LC_ALL, "ru");
    
    if (movieCount >= 100) {
        cout << "Видеомагазин полон! Нельзя добавить больше фильмов." << endl;
        return;
    }

    cout << "\n=== Добавление нового фильма ===" << endl;
    cout << "Название фильма: ";
    cin.ignore();
    getline(cin, movies[movieCount].title);

    cout << "Режиссер: ";
    getline(cin, movies[movieCount].director);

    cout << "Жанр: ";
    getline(cin, movies[movieCount].genre);

    cout << "Рейтинг популярности (0-10): ";
    cin >> movies[movieCount].rating;

    cout << "Цена диска: ";
    cin >> movies[movieCount].price;

    movieCount++;
    cout << "Фильм успешно добавлен!" << endl;
}

void showAllMovies() {
    setlocale(LC_ALL, "ru");
    
    if (movieCount == 0) {
        cout << "\nВидеомагазин пуст!" << endl;
        return;
    }

    cout << "\n=== Все фильмы в видеомагазине ===" << endl;
    cout << "Всего фильмов: " << movieCount << endl;

    for (int i = 0; i < movieCount; i++) {
        cout << "\nФильм #" << i + 1 << endl;
        cout << "Название: " << movies[i].title << endl;
        cout << "Режиссер: " << movies[i].director << endl;
        cout << "Жанр: " << movies[i].genre << endl;
        cout << "Рейтинг: " << movies[i].rating << endl;
        cout << "Цена: " << movies[i].price << " руб." << endl;
    }
}

void searchByTitle() {
    setlocale(LC_ALL, "ru");
    string title;
    bool found = false;

    cout << "\n=== Поиск по названию ===" << endl;
    cout << "Введите название для поиска: ";
    cin.ignore();
    getline(cin, title);

    for (int i = 0; i < movieCount; i++) {
        
        if (movies[i].title.find(title) != string::npos) {
            if (!found) {
                cout << "\nРезультаты поиска:" << endl;
                found = true;
            }
            cout << "\nНазвание: " << movies[i].title << endl;
            cout << "Режиссер: " << movies[i].director << endl;
            cout << "Жанр: " << movies[i].genre << endl;
            cout << "Рейтинг: " << movies[i].rating << endl;
            cout << "Цена: " << movies[i].price << " руб." << endl;
        }
    }

    if (!found) {
        cout << "Фильмы с таким названием не найдены." << endl;
    }
}

void searchByGenre() {
    setlocale(LC_ALL, "ru");
    string genre;
    bool found = false;

    cout << "\n=== Поиск по жанру ===" << endl;
    cout << "Введите жанр для поиска: ";
    cin.ignore();
    getline(cin, genre);

    for (int i = 0; i < movieCount; i++) {
        if (movies[i].genre == genre) {
            if (!found) {
                cout << "\nРезультаты поиска:" << endl;
                found = true;
            }
            cout << "\nНазвание: " << movies[i].title << endl;
            cout << "Режиссер: " << movies[i].director << endl;
            cout << "Жанр: " << movies[i].genre << endl;
            cout << "Рейтинг: " << movies[i].rating << endl;
            cout << "Цена: " << movies[i].price << " руб." << endl;
        }
    }

    if (!found) {
        cout << "Фильмы этого жанра не найдены." << endl;
    }
}

void searchByDirector() {
    setlocale(LC_ALL, "ru");
    string director;
    bool found = false;

    cout << "\n=== Поиск по режиссеру ===" << endl;
    cout << "Введите режиссера для поиска: ";
    cin.ignore();
    getline(cin, director);

    for (int i = 0; i < movieCount; i++) {
        if (movies[i].director.find(director) != string::npos) {
            if (!found) {
                cout << "\nРезультаты поиска:" << endl;
                found = true;
            }
            cout << "\nНазвание: " << movies[i].title << endl;
            cout << "Режиссер: " << movies[i].director << endl;
            cout << "Жанр: " << movies[i].genre << endl;
            cout << "Рейтинг: " << movies[i].rating << endl;
            cout << "Цена: " << movies[i].price << " руб." << endl;
        }
    }

    if (!found) {
        cout << "Фильмы этого режиссера не найдены." << endl;
    }
}

void mostPopularInGenre() {
    setlocale(LC_ALL, "ru");
    string genre;

    cout << "\n=== Самый популярный фильм в жанре ===" << endl;
    cout << "Введите жанр: ";
    cin.ignore();
    getline(cin, genre);

    double maxRating = -1;
    int bestMovieIndex = -1;

    for (int i = 0; i < movieCount; i++) {
        if (movies[i].genre == genre && movies[i].rating > maxRating) {
            maxRating = movies[i].rating;
            bestMovieIndex = i;
        }
    }

    if (bestMovieIndex != -1) {
        cout << "\nСамый популярный фильм в жанре \"" << genre << "\":" << endl;
        cout << "Название: " << movies[bestMovieIndex].title << endl;
        cout << "Режиссер: " << movies[bestMovieIndex].director << endl;
        cout << "Жанр: " << movies[bestMovieIndex].genre << endl;
        cout << "Рейтинг: " << movies[bestMovieIndex].rating << endl;
        cout << "Цена: " << movies[bestMovieIndex].price << " руб." << endl;
    }
    else {
        cout << "Фильмов в жанре \"" << genre << "\" не найдено." << endl;
    }
}

void displayMenu() {
    setlocale(LC_ALL, "ru");
    cout << "\n=== ВИДЕОМАГАЗИН ===" << endl;
    cout << "1. Показать все фильмы" << endl;
    cout << "2. Добавить фильм" << endl;
    cout << "3. Поиск по названию" << endl;
    cout << "4. Поиск по жанру" << endl;
    cout << "5. Поиск по режиссеру" << endl;
    cout << "6. Самый популярный фильм в жанре" << endl;
    cout << "7. Выход" << endl;
    cout << "Выберите действие (1-7): ";
}

void addExampleMovies() {
    setlocale(LC_ALL, "ru");
    // Фильм 1
    movies[0].title = "Криминальное чтиво";
    movies[0].director = "Квентин Тарантино";
    movies[0].genre = "Драма";
    movies[0].rating = 9.5;
    movies[0].price = 15.99;

    // Фильм 2
    movies[1].title = "Убить Билла";
    movies[1].director = "Квентин Тарантино";
    movies[1].genre = "Триллер";
    movies[1].rating = 9.8;
    movies[1].price = 19.99;

    // Фильм 3
    movies[2].title = "Темный рыцарь";
    movies[2].director = "Кристофер Нолан";
    movies[2].genre = "Боевик";
    movies[2].rating = 9.7;
    movies[2].price = 17.50;

    movieCount = 3;
}

int main() {
    setlocale(LC_ALL, "ru");
    
    addExampleMovies();

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            showAllMovies();
            break;

        case 2:
            addMovie();
            break;

        case 3:
            searchByTitle();
            break;

        case 4:
            searchByGenre();
            break;

        case 5:
            searchByDirector();
            break;

        case 6:
            mostPopularInGenre();
            break;

        case 7:
            cout << "\nДо свидания!" << endl;
            break;

        default:
            cout << "\nНеверный выбор. Попробуйте снова." << endl;
        }

    } while (choice != 7);

    return 0;
}