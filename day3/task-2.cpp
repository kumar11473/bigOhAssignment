#include <bits/stdc++.h>
using namespace std;

class ATM
{
public:
    vector<int> denominations;
    vector<int> notes;
    int totalMoneyInAtm = 0;
    ATM(vector<int> denoms) : denominations(denoms)
    {
        notes.resize(denoms.size(), 0);
    }

    void topUp()
    {
        int amount, sum = 0;
        cout << "Enter top up amount ";
        cin >> amount;
        for (int i = 0; i < denominations.size(); i++)
        {
            int a;
            cout << "Enter number notes of " << denominations[i] << " ";
            cin >> a;
            sum += (a * denominations[i]);
            notes[i] = a;
        }

        if (sum != amount)
        {
            cout << " Entered number of denominations and amount doesn't matches" << endl;
            cout << "Top up failed." << endl;
            return;
        }
        cout << "Top Up Successfull!" << endl;
        totalMoneyInAtm += amount;
    }

    void withdraw(int amount)
    {
        if (amount % denominations[denominations.size() - 1] != 0)
        {
            cout << "please enter amount in multiples of " << denominations[denominations.size() - 1] << std::endl;
            return;
        }

        for (int i = 0; i < denominations.size(); i++)
        {
            int numNotes = min(amount / denominations[i], notes[i]);
            notes[i] -= numNotes;
            amount -= numNotes * denominations[i];
        }

        if (amount == 0)
        {
            cout << "Transcation successfull!" << endl;
        }
        else if (amount < totalMoneyInAtm)
        {
            cout << "increase withdrawal amount to multiple of higher denomination of ";
            for (int i = 0; i < denominations.size(); i++)
            {
                cout << denominations[i] << " ";
            }
        }
        else
        {
            cout << "ATM is low in cash" << endl;
        }
    }

    void updateDenominations(vector<int> newDenoms)
    {
        denominations = newDenoms;
        notes.resize(denominations.size(), 0);
    }
};

int main()
{
    vector<int> denominations = {2000, 500, 200, 100};
    ATM myATM(denominations);

    myATM.topUp();

    myATM.withdraw(2300);

    // changing our denomination
    // vector<int> newDenominations = {5000, 2000, 500, 200, 100};
    // myATM.updateDenominations(newDenominations);

    // // Withdraw cash after demonetization
    // myATM.withdraw(2500);

    return 0;
}