#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include "Order.h"
using namespace std;

class PickupOrder : public Order
{
private:
    string pickupLocation;
    bool isReady;

public:
    PickupOrder() : pickupLocation(""), isReady(false) {}

    PickupOrder(const string &location) : pickupLocation(location), isReady(false) {}

    string getType() const override
    {
        return "Pickup";
    }

    // Getters and setters
    void setPickupLocation(const string &location)
    {
        pickupLocation = location;
    }

    string getPickupLocation() const
    {
        return pickupLocation;
    }

    // Legacy method for compatibility
    void setRestaurantAddress(const string &addr)
    {
        pickupLocation = addr;
    }

    string getRestaurantAddress() const
    {
        return pickupLocation;
    }

    void markReady()
    {
        isReady = true;
    }

    bool getReadyStatus() const
    {
        return isReady;
    }
};

#endif // PICKUP_ORDER_H