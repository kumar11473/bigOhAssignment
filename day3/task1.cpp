
#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> dedication; // mapping userId and how many people decidated him/her
unordered_map<int ,Person> users;



class Person{
  public:
    string name;
    string role;
    string userId;
};

class Admin:public Person{
    public:
    	string authlevel;
    	Admin(string name, string role, string userId):name(name),role(role),userId(userId),authlevel(authlevel){}
};

class User:public Person{
    public:
        int brickReceived;
        User(string name, string role, string userId):name(name),role(role),userId(userId),brickReceived(0);
        
        
        void dedicate(User user){  // one brick can be dedicated to multiple user
            dedication[user.userId]++;
            
        }
        
        
        
};



class Brick{
    vector<<string,vector<string>> comments; // a single user can have multiple comments
    public:
        string caption;
        string ownerId;
        bool isFlagged;
        bool isVisible=true;
        
    void doComment(Brick brick,string comm){
        comments.push_back(comm);
    }
    
    void animate(User user,Brick brick){
        if(user.userId==brick.ownerId){
            cout<<"brick is animating";
        }
        else{
            cout<<"user is not an owner of brick";
        }
    }
    
    void flagIt( ){
    	isVisible=true;
    }
    
    
    
};
int main()
{
    
    
    return 0;
}
