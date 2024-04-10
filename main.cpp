#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
};

void printBookInfo(Book* book) {
    std::cout << "Title: " << book->title << std::endl;
    std::cout << "Author: " << book->author << std::endl;
    std::cout << "Year: " << book->year << std::endl;
}

void sortByYear(Book* books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (books[j]->year > books[j + 1]->year) {
                Book* temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void sortByAuthor(Book* books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (books[j]->author > books[j + 1]->author) {
                Book* temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int main() {
    return 0;
}
