#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class WithdawableAcc{
public:
    int accNo;

    virtual void deposit(){
        cout<<"Money Deposited\n";
    }
    void withdraw(){
        cout<<"Money Withdrawn\n";
    }
};
class NonWithdrawableAcc : public WithdawableAcc{
public:
    int accNo;
    void deposit() override{
        cout<<"Money Deposited\n";
    }
};

class Client{
public:
    vector<WithdawableAcc*>withdrawAvailable;
    vector<NonWithdrawableAcc*>withdrawNotAvailable;
    Client(vector<WithdawableAcc*>& canWithdraw, vector<NonWithdrawableAcc*>& cantWithdraw) {
        withdrawAvailable=canWithdraw;
        withdrawNotAvailable=cantWithdraw;
    }
    void display(){
        for(auto& it : withdrawAvailable) {
            it->deposit();
        }
        
    }
};