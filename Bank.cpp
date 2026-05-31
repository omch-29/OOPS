#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Account{
protected:
    int acc;
public:
    Account(int a) : acc(a) {}
    virtual void deposit()=0;
    virtual ~Account()=default;
};
class WithdrawableAcc : public Account{
public:
    WithdrawableAcc(int a) : Account(a) {}

    void deposit() override{
        cout<<"Money deposited in"<<acc<<endl;
    }
    void withdraw(){
        cout<<"Money Withdrawn from:"<<acc<<endl;
    }
};
class NonWithdrawableAcc :public Account{
public:
    NonWithdrawableAcc(int a) : Account(a) {}

    void deposit() override{
        cout<<"Money Deposited to:"<<acc<<endl;
    }
};
class Client{
    vector<WithdrawableAcc*> withdrawAvailable;
    vector<NonWithdrawableAcc*> withdrawNotAvailable;
public:
    Client(
        const vector<WithdrawableAcc*>& canWithdraw,
        const vector<NonWithdrawableAcc*>& cantWithdraw
    ) {
        withdrawAvailable = canWithdraw;
        withdrawNotAvailable = cantWithdraw;
    }
    void display(){
        cout << "\nWithdrawable Accounts:\n";
        for (auto acc : withdrawAvailable){
            acc->deposit();
            acc->withdraw();
        }
        cout << "\nNon-Withdrawable Accounts:\n";
        for (auto acc : withdrawNotAvailable)
        acc->deposit();
    }
};

int main(){
    WithdrawableAcc w1(10);
    WithdrawableAcc w2(20);
    NonWithdrawableAcc nw1(30);
    NonWithdrawableAcc nw2(40);

    vector<WithdrawableAcc*> can={&w1, &w2};
    vector<NonWithdrawableAcc*> cant={&nw1, &nw2};

    Client client(can, cant);
    client.display();


}