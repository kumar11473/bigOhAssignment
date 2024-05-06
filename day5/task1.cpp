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
    Media(){}
    Media(string s, int ms) : mediaType(s), mediaSize(ms) {}
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
    Status status;
    Contact(string name, long long cont) : Person(name, cont) {}
};

// user management
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
    Status(){}
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

    void viewStatus(Contact contact)
    {
        cout << "status type" << contact.status.media.mediaType;
        cout << "Status text" << contact.status.caption;
    }
};

class Chat
{
public:
    time_t sent_time;
    string content;
    bool sendStatus;
    bool readStatus;
    Media media;

    Chat(time_t time, string cont, bool sStatus, bool rStatus, string mMId, Media media) : sent_time(time),
                                                                                           content(cont), sendStatus(sStatus), readStatus(rStatus), media(media) {}

    Chat(string cont, time_t tm, Media media) : content(cont), sent_time(tm), media(media) {}
};

class ChatManagement
{
public:
    unordered_map<long long, vector<Chat>> chatHistory;

    // to convert time_t date and time to human readable format dd/mm/yyyy
    string time_t_to_StringFormat(time_t time)
    {
        const char *datetimeString = "2023-06-17 12:36:51";
        const char *format = "%Y-%m-%d %H:%M:%S";

        char buffer[90];
        struct tm *timeinfo = localtime(&time);
        strftime(buffer, sizeof(buffer), format, timeinfo);
        return buffer;
    }

    void showAllChat()
    { // print contacts with whoom user has ever chatted. (eg. )
        int index = 0;
        for (auto x : chatHistory)
        {
            cout << index << " " << x.first << endl;
            for (auto y : x.second)
            {
                cout << "time:" << time_t_to_StringFormat(y.sent_time);
                cout << "You: " << y.content << endl;
                cout << "status:" << y.sendStatus;
            }
            index++;
        }
    }
    // deleting all chats of a particular number
    void deleteAllChat()
    {
        int index = 0;
        for (auto x : chatHistory)
        {
            cout << index << " " << x.first << endl;
            index++;
        }

        int n = 0;
        cout << "Select contact to delete chat ";
        cin >> n;
        if (n > chatHistory.size())
        {
            cout << "Invalid entry";
            return;
        }
        for (auto it = chatHistory.begin(); it != chatHistory.end(); it++)
        {
            n--;
            if (n == 0)
            {
                chatHistory.erase(it);
                break;
            }
        }
    }

    void sendChat(Contact contact)
    {
        cout << "Enter message ";
        string content;
        cin >> content;
        time_t now = time(0);
        string s;
        cout << "Enter media type ";
        cin >> s;
        Media media(s, 30);

        Chat chat(content, now, media);

        chatHistory[contact.contactNum].push_back(chat);
    }
};

int main()
{
    Contact c1("sushant", 9876678760);
    UserManagement user1;

    return 0;
}
