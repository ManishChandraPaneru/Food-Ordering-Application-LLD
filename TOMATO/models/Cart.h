#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include "../models/MenuItem.h"
#include "../models/Restaurant.h"
using namespace std;

class Cart
{
private:
    int total;
    Restaurant *restaurant;
    vector<MenuItem> items;

public:
    Cart()
    {
        restaurant = nullptr;
        total = 0;
    }

    void addItem(const MenuItem &item)
    {
        if (!restaurant)
        {
            cout << "Please select restaurant first." << endl;
            return;
        }
        items.push_back(item);
    }

    const vector<MenuItem> &getItems() const
    {
        return items;
    }

    void setRestaurant(Restaurant *r)
    {
        restaurant = r;
    }

    Restaurant *getRestaurant() const
    {
        return restaurant;
    }

    double getTotalCost() const
    {
        double cost = 0;
        for (const auto &it : items)
        {
            cost += it.getPrice();
        }
        return cost;
    }

    void clear()
    {
        if (items.empty())
        {
            cout << "Nothing to delete." << endl;
            return;
        }
        items.clear();
        restaurant = nullptr;
        cout << "Cart is now empty." << endl;
    }

    bool isEmpty() const
    {
        return items.empty();
    }
};

#endif