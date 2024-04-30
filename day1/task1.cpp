#include<bits/stdc++.h>
using namespace std;

class Person{
	public:
	    int age;
	    string name;
	    Person(int a,string n){
	        age=a;
	        name=n;
	    }
	    string getName(){
	     return name;
    	}
	    int getAge(){
	       return age;
	    }
};


class Driver:public Person{
    
    public:
        
        Driver(int age,string name): Person(age,name){}
    string getDriver(){
        return name;
    }
    
};

class Mp:public Person{
    public:
        string constituency;
        int spendingLimit;
        int expenses;
        Mp(int age,string name,string consti,int slimit):Person(age,name),
        constituency(consti),spendingLimit(slimit),expenses(0){}
        
        string getConstituency(){
            return constituency;
        }
        int getSpendingLimit(){
            return spendingLimit;
        }
        
        void spendMoney(int money){
            expenses+=money;
        }
};


class Minister:public Mp{
    public:
        string ministry;
        Minister(int age,string name,string consti,int slimit,string ministry):
            Mp(age,name,consti,slimit),ministry(ministry){}
};

class Pm:public Minister{
    public:
        bool havePlane=true;
        bool isPermissionToArrest;
        
        Pm(int age,string name,string consti,int slimit,string ministry,bool permissionToArrest):
            Minister(age,name,consti,slimit,ministry),isPermissionToArrest(permissionToArrest){}
            
        string getMinistry(){
            return ministry;
        }    
};

class Commissioner:public Person{
    public:
        
    // functioon overloading
    Commissioner(int age,string name):Person(age,name){}
    bool canArrest(Mp mp){
        if((mp.expenses>mp.spendingLimit)){
            return true;
        }
        else if( mp.expenses<=mp.spendingLimit){
            return false;
        }
        
    }
    bool canArrest(Pm &pm){
        return false;
    }
    bool canArrest(Pm pm,Minister minister){ 
        if(minister.expenses>minister.spendingLimit && (pm.isPermissionToArrest)){
            return true;
        }
        return false;
    }
};


int main(){
    Person p(24,"john");
    //  Driver d(12,"jack");
    Minister nitin(55,"nitin gadkari","surat",100000,"Highway");
    nitin.spendMoney(200000);
    Pm  modi(60,"narendra","varanasi",100000000,"prime",true);
    Commissioner dsp(35,"chulbul pandey");
    if(dsp.canArrest(modi,nitin)){
        cout<<"minister Arrested";
    }
    else{
        cout<<"can't arrest";
    }
    return 0;
}
