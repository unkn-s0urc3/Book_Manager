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

int main() {
    return 0;
}
