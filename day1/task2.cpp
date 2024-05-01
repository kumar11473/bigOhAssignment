
#include <bits/stdc++.h>
using namespace std;

class Grid{
    int capacity;
    string location;
    Grid(int cap,string loc){
        capacity=cap;
        location=loc;
    }
    int getCapacity(){
        return capacity;
    }
    
    string getLocation(){
        return location;
    }
    
};

class SolarPanel{
    int power; // how much power each panel generate
    int panelSize;
    int getPanelPower(){
        return power;
    }
};

class Battery{
    int capacity;
    int storedEnergy;
    
    Battery(int cap,int ene):capacity(cap),storedEnergy(ene){};
    int getCapacity(){
        return capacity;
    }
    int storedEnergy(){
        return storedEnergy;
    }
    
};



class Inverter{
    public:
        string type;
        bool isStoring;
        int current;
        int operatingVoltage;
        Inverter(string type,bool isStoring,int curr,int volt):
            type(type),isStoring(isStoring),current(curr),volt(volt){};
            
        int getPowerRating(){
             return (current*operatingVoltage);
        }
};



class Solar:public Inverter{
       public:
       
        Solar(Battery battery){
            
        }
        Solar(bool isStoring,int curr,int volt,int panelSize){  // have to tell isStoring or not
            isStoring=isStoring,
            current=curr;
            operatingVoltage=volt;
            panelSize=panelSize;
        }
    
        int getPanelSize(){
            return panelSize;
        }    
        
        void sellingCapacity(){
            if(gridOn){
                cout<<"total gridOn capacity is: "<<getPowerRating();
            }else{
                cout<<"Not a grid on";
            }
        }
};


class NonSolar:public Inverter{
    public:
        bool hasSolarPanel=false; 
        NonSolar(int curr,int volt){
            type="nonsolar";
            isStoring=true;
            hasSolarPanel=false;
            current=curr;
            operatingVoltage=volt;
        }
        
};


class PCU:public Solar{
    
};

class GTI:public Solar{
    
};


class Zelio:public NonSolar{
    
};


class Icruze:public NonSolar{
    
}

int main()
{
     Solar PCU(true,true,2,8,1);
    //  ,GTI(false,100,27,1),Regalia(true,20,2,1);
    
    //  cout<<PCU.getPowerRating()<<" watt"<<endl;
    // cout<<PCU.gridOn;
    // PCU.sellingCapacity();
    
    NonSolar Zelio(2,27),Icruze(5,30);
     cout<<Icruze.getPowerRating();
    return 0;
}
