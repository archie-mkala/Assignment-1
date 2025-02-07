Online Library Management System - Documentation
Project Overview
This C++ Console Application is a Library Management System that allows users to:  Add and Remove Books
 Search for Books
 Register Users
 Borrow and Return Books
The project follows object-oriented programming (OOP) principles for modularity and efficiency.

Object-Oriented Approach
We follow OOP principles to ensure maintainability and scalability. The system has three main classes:
Class	Responsibility
Book	Stores book details (title, author, ISBN, availability)
User	Stores user details and borrowed books
Library	Manages books, users, borrowing, and returning
 
Data Structures Used
Data Structure	Reason
vector<Book*>	Allows dynamic addition/removal of books
vector<User*>	Stores multiple users efficiently
string	Used for book details and user names
Memory Management
•	Dynamically Allocated Objects (new Book(...), new User(...)) ensure proper memory usage.
•	Destructor (~Library) is implemented to delete allocated memory and prevent memory leaks.


