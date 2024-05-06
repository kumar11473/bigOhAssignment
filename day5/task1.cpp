#include <bits/stdc++.h>

using namespace std;

class Person
{
public:
    string name;
    long long contactNum;
    string about = "";

    Person(string name, long long cont, string about) : name(name), contactNum(cont), about(about) {}

    Person(string name, long long cont) : name(name), contactNum(cont) {}
};

class Media
{
public:
    string mediaType;
    int mediaSize;
};

class User : public Person
{
public:
    // vector<Contact> contactList;
    string password;
};

class Contact : public Person
{
public:
    Contact(string name, long long cont) : Person(name, cont) {}
};

class UserManagement
{
public:
    vector<Contact> yourContacts;
    unordered_map<string, pair<string, string>> db; // <contactNum,<name,password>>
    bool isLoggedIn = false;

    void singUp()
    {

        string nm, cont, pass;
        cout << "Enter Contact Number ";
        cin >> cont;
        cout << "Enter full name";
        cin >> nm;
        cout << "Enter password";
        cin >> pass;

        if (db.find(cont) != db.end())
        {
            cout << "Contact Number already registered" << endl
                 << "Please Login " << endl;
            return;
        }
        db[cont] = {nm, pass};
    }
    void logIn(string cont, string pass)
    {

        if (db.find(cont) == db.end())
        {
            cout << "Invalid phone number ";
            return;
        }
        if (db[cont].second == pass)
        {
            isLoggedIn = true;
            cout << "Logged In successfully" << endl;
        }
    }

    void AddContact(Contact contact)
    {
        yourContacts.push_back(contact);
    }

    void removeContact(Contact contact)
    {
        int ind = -1;
        for (int i = 0; i < yourContacts.size(); i++)
        {
            if (yourContacts[i].contactNum == contact.contactNum)
            {
                ind = i;
                break;
            }
        }

        if (ind != -1)
        {

            vector<Contact>::iterator it;
            it = yourContacts.begin() + ind;
            yourContacts.erase(it);
            cout << "Contact removed";
        }
    }

    void editcontact(Contact contact)
    {
        // replace old contact ojbect with new Contact obj.

        int ind = -1;
        for (int i = 0; i < yourContacts.size(); i++)
        {
            if (yourContacts[i].contactNum == contact.contactNum)
            {
                ind = i;
                return;
            }
        }
        string name, ans;
        long long cont;
        cout << "Enter new name ";
        cin >> name;
        cout << "Enter new contact number";
        cin >> cont;
        Contact newContact(name, cont);
        yourContacts[ind] = newContact;
    }
};

class Status
{
public:
    string statusId; // because status can be multiple and if we want to remove a particular status we will use statusId
    string caption;
    Media media;
    int viewCount;
};

class StatusManagement
{
public:
    vector<Status> uploadedStatus;
    void addStatus(Status status)
    {
        uploadedStatus.push_back(status);
    }
    void removeStatus(Status status, string statusId)
    {
        int ind = -1;
        for (int i = 0; i < uploadedStatus.size(); i++)
        {
            if (uploadedStatus[i].statusId == statusId)
            {
                ind = i;
                break;
            }
        }
        if (ind != -1)
        {
            vector<Status>::iterator it;
            it = uploadedStatus.begin() + ind;
            uploadedStatus.erase(it);
            cout << "status removed";
        }
    }

    void viewStatus(Contact contact, Status status)
    {
    }
};

class Chat
{
public:
    time_t sent_time;
    string content;
    bool sendStatus;
    bool readStatus;
    string multiMediaId = "";

    Chat(time_t time, string cont, bool sStatus, bool rStatus, string mMId) : sent_time(time),
                                                                              content(cont), sendStatus(sStatus), readStatus(rStatus), multiMediaId(mMId) {}
};

class Chat
{
public:
    string content;
    time_t sentTime;
    bool sendStatus;
    bool readStatus;
};

class ChatManagement
{
public:
    unordered_map<long long, vector<Chat>> chatHistory;

    void showAllChat()
    { // print contacts with whoom user has ever chatted. (eg. )
    }
};

int main()
{
    Contact c1("sushant", 9876678760);
    UserManagement user1;

    return 0;
}
