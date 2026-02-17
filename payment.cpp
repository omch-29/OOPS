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
class CreditCardPayment : public PaymentMethod{
public:
    void pay(double amount) override{
        cout<< "paid rs"<<amount<<"using credit card"<<endl;
    }
};
