

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
using namespace std;
struct Book {
    string title;      
    string author;     
    string publisher;  
    string genre;      

    
    void display() const {
        std::cout << "Name : " << title << "\n"
            << "Author : " << author << "\n"
            << "Publisher :  " << publisher << "\n"
            << "Genre: " << genre << "\n";
        cout << "----------------------\n";
    }
};


void editBook(Book& book) {
    cout << "Edit book :";
    cout << "New name : : ";
    getline(cin, book.title);
    cout << "New author: ";
    getline(cin, book.author);
    cout << "New publisher: ";
    getline(cin, book.publisher);
    cout << "New genre : ";
    getline(cin, book.genre);
}


void print(Book books[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Book" << (i + 1);
        books[i].display();
    }
}



void searchByTitle(const Book books[], int size, const string& title) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (books[i].title == title) {
            books[i].display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Book with a name  \"" << title << "\" not found\n";
    }
}


void sortByTitle(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
}


void sortByAuthor(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
}


void sortByPublisher(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.publisher < b.publisher;
        });
}

int main() {
    const int SIZE = 10;
    Book library[SIZE] = {
        {"Gary Poter", "Rouling", "Posmen", "Fantasy"},
        {"1984", "Mark TWen", "iishl", "adventures"},
        {"Three frieds", "Remark","elberg", "Roman"},
        {"Мargarita", "Bulgakow", "Press", "Mistic"},


    };


    cout << "All books in library : ";
    print(library, SIZE);



    cout << "\nSearch \"Mark Twen\":\n";
    searchByTitle(library, SIZE, "Мобі Дік");

    cout << "\nSort for name :\n";
    sortByTitle(library, SIZE);
    print(library, SIZE);

    cout << "\nSort for author :\n";
    sortByAuthor(library, SIZE);
    print(library, SIZE);

    cout << "\nSort : :\n";
    sortByPublisher(library, SIZE);
    print(library, SIZE);

    cout << "\nEdit first book:\n";
    editBook(library[0]);
    print(library, SIZE);
}