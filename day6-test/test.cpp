#include <bits/stdc++.h>
using namespace std;
 unordered_map<long long, pair<string, string>> db; // <contactNum,<name,password>>
unordered_map<string,Hotel> approvedHotels;  // <agentId,hotel>

class User
{
public:
    string name;
    long long num;
    string pass;
    User(string name, long long num, string pass) : name(name), num(num), pass(pass) {}
};

class Normaluser:public User{
    public:
        string userId;
        Normaluser(string name,long long num,string pass,string userid):User(name,num,pass),userId(userid){}
};

class NormalUserManagement{
    public:
        unordered_map<long long,vector<Hotel>> cart;
        // NormalUser(string name, long long num, string pass): User(name,num,pass){}
    NormalUserManagement(){}
    void signUp(User* user)
    {
        string nm, pass;
        long long cont;
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
    void logIn(long long cont, string pass)
    {
        if (db.find(cont) == db.end())
        {
            cout << "Invalid phone number ";
            return;
        }
        if (db[cont].second == pass)
        {
            // isLoggedIn = true;
            cout << "Logged In successfully" << endl;
        }
    }

    void changeProfile(User* user){

        cout<<"1. change Password"<<endl<<"2. change Name"<<endl<<"3. change number"<<endl;
        int option; cin>>option;
        string str;
        switch (option){

            case 1:
                cout<<"Enter old password ";cin>>str;
                if(str==user->pass){
                    user->pass =str;
                }
            break;
            case 2:
                cout<<"Enter new name ";cin>>str;
                user->name =str;
            case 3:
                cout<<"Enter password first";cin>>str;
                if(str==user->pass){
                    cout<<"Enter new number ";
                    long long numb;
                    cin>>numb;
                    user->num=numb;

                    cout<<"Number changed successfully"<<endl;
                }
                else{
                    cout<<"wrong password"<<endl;
                }

            default:
                break;
        }
    }


};

class HotelAgent:User{
    public:
        string agentId;
        HotelAgent(string name, long long num, string pass,string id): User(name,num,pass),agentId(id){}
};

class HotelAgentManagement{
    public: 
    unordered_map<string,HotelAgent> agentList; // <agentId,hotelagent>

    unordered_map<string,pair<string,Room>> bookingDetail; // <roomId,<userId,room>
    void signUp(HotelAgent * agent){
            agentList[agent->agentId]=*agent;
    }

    void showHotelOfAgent(HotelAgent agent){

        for(auto &it:approvedHotels){
            if(it.first==agent.agentId){
                cout<<"hotel name :"<<it.second.hotelName<<endl;
                cout<<"hotel Location :"<<it.second.location<<endl;
                cout<<"Rating : "<<it.second.rating<<endl;
                cout<< "---------------------------"<<endl;
            }
        }
    }
};

class Admin{   
    public:
    string adminId;
    string auth; // basic, all, moderate

};

// class AdminManagement{
//     public:
//         void approveHotel(HotelAgent* agent,Hotel* hotel, unordered_map<string,unordered_map<string,vector<Room>>> property_added_by_agent){

//             /// your logic for approval
//             approvedHotels[agent->agentId]=hotel;
//             property_added_by_agent[agent->agentId].erase(hotel->hotelId); // removing approved hotel 


//         }

//         void deleteHotel(HotelAgent* agent,Hotel* hotel){
//             approvedHotels[agent->agentId].erase(hotel->hotelId);
//         }
//         void deleteUser(User * user){
//             db.erase(user->num);
//         }
// };

class Room
{
public:
    int roomNum;
    string type;     // single,double , triple
    string category; // deluxe, premium,
    bool isBooked;
    int count; // how many such room exist
    int price;
    

    Room(int rn, string ty, string cat, bool isB, int cnt) : roomNum(rn), type(ty), category(cat), isBooked(isB), count(cnt) {}

    bool getIsBooked()
    {
        return isBooked;
    }
    string getRoomType()
    {
        return type;
    }

    string getCategory()
    {
        return category;
    }

};

class RoomManagement{
    public:
       void changeBookingStatus(Room* room){
            room->isBooked=true;
       } 

       void changePrice(Room* room){
            int p;
            cout<<"Enter new Price "<<endl;
            room->price=p;
       } 

       void changeCnt(Room * room){
            int n;
            cout<<"enter count ";
            cin>>n;
            room->count=n;
       }

       

       
};

class Hotel
{
public:
    string hotelId;
    string hotelName;
    string location;
    double rating;

    vector<vector<string>> previewList;  //  vector of [userId,rating,string review]

    Hotel(string hotelId,string hotelName,string location):hotelId(hotelId),hotelName(hotelName),location(location){}

    string getHotelId(){
        return hotelId;
    }
    string getHotelName(){
        return hotelName;
    }

    string getLoacation(){
        return location;
    }
};

class HotelManagement{
    public:
        unordered_map<string,unordered_map<string,vector<Room>>> property_added_by_agent; // <agentId,<hotelId,vector<room>> //single agent may have multiple hotels
        

        // before call this function check admin access in the system class
        void addHotel(Hotel* hotel,HotelAgent* hotelagent,Room room){
            unordered_map<string,vector<Room>> temp;
            temp[hotel->hotelId].push_back(room);
            property_added_by_agent[hotelagent->agentId]= temp;
        }
        




};

class System{
    public:
        
        System(){};

        void bookRoom(Hotel* hotel,Room * room,int cnt){
            Normaluser * user1 = new Normaluser("john",8765987654,"john@123","123");
            NormalUserManagement * usermgnt = new NormalUserManagement();
            usermgnt->signUp(user1);


        }

         void writeReview(Normaluser user, Hotel * hotel){
            string rev;
            double rati;
            cout<<"Enter rating ";cin>>rati;
            cout<<"Enter review ";cin>>rev;
            (*hotel).previewList.push_back({user.userId,rati,rev});
        }

            // I associated booking details with the user
        void showBookedList(Normaluser * user){

        }

        void showHotels(User*user,Hotel* hotel){

        }
};

int main()
{

    return 0;
}