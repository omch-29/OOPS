#include<iostream>
#include<vector>
using namespace std;


class bankAccount{
private:            //Encapsulation
   double balance;
   int accno;
public:
    bankAccount(int accno, double balance){
        this->accno=accno;
        this->balance=balance;
    }
    void deposit(double val){
        if(val>0) balance+=val;
    }
    virtual bool withdraw(double val){          //Abstraction
        if(val>0 && val<=balance){ balance-=val;
        return true;
        }
        return false;
    }
    double getBalance(){
        return balance;
    }
};
class savingsAccount : public bankAccount{
private:
    double minBalance;
public:
    savingsAccount(int accNo,double balance, double minBal) : bankAccount(accNo, balance), minBalance(minBal) {};
    bool withdraw(double amount) override {
        if (getBalance() - amount >= minBalance) {
            return bankAccount::withdraw(amount);
        }
        return false;
    }
};
int main(){
    bankAccount b(85, 100.20);
    int amnt;
    cout<<"enter amoun to withdraw";
    cin>>amnt;
    b.withdraw(amnt);
    cout<<b.getBalance()<<endl;
    b.deposit(100);
    cout<<b.getBalance();
}