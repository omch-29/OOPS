#include<bits/stdc++.h>
using namespace std;

class Car{
protected:
    string brand;
    int engineNo;
    string model;
    bool isOn;
    int speed;
public:
    Car(string b, string m){
        brand=b;
        model=m;
        isOn=false;
        speed=0;
    }
    virtual void start(){
        if(!isOn) isOn=true;
        cout<<"Car started"<<endl;
    }
    virtual void stop(){
        cout<<"car stopped"<<endl;
        isOn=false;
    }
    virtual void accelerate(){
        if(!isOn){
            cout<<"please turn ON car"<<endl;
            return;
        }
        cout<<"speed increased by 20km/hr"<<endl;
    }
    virtual void brake(){
        cout<<"brakes applied"<<endl;
    }
};

class ManualCar : public Car{
int noOfGears;
public:
    ManualCar(string b, string m) : Car(b,m){
        noOfGears=6;
    }
    void accelerate() override{         //overriding
        if(!isOn){
            cout<<"Please turn ON car"<<endl;
            return;
        }
        cout<<"Manual Car speed increased"<<endl;
        speed+=20;
        cout<<"Speed ="<<speed<<endl;
    };
    void accelerate(int s){     //overloading
        if(!isOn){
            cout<<"Please turn ON car"<<endl;
            return;
        }
        cout<<"speed increased by "<<s<<"km/hr";
        speed+=s;
        cout<<"Speed ="<<speed<<endl;
    }
};
class EvCar : public Car{
int batteryPerc;
public:
    EvCar(string b, string m) : Car(b,m){
        batteryPerc=100;
    }
    void accelerate() override{
        if(!isOn){
            cout<<"Please turn ON car"<<endl;
            return;
        }
        cout<<"EV Car speed increased"<<endl;
        batteryPerc-=10;
        speed+=20;
        cout<<"Speed ="<<speed<<endl;
    }
    void accelerate(int s){
        if(!isOn){
            cout<<"Please turn ON car"<<endl;
            return;
        }
        batteryPerc-=(s/10);
        cout<<"speed increased by "<<s<<"km/hr";
        speed+=s;
        cout<<"Speed ="<<speed<<endl;
    }
};

int main(){
    ManualCar man1("suzuki","creta");

    man1.accelerate();
    man1.accelerate(40);
    man1.start();
    man1.accelerate();
    man1.accelerate();
    man1.accelerate();
    man1.brake();
    man1.stop();
    man1.accelerate();

    cout<<"EV car:"<<endl;
    EvCar e1("tvs","e9");
    e1.accelerate();
    e1.start();
    e1.accelerate();
    e1.accelerate();
    e1.stop();
}
