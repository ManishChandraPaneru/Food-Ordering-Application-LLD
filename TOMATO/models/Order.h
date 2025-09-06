#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include<vector>
#include "models/Restraunt.h"
#include "models/MenuItem.h"
#include "models/User.h"
#include "../TOMATO/Strategies/PaymentStrategies.h"
using namespace std;

class Order{
  private:
    int id;

    Restraunt *restraunt;
    vector<MenuItem> items;
    User *user;
    PaymentStrategy *ps;
    
};

#endif