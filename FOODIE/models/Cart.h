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
    Restaurant *restaurant;
    vector<MenuItem> items;

public:
    Cart() : restaurant(nullptr) {}

    // Cart operations
    bool addItem(const MenuItem &item)
    {
        if (!restaurant)
        {
            return false; // No restaurant selected
        }
        items.push_back(item);
        return true;
    }

    void removeItem(const string &itemCode)
    {
        auto it = items.begin();
        while (it != items.end())
        {
            if (it->getCode() == itemCode)
            {
                items.erase(it);
                break;
            }
            ++it;
        }
    }

    void clear()
    {
        items.clear();
        restaurant = nullptr;
    }

    // Getters
    const vector<MenuItem> &getItems() const { return items; }
    Restaurant *getRestaurant() const { return restaurant; }
    bool isEmpty() const { return items.empty(); }

    size_t getItemCount() const { return items.size(); }

    double getTotalCost() const
    {
        double cost = 0.0;
        for (const auto &item : items)
        {
            cost += item.getPrice();
        }
        return cost;
    }

    // Setters
    void setRestaurant(Restaurant *r) { restaurant = r; }
};

#endif