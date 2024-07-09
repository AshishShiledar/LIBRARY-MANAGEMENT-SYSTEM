 #include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;


class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    
    LibraryItem(const string& t, const string& a, const string& d) {
        title = t;
        author = a;
        dueDate = d;
    }

    
    virtual ~LibraryItem() {}

    
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    void setTitle(const string& newTitle) { title = newTitle; }
    void setAuthor(const string& newAuthor) { author = newAuthor; }
    void setDueDate(const string& newDueDate) { dueDate = newDueDate; }

    
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};


class Book : public LibraryItem {
public:
    Book(const string& t = "", const string& a = "", const string& d = "")
        : LibraryItem(t, a, d) {}

    void checkOut() override {
        cout << "Checking out book: " << getTitle() << endl;
    }

    void returnItem() override {
        cout << "Returning book: " << getTitle() << endl;
    }

    void displayDetails() const override {
        cout << "Book Title: " << getTitle() << ", Author: " << getAuthor() << ", Due Date: " << getDueDate() << endl;
    }
};


class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(const string& t = "", const string& a = "", const string& d = "", int dur = 0)
        : LibraryItem(t, a, d), duration(dur) {}

    void checkOut() override {
        cout << "Checking out DVD: " << getTitle() << endl;
    }

    void returnItem() override {
        cout << "Returning DVD: " << getTitle() << endl;
    }

    void displayDetails() const override {
        cout << "DVD Title: " << getTitle() << ", Director: " << getAuthor() << ", Due Date: " << getDueDate() << ", Duration: " << duration << " minutes" << endl;
    }
};


class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(const string& t = "", const string& a = "", const string& d = "", int issueNum = 0)
        : LibraryItem(t, a, d), issueNumber(issueNum) {}

    void checkOut() override {
        cout << "Checking out magazine: " << getTitle() << endl;
    }

    void returnItem() override {
        cout << "Returning magazine: " << getTitle() << endl;
    }

    void displayDetails() const override {
        cout << "Magazine Title: " << getTitle() << ", Author: " << getAuthor() << ", Due Date: " << getDueDate() << ", Issue Number: " << issueNumber << endl;
    }
};


void displayMenu() {
    cout << "Library Management System" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Add DVD" << endl;
    cout << "3. Add Magazine" << endl;
    cout << "4. Display All Items" << endl;
    cout << "5. Check Out Item" << endl;
    cout << "6. Return Item" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}


int main() {
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 7) break;

        string title, author, dueDate;
        switch (choice) {
            case 1:
                if (itemCount < MAX_ITEMS) {
                    cout << "Enter Book Title: ";
                    cin >> title;
                    cout << "Enter Author: ";
                    cin >> author;
                    cout << "Enter Due Date: ";
                    cin >> dueDate;
                    libraryItems[itemCount++] = new Book(title, author, dueDate);
                } else {
                    cerr << "Library is full!" << endl;
                }
                break;
            case 2:
                if (itemCount < MAX_ITEMS) {
                    int duration;
                    cout << "Enter DVD Title: ";
                    cin >> title;
                    cout << "Enter Director: ";
                    cin >> author;
                    cout << "Enter Due Date: ";
                    cin >> dueDate;
                    cout << "Enter Duration (minutes): ";
                    cin >> duration;
                    libraryItems[itemCount++] = new DVD(title, author, dueDate, duration);
                } else {
                    cerr << "Library is full!" << endl;
                }
                break;
            case 3:
                if (itemCount < MAX_ITEMS) {
                    int issueNumber;
                    cout << "Enter Magazine Title: ";
                    cin >> title;
                    cout << "Enter Author: ";
                    cin >> author;
                    cout << "Enter Due Date: ";
                    cin >> dueDate;
                    cout << "Enter Issue Number: ";
                    cin >> issueNumber;
                    libraryItems[itemCount++] = new Magazine(title, author, dueDate, issueNumber);
                } else {
                    cerr << "Library is full!" << endl;
                }
                break;
            case 4:
                for (int i = 0; i < itemCount; ++i) {
                    libraryItems[i]->displayDetails();
                }
                break;
            case 5:
                cout << "Enter the index of the item to check out: ";
                int index;
                cin >> index;
                if (index >= 0 && index < itemCount) {
                    libraryItems[index]->checkOut();
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;
            case 6:
                cout << "Enter the index of the item to return: ";
                cin >> index;
                if (index >= 0 && index < itemCount) {
                    libraryItems[index]->returnItem();
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

 
    return 0;
}
