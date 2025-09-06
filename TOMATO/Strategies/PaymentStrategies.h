#ifndef PAYMENT_STRATEGIES
#define  PAYMENT_STRATEGIES

#include<iostream>
using namespace std;

class PaymentStrategy{
  virtual void pay(double amount)=0;

};

#endif 