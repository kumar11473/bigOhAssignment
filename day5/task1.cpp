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

// class Contact:public Person{
//     public:
//        //chathistory
// };

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

    void editcontact() 
    {
                    // replace old contact ojbect with new Contact obj.
        string name, pass, ans;
        long long cont;
        cout << "Enter new name ";
        cin >> name;
        cout << "Enter new contact number";
        cin >> cont;
        Contact newContact(name,cont);
        
        
        int ind=-1;
        for(int i=0;i<yourContacts.size();i++){
            if(yourContacts[i].contactNum==cont){
                yourContacts[i]=newContact;
                return;
            }
        }
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

int main()
{
    Contact c1("sushant",9876678760);
    UserManagement user1;

    return 0;
}
