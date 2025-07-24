#include<iostream>
#include<string>
using namespace std;

class Car{
  public:
    virtual void startEngine()=0;
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine()=0;
    virtual ~Car(){}
};

class sportsCar : public Car{
  public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    sportsCar(string brand,string model){
      this->brand=brand;
      this->model=model;
      isEngineOn=false;
      currentSpeed=0;
      currentGear=0;
    }

    void startEngine(){
      isEngineOn=true;
      cout<<"Engine starts with a roar."<<endl;
      return ;
    }

    void shiftGear(int gear){
      if(!isEngineOn){
        cout<<"Engine is off! Can't shift gear."<<endl;
        return;
      }
      currentGear=gear;
      cout<<"Gear id shifted to"<<currentGear<<endl;
      return;
    }

    void accelerate(){
      if(!isEngineOn){
        cout<<"Engine is off! Can't accelarate."<<endl;
        return ;
      }
      currentSpeed+=10;
      cout<<"Accelerating"<<brand<<" "<<model <<"to "<<currentSpeed<<" km/h"<<endl;
    }

    void brake(){
      currentSpeed-=10;
      if(currentSpeed<10)currentSpeed=0;
      cout<<brand<<" "<<model<<" stopped."<<endl;
    }

    void stopEngine(){
      isEngineOn=false;
      currentSpeed=0;
      currentGear=0;
      cout<<"Engine turned off"<<endl;
    }
};

class sedan : public Car{
  
};

int main(){
  Car* mycar= new sportsCar("Dodge","Challenger");

  delete(mycar);
  return 0;
}