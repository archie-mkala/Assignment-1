#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
public:
    string title, author, ISBN;
    bool isBorrowed;

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), isBorrowed(false) {}
};

class User {
public:
    string name;
    vector<string> borrowedBooks;

    User(string n) : name(n) {}

    void borrowBook(string ISBN) {
        borrowedBooks.push_back(ISBN);
    }

    void returnBook(string ISBN) {
        borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), ISBN), borrowedBooks.end());
    }
};

class Library {
private:
    vector<Book*> books;
    vector<User*> users;

public:
    ~Library() {
        for (auto book : books) delete book;
        for (auto user : users) delete user;
    }

    void addBook(string title, string author, string ISBN) {
        books.push_back(new Book(title, author, ISBN));
        cout << "Book added: " << title << "\n";
    }

    void removeBook(string ISBN) {
        auto it = remove_if(books.begin(), books.end(), [&](Book* b) { return b->ISBN == ISBN; });
        if (it != books.end()) {
            delete *it;
            books.erase(it, books.end());
            cout << "Book removed with ISBN: " << ISBN << "\n";
        }
    }

    void searchBook(string query) {
        for (auto book : books) {
            if (book->title == query || book->author == query || book->ISBN == query) {
                cout << "Found: " << book->title << " by " << book->author << " (" << book->ISBN << ")\n";
            }
        }
    }

    void registerUser(string name) {
        for (auto user : users) {
            if (user->name == name) {
                cout << "User " << name << " is already registered!\n";
                return;
            }
        }
        users.push_back(new User(name));
        cout << "User registered: " << name << "\n";
    }

    void borrowBook(string username, string ISBN) {
        Book* book = nullptr;
        User* user = nullptr;

        for (auto b : books) {
            if (b->ISBN == ISBN) {
                book = b;
                break;
            }
        }

        for (auto u : users) {
            if (u->name == username) {
                user = u;
                break;
            }
        }

        if (book && user && !book->isBorrowed) {
            book->isBorrowed = true;
            user->borrowBook(ISBN);
            cout << username << " borrowed " << book->title << "\n";
        } else {
            cout << "Borrowing failed! Either book not found, user not found, or already borrowed.\n";
        }
    }

    void returnBook(string username, string ISBN) {
        Book* book = nullptr;
        User* user = nullptr;

        for (auto b : books) {
            if (b->ISBN == ISBN) {
                book = b;
                break;
            }
        }

        for (auto u : users) {
            if (u->name == username) {
                user = u;
                break;
            }
        }

        if (book && user && book->isBorrowed) {
            book->isBorrowed = false;
            user->returnBook(ISBN);
            cout << username << " returned " << book->title << "\n";
        } else {
            cout << "Return failed! Either book not found, user not found, or wasn't borrowed.\n";
        }
    }
};

int main() {
    Library library;
    library.addBook("C++ Programming", "Bjarne Stroustrup", "12345");
    library.addBook("Clean Code", "Robert C. Martin", "67890");

    library.registerUser("Alice");
    library.registerUser("Bob");

    library.searchBook("C++ Programming");
    library.borrowBook("Alice", "12345");
    library.returnBook("Alice", "12345");
    library.removeBook("67890");

    return 0;
}
