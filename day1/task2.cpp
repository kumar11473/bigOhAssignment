
#include <bits/stdc++.h>
using namespace std;

// class Grid{
//     int sellBack;
    
// }
vector<string> v={"PCU","GTI","Regalia"};

class Inverter{
    public:
        
        string type;
        bool isStoring;
        int current;
        int operatingVoltage;
        
        int getPowerRating(){
             return (current*operatingVoltage);
        }
};



class Solar:public Inverter{
       public:
        int panelSize;
        bool gridOn;
        Solar(bool gn, bool isStoring,int curr,int volt,int panelSize){  // have to tell isStoring or not
            
            if(!isStoring) 
                gridOn=false;
            else
                gridOn=gn;
                
                
            type="solar";
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
int main()
{
	int n;cin>>n;
     Solar PCU(true,true,2,8,1);
    //  ,GTI(false,100,27,1),Regalia(true,20,2,1);
    
    //  cout<<PCU.getPowerRating()<<" watt"<<endl;
    // cout<<PCU.gridOn;
    // PCU.sellingCapacity();
    
    NonSolar Zelio(2,27),Icruze(5,30);
     cout<<Icruze.getPowerRating();
    return 0;
}
