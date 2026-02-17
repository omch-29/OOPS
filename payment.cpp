#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<map>
using namespace std;

class PaymentMethod{
public:
    virtual void pay(double amount)=0;

    virtual ~PaymentMethod(){}
};
