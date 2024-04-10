#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
};

// Function to print information about a book
void printBookInfo(const Book* book) {
    std::cout << "Title: " << book->title << std::endl;
    std::cout << "Author: " << book->author << std::endl;
    std::cout << "Year: " << book->year << std::endl;
}

// Function to sort books by year
void sortByYear(Book* books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (books[j]->year > books[j + 1]->year) {
                std::swap(books[j], books[j + 1]);
            }
        }
    }
}

// Function to sort books by author
void sortByAuthor(Book* books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (books[j]->author > books[j + 1]->author) {
                std::swap(books[j], books[j + 1]);
            }
        }
    }
}

// Function to select sorting function
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
    Book* books[size] = {
            new Book{"Book1", "Author3", 2005},
            new Book{"Book2", "Author1", 1998},
            new Book{"Book3", "Author2", 2010}
    };

    // Output information about books before sorting
    std::cout << "Books before sorting:" << std::endl;
    for (const auto& book : books) {
        printBookInfo(book);
        std::cout << std::endl;
    }

    // Choose sorting method
    std::cout << "Select sorting method:" << std::endl;
    std::cout << "1. By year" << std::endl;
    std::cout << "2. By author" << std::endl;

    int choice;
    std::cin >> choice;

    // Get sorting function
    void (*sortFunc)(Book**, int) = selectSortingFunction(choice);

    if (sortFunc != nullptr) {
        // Apply selected sorting
        sortFunc(books, size);

        // Output sorted books
        std::cout << "Books after sorting:" << std::endl;
        for (const auto& book : books) {
            printBookInfo(book);
            std::cout << std::endl;
        }
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    // Free memory
    for (const auto& book : books) {
        delete book;
    }

    return 0;
}