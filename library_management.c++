#include <iostream>
using namespace std;

class Book {
public:
    string title, author, ISBN;
    bool isBorrowed;

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), isBorrowed(false) {}
};
