#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int age;
    string address;
    Person(string name, int age, string address) : name(name), age(age), address(address) {}

    void getName()
    {
        cout << name;
    }
    void getAge()
    {
        cout << age;
    }
    void getAddress()
    {
        cout << address;
    }
};

class Librarian : public Person
{

public:
};

class Book
{
public:
    string title;
    string author;
    string subjectCategory;
    string publicationDate;
    int rackNumber;
    string uniqueId;

    Book(string title, string author, string subCat, string publicationDate, int rackNumber, string uniqueId)
        : title(title), author(author), subjectCategory(subCat), publicationDate(publicationDate), rackNumber(rackNumber), uniqueId(uniqueId) {}

    void getTitle()
    {
        cout << title;
    }
    void getAuthor()
    {
        cout << author;
    }
    void getSubjectCategory()
    {
        cout << subjectCategory;
    }
    void getPublicationDate()
    {
        cout << publicationDate;
    }
    void getRackNumber()
    {
        cout << rackNumber;
    }
    void getUniqueId()
    {
        cout << uniqueId;
    }
};

class BookItem : public Book
{
public:
    bool isReserved;
    bool isCheckedOut;
    time_t dueDate;
    BookItem(string title, string author, string subjectCategory, string publicationDate, int rackNumber, string uniqueId)
        : Book(title, author, subjectCategory, publicationDate, rackNumber, uniqueId)
    {
        isReserved = false;
        isCheckedOut = false;
        dueDate = 0;
    }

    void getIsReserved()
    {
        cout << isReserved;
    }
    void getIsCheckedOut()
    {
        cout << isCheckedOut;
    }
    time_t getDueDate()
    {
        cout << dueDate;
    }

    void setIsReserved(bool reserved)
    {
        isReserved = reserved;
    }
    void setIsCheckedOut(bool checkedOut)
    {
        isCheckedOut = checkedOut;
    }
    void setDueDate(time_t _dueDate)
    {
        dueDate = _dueDate;
    }
};

class Member : public Person
{
public:
    string memberId;
    vector<BookItem> checkedOutBooks;
    Member(string memberId, string name, int age, string address) : Person(name, age, address), memberId(memberId) {}

    void getMemberId()
    {
        cout << memberId;
    }
    vector<BookItem> getCheckedOutBooks()
    {
        return checkedOutBooks;
    }

    void checkoutBook(BookItem bookItem)
    {

        if (checkedOutBooks.size() == 5)
        {
            cout << " can't checkout more than 5 books" << endl;
            return;
        }
        checkedOutBooks.push_back(bookItem);
        bookItem.setIsCheckedOut(true);

        time_t now = time(0);
        bookItem.setDueDate(now + (10 * 24 * 60 * 60)); // 10 days in seconds
    }

    void returnBook(BookItem bookItem)
    {
        for (auto it = checkedOutBooks.begin(); it != checkedOutBooks.end(); it++)
        {
            if (*it == bookItem)
            {
                checkedOutBooks.erase(it);
                bookItem.setIsCheckedOut(false);

                fineCalc(bookItem);

                bookItem.setDueDate(0);
                break;
            }
        }
    }

    int fineCalc(BookItem bookItem)
    {
        time_t now = time(0);
        // calculation of fine
        int dur = now - bookItem.dueDate;
        int fine = 0;
        if (dur > 0)
            fine = (dur / 3600) * 10; // (2days * rs 10 per day)

        return fine;
    }
    // total fine of a member by adding all the fine of checkedout books
    int totalFineByTheMember(Member member)
    {
        int total = 0;
        for (auto bookItem : member.checkedOutBooks)
        {
            total += fineCalc(bookItem);
        }

        return total;
    }

    void renewBook(BookItem bookItem)
    {
        time_t now = time(0);
        bookItem.setDueDate(now + (10 * 24 * 60 * 60)); // just adding 10 more days to the dueDate
    }
};

class LibrarySystem
{
public:
    vector<BookItem> books;
    vector<Member> members;
    void addBook(BookItem bookItem)
    {
        books.push_back(bookItem);
    }

    void removebook(BookItem bookItem)
    {

        for (auto it = books.begin(); it != books.end(); it++)
        {
            if (it == bookItem)
            {
                books.erase(it);
            }
        }
    }

    void addMember(Member member)
    {
        members.push_back(member);
    }

    vector<BookItem> result = {};

    // searching of books using different parameter
    vector<BookItem> search()
    {
        cout << "select option ";
        cout << "press 1 to search by title " << endl
             << "press 2 to search by author " << endl
             << "press 3 to search by subject category" << endl
             << "press 4 to search by publication date ";
        int n;
        cin >> n;
        string name;
        switch (n)
        {
        case 1:
            cout << "Enter book name";

            cin >> name;
            for (auto &bookItem : books)
            {
                if (bookItem.title == name)
                {
                    result.push_back(bookItem);
                }
            }
            break;
        case 2:
            cout << "Enter author name";
            // print all author name below

            cin >> name;
            for (auto &bookItem : books)
            {
                if (bookItem.title == name)
                {
                    result.push_back(bookItem);
                }
            }
            break;
        case 3:
            cout << "Enter subject Category ";

            cin >> name;
            for (auto &bookItem : books)
            {
                if (bookItem.subjectCategory == name)
                {
                    result.push_back(bookItem);
                }
            }
            break;
        case 4:
            cout << "Enter publication Date ";

            cin >> name;
            for (auto &bookItem : books)
            {
                if (bookItem.publicationDate == name)
                {
                    result.push_back(bookItem);
                }
            }
            break;
        default:
            cout << "Please selct correct option" << endl;
            break;
        }
        return result;
    }

    // The system should be able to send notifications whenever the
    // reserved books become available, as well as when the book
    // is not returned within the due date.

    // ask how to implement this
};

int main()
{

    return 0;
}
