// LIBRARY MANAGEMENT SYSTEM
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Book class
class Book {
public:
    string title;
    string author;
    string ISBN;
    int quantity;
    int available;

    Book(string t, string a, string i, int q) : title(t), author(a), ISBN(i), quantity(q), available(q) {}
};

// Member class
class Member {
public:
    string name;
    int memberID;

    Member(string n, int id) : name(n), memberID(id) {}
};

// Library class
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(string title, string author, string ISBN, int quantity) {
        books.emplace_back(title, author, ISBN, quantity);
        cout << "Book added: " << title << " (Quantity: " << quantity << ")" << endl;
    }

    void addMember(string name, int id) {
        members.emplace_back(name, id);
        cout << "Member added: " << name << endl;
    }

    void issueBook(string ISBN) {
        for (auto& book : books) {
            if (book.ISBN == ISBN) {
                if (book.available > 0) {
                    book.available--;
                    cout << "Book issued: " << book.title << endl;
                } else {
                    cout << "Book is not available" << endl;
                }
                return;
            }
        }
        cout << "Book not found" << endl;
    }

    void returnBook(string ISBN) {
        for (auto& book : books) {
            if (book.ISBN == ISBN) {
                if (book.available < book.quantity) {
                    book.available++;
                    cout << "Book returned: " << book.title << endl;
                } else {
                    cout << "All copies of the book are already available" << endl;
                }
                return;
            }
        }
        cout << "Book not found" << endl;
    }

    void viewAllBooks() {
        cout << "All Books:" << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author
                 << ", ISBN: " << book.ISBN
                 << ", Quantity: " << book.quantity
                 << ", Available: " << book.available << endl;
        }
    }

    void viewAllMembers() {
        cout << "All Members:" << endl;
        for (const auto& member : members) {
            cout << "Name: " << member.name << ", Member ID: " << member.memberID << endl;
        }
    }

    void searchBookByTitle(string title) {
        cout << "Search Results for Title '" << title << "':" << endl;
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "Title: " << book.title << ", Author: " << book.author
                     << ", ISBN: " << book.ISBN
                     << ", Quantity: " << book.quantity
                     << ", Available: " << book.available << endl;
                return;
            }
        }
        cout << "Book not found" << endl;
    }

    void searchMemberByID(int id) {
        cout << "Search Results for Member ID '" << id << "':" << endl;
        for (const auto& member : members) {
            if (member.memberID == id) {
                cout << "Name: " << member.name << ", Member ID: " << member.memberID << endl;
                return;
            }
        }
        cout << "Member not found" << endl;
    }
};


int main() {
    Library library;
    int choice;
    string title, author, ISBN;
    int memberID, quantity;

    do {
        cout << "===== Library Management System =====" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Add New Member" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. View All Books" << endl;
        cout << "6. View All Members" << endl;
        cout << "7. Search Book by Title" << endl;
        cout << "8. Search Member by ID" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left in the input buffer

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter book ISBN: ";
                getline(cin, ISBN);
                cout << "Enter book quantity: ";
                cin >> quantity;
                cin.ignore();
                library.addBook(title, author, ISBN, quantity);
                break;
            case 2:
                cout << "Enter member name: ";
                getline(cin, title);  // Reusing 'title' variable to store member name
                cout << "Enter member ID: ";
                cin >> memberID;
                cin.ignore();
                library.addMember(title, memberID);
                break;
            case 3:
                cout << "Enter book ISBN to issue: ";
                getline(cin, ISBN);
                library.issueBook(ISBN);
                break;
            case 4:
                cout << "Enter book ISBN to return: ";
                getline(cin, ISBN);
                library.returnBook(ISBN);
                break;
            case 5:
                library.viewAllBooks();
                break;
            case 6:
                library.viewAllMembers();
                break;
            case 7:
                cout << "Enter book title to search: ";
                getline(cin, title);
                library.searchBookByTitle(title);
                break;
            case 8:
                cout << "Enter member ID to search: ";
                cin >> memberID;
                cin.ignore();
                library.searchMemberByID(memberID);
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }

        cout << endl;

    } while (choice != 9);

    return 0;
}