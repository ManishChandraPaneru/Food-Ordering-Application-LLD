#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "Order.h"
using namespace std;

class DeliveryOrder : public Order
{
private:
  string deliveryAddress;
  double deliveryFee;

public:
  DeliveryOrder() : deliveryAddress(""), deliveryFee(5.0) {}

  DeliveryOrder(const string &address) : deliveryAddress(address), deliveryFee(5.0) {}

  string getType() const override
  {
    return "Delivery";
  }

  // Calculate total including delivery fee
  double calculateTotal() const
  {
    return getTotal() + deliveryFee;
  }

  // Getters and setters
  void setDeliveryAddress(const string &address)
  {
    deliveryAddress = address;
  }

  string getDeliveryAddress() const
  {
    return deliveryAddress;
  }

  void setDeliveryFee(double fee)
  {
    deliveryFee = fee;
  }

  double getDeliveryFee() const
  {
    return deliveryFee;
  }
};

#endif // DELIVERY_ORDER_H