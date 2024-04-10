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

void (*selectSortingFunction(int choice))(Book**, int) {
    if (choice == 1)
        return sortByYear;
    else if (choice == 2)
        return sortByAuthor;
    else
        return nullptr;
}

int main() {
    const int size = 3;
    Book* books[size];

    books[0] = new Book{"Book1", "Author3", 2005};
    books[1] = new Book{"Book2", "Author1", 1998};
    books[2] = new Book{"Book3", "Author2", 2010};

    std::cout << "Книги до сортировки:" << std::endl;
    for (int i = 0; i < size; ++i) {
        printBookInfo(books[i]);
        std::cout << std::endl;
    }

    std::cout << "Выберите метод сортировки:" << std::endl;
    std::cout << "1. По году издания" << std::endl;
    std::cout << "2. По автору" << std::endl;

    int choice;
    std::cin >> choice;

    void (*sortFunc)(Book**, int) = selectSortingFunction(choice);

    if (sortFunc != nullptr) {
        sortFunc(books, size);

        std::cout << "Книги после сортировки:" << std::endl;
        for (int i = 0; i < size; ++i) {
            printBookInfo(books[i]);
            std::cout << std::endl;
        }
    } else {
        std::cout << "Неправильный выбор." << std::endl;
    }

    for (int i = 0; i < size; ++i) {
        delete books[i];
    }

    return 0;
}