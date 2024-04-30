
#include <iostream>
using namespace std;
class Mp{
    // private:
       
    public:
        string constituency ;
        string driver;
        int spendingLimit;
        int expenses;
        string designation; // mp,pm,minister
        Mp(string desig,string consti,string driver,int spendingLimit){
            string designation=designation;
            constituency=consti;
            driver=driver;
            spendingLimit=spendingLimit;
            expenses=0;
        }
            
            
        string getConstituency(){
            return constituency;
        }
        int getExpenses(){
            return expenses;
        }
        
        bool exceedSpendingLimit(){
            if(expenses>spendingLimit){
                return true;
            }
            return false;
        }
        
};

class Pm:public Mp{
    // private:
    public:
        bool isPermissionToArrest;
        Pm(string desig,string consti,string driver,int spendingLimit,bool permission):
        Mp(desig,consti,driver,spendingLimit),isPermissionToArrest(permission){}
            
            // string designation=desig;
            // constituency=consti;
            // driver=driver;
            // spendingLimit=spendingLimit;
            // expenses=0;
            // isPermissionToArrest=permission;
        
};

class Minister:public Mp{
    
};

class Comissioner{
    public:
    // functioon overloading
    bool canArrest(Mp mp){
        if(mp.designation=="mp" && (mp.expenses>mp.spendingLimit)){
            return true;
        }
        else if((mp.designation=="mp" )&& (mp.expenses<mp.spendingLimit)){
            return false;
        }
        else if(mp.designation=="pm"){
            return false;
        }
    }
    bool canArrest(Pm *pm,Minister *minister){ 
        if(minister.expenses>minister.spendingLimit && (pm.isPermissionToArrest)){
            return true;
        }
        return false;
    }
};

int main()
{
    // Pm * pm1 =new Pm();
    

    return 0;
}
