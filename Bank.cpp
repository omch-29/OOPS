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
class withdrawableAcc : public Account{
public:
    withdrawableAcc(int a) : Account(a) {}

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