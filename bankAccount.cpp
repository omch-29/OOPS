#include<iostream>
#include<vector>
using namespace std;


class bankAccount{
private:
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
    bool withdraw(double val){
        if(val>0 && val<=balance){ balance-=val;
        return true;
        }
        return false;
    }
    double getBalance(){
        return balance;
    }
};

int main(){
    bankAccount b(85, 100.20);
    int amnt;
    cout<<"enter amoun to withdraw";
    cin>>amnt;
    b.withdraw(amnt);
    cout<<b.getBalance();
}