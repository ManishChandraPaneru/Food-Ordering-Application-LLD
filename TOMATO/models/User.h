#ifndef  USER_H
#define USER_H

#include<iostream>
#include<vector>
#include<string>
#include "Cart.h"

using namespace std;

class User{
  private:
    int id;
    string name;
    string address;
    Cart* cart;

  public:
    User(int id,const string &name,const string &address){
      this->id=id;
      this->name=name;
      this->address=address;
      cart=new Cart();
    }

    ~User(){
      delete cart;
    }

    int getId(){return id;}
    string getName(){return name;}
    void setName(const string &n){name=n;}
    string getAddress(){return address;}
    void setAddress(const string &a){address=a;}
    Cart* getCart(){return cart;}
};

#endif
