
#include <bits/stdc++.h>
using namespace std;

class Floor{
    public:
    // Compact, Large, Handicapped, Motorcycle
    int floorLevel,totalCompact, totalLarge, totalHandicapped, totalMotorcycle;
    
    Floor(int fl,int tc,int tl,int th,int tm){
        floorLevel=fl;
        totalCompact=tc;
        totalLarge=tl;
        totalHandicapped=th;
        totalMotorcycle=tm;
    }

};

class Person{
    public:
    int age;
    string name;
    Person(int age,string name){
        age=age;
        name=name;
       
    }
    
    
    int getAge(){
        return age;    
    }
    string getName(){
        return name;
    }
  
};

class Attendents:public Person{
    public:
        vector<Person> AttendentList;

        
};

class Vehicle{
    public:
    string vehicleNumber;
    string vehicleType;
    Vehicle(string vn,string vt){
        vehicleNumber=vn;
        vehicleType=vt;
    }
    string getVehicleNumber(){
        return vehicleNumber;
    }
    
    string getVehicleType(){
        return vehicleType;
    }
};

class Ticket{
    public:
    // ticket price exit k time decide hoga
    int spot_Floor;
    string vehicleNumber;
    string vehicleType;
    
    Ticket(int fn, string vn,string vt){
        spot_Floor=fn;
        vehicleNumber=vn;
        vehicleType=vt;
    }
};

class ParkingLot{
    public:
    // have multiple floors ,multiple entry and exit
        int floors;
        vector<Floor> floorList;
        
        // void addFloor(Floor &f){  // it will be done inside admin class
        //     floorList.push_back(f);
        // }
        
};

class System{
    public:
    // System class, vehicle object as a argument lega and ticket ojbect genrate karega! 
    System(){
        
    }
    
    Ticket genrateTicket(Vehicle &vehicle){
        Ticket  ticket1(1,"JH9C1234","Bike");
        return ticket1;
    }
};



class Admin:public Person{   // all correct
    
    public:
        // ParkingLot parking_lot; // aggregation
        // once you create a constructor explicity , default constructor got vanished
        Admin(int age,string name):Person(age,name){}
        // Admin(ParkingLot &pl){
        //     parking_lot=pl;
        // }
        
        void addFloors(ParkingLot &pl,Floor &f){ // working correclty (association)
            pl.floorList.push_back(f);
        }
        void removeFloors(ParkingLot &pl,int level){
            // pl.floors-=num;
            // remove a whole floor class from the floorList using floorLevel value
            int ind=-1;
            for(int i=0;i<pl.floorList.size();i++){
                if(pl.floorList[i].floorLevel==level){
                    ind=i;
                    break;
                }
            }
                vector<Floor> :: iterator it=pl.floorList.begin()+ind;
                pl.floorList.erase(it);
                
            
        }
        
                // adding Attendents by admin
        void addAttendent(Attendents attendent){
            cout<<"Enter Number of Attendents you want to add ";
            int n;cin>>n;
            for(int i=0;i<n;i++){
                int age;
                string name;
                cout<<"Enter name ";
                cin>>name;
                cout<<"Enter age ";
                cin>>age;
                Person p(age,name);              //composition?
                attendent.AttendentList.push_back(p);
            }
        
        }
        
                 // removing Attendent if found 
        void removeAttendents(Attendents attendent){
            cout<<"Enter name";
            string name; cin>>name;
            int ind=-1;
            for(int i=0;i<attendent.AttendentList.size();i++){
                if(attendent.AttendentList[i].name==name){
                    ind=i;
                    break;
                }
            }
            
            if(ind==-1){
                cout<<"NO such attendent found"<<endl;
            }else{
                vector<Person> :: iterator it; 
                it=attendent.AttendentList.begin()+ind;
                attendent.AttendentList.erase(it);
                cout<<"attendent Removed"<<endl;
            }
        }
};                 


int main()
{
    int n;cin>>n;
    // create floor
    Floor f1(1,3,4,6,9), f2(2,7,9,12,3);
    // cout<<f1.floorLevel;
        // create ParkingLot
    ParkingLot pl;
    
    
    Admin admin1(25,"john");
    admin1.addFloors(pl,f1);
    admin1.addFloors(pl,f2);
    cout<<pl.floorList.size()<<endl; // working correctly
    
    admin1.removeFloors(pl,1);
    cout<<pl.floorList.size()<<endl;   // working correctly!
    
    
    
    
    Vehicle vehicle1("JH9C8765","car");
    System system1;
    Ticket t1 = system1.genrateTicket(vehicle1);
    cout<<t1.vehicleNumber<<" "<<t1.vehicleType<<endl;
    

    return 0;
}
