#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include <iostream>
#include "PaymentStrategies.h"
using namespace std;

class UPIPaymentStrategy : public PaymentStrategy
{
private:
  string mobile;

public:
  UPIPaymentStrategy(const string &mobile)
  {
    this->mobile = mobile;
  }

  void pay(double amount)
  {
    cout << "Amount - " << amount << " payed through UPI with phone number" << mobile << endl;
  }
};

#endif