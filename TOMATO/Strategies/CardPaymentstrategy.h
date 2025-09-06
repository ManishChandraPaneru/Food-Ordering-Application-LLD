#ifndef CARD_PAYMENT_STRATEGY_H
#define CARD_PAYMENT_STRATEGY_H

#include <iostream>
#include <string>
#include "PaymentStrategies.h"
using namespace std;

class CardPaymentStrategy : public PaymentStrategy
{
private:
  string name;
  string cardNumber;
  string expiryDate;
  string CVV;

public:
  CardPaymentStrategy(const string &name, const string &cardNumber,
                      const string &expiryDate, const string &CVV)
  {
    this->name = name;
    this->cardNumber = cardNumber;
    this->expiryDate = expiryDate;
    this->CVV = CVV;
  }

  void pay(double amount) override
  {
    cout << "Processing card payment..." << endl;
    cout << "Amount: ₹" << amount << endl;
    cout << "Card holder: " << name << endl;
    cout << "Card Number: ****-****-****-" << cardNumber.substr(cardNumber.length() - 4) << endl;
    cout << "Expiry: " << expiryDate << endl;
    cout << "Payment successful via Credit Card!" << endl;
  }
};

#endif