#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>
#include "Cart.h"
using namespace std;

class User
{
private:
  int id;
  string name;
  string address;
  Cart *cart;

public:
  User(int id, const string &name, const string &address)
      : id(id), name(name), address(address)
  {
    cart = new Cart();
  }

  ~User()
  {
    delete cart;
  }

  // Getters
  int getId() const { return id; }
  string getName() const { return name; }
  string getAddress() const { return address; }
  Cart *getCart() { return cart; }

  // Setters
  void setName(const string &n) { name = n; }
  void setAddress(const string &a) { address = a; }
};

#endif
