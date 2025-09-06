#ifndef PAYMENT_STRATEGIES
#define  PAYMENT_STRATEGIES

#include<iostream>
using namespace std;

class PaymentStrategy{
  public:
    virtual void pay(double amount)=0;
    virtual ~PaymentStrategy(){};

};

#endif 