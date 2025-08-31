#include<iostream>
#include<string>
using namespace std;

class Burger{
  public:
  virtual void prepare()=0;
  virtual ~Burger(){};
};

class basicBurger : public Burger{
  public:
  void prepare() override{
    cout<<"Preparing basic burger w/o wheat."<<endl;
  }
};

class standardBurger : public Burger{
  public:
  void prepare() override{
    cout<<"Preparing standard burger w/o wheat."<<endl;
  }
};

class gourmetBurger : public Burger{
  public:
  void prepare() override{
    cout<<"Preparing gourmet burger w/o wheat."<<endl;
  }
};

class wheatBasicBurger : public Burger{
  public:
  void prepare() override{
    cout<<"Preparing basic wheat burger."<<endl;
  }
};
class wheatStandardBurger : public Burger{
  public: 
  void prepare() override{
    cout<<"Preparing standard wheat burger."<<endl;
  }
};

class wheatPremiumBurger : public Burger{
  public:
  void prepare() override{
    cout<<"Preparing gourmet wheat burger."<<endl;
  }
};

class burgerFactory{
  public:
  virtual Burger* createBurger(string type)=0;
  virtual ~burgerFactory(){};
};

class singhBurger : public burgerFactory{
  public:
  Burger* createBurger(string type) override{
    cout<<"Normal Burger Factory is preparing your order."<<endl;
    if(type=="basic"){
      return new basicBurger();
    }
    else if(type=="standard"){
      return new standardBurger();
    }
    else if(type=="gourmet"){
      return new gourmetBurger();
    }
    else{
      cout<<"Invalid burger type";
      return nullptr;
    } 
  }
};

class kingBurger : public burgerFactory{
  public:
  Burger* createBurger(string type) override{
    cout<<"Your wheat burger is being prepared."<<endl;
    if(type=="basicwheat"){
      return new wheatBasicBurger();
    }
    else if(type=="standardWheat"){
      return new wheatStandardBurger();
    }
    else if(type=="premiumWheat"){
      return new wheatPremiumBurger();
    }
    else {
      cout<<"Invalid burger type";
      return nullptr;
    }
  }
};

int main(){
  //We have two shops singh and king one prepares wheat burger and other perpares normal burger.
  burgerFactory* singhShop = new singhBurger();
  burgerFactory* kingShop = new kingBurger();

  cout << "=== BURGER FACTORY DEMO ====" << endl;

  Burger* burgerOne= singhShop->createBurger("basic");
  if(burgerOne){
    burgerOne->prepare();
    delete burgerOne;
  }

  Burger* burgerTwo= kingShop->createBurger("premiumWheat");
  if(burgerTwo){
    burgerTwo->prepare();
    delete burgerTwo;
  }

  return 0;
}