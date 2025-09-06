#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include <vector>
#include "MenuItem.h"
using namespace std;

class Restaurant
{
private:
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string location;
    vector<MenuItem> menu;

public:
    Restaurant(const string &name, const string &location)
        : name(name), location(location), restaurantId(++nextRestaurantId) {}

    ~Restaurant()
    {
        menu.clear();
    }

    // Getters
    string getName() const { return name; }
    string getLocation() const { return location; }
    int getId() const { return restaurantId; }
    const vector<MenuItem> &getMenu() const { return menu; }

    // Setters
    void setName(const string &n) { name = n; }
    void setLocation(const string &loc) { location = loc; }

    // Menu operations
    void addMenuItem(const MenuItem &item)
    {
        menu.push_back(item);
    }

    MenuItem *findMenuItem(const string &itemCode)
    {
        for (auto &item : menu)
        {
            if (item.getCode() == itemCode)
            {
                return &item;
            }
        }
        return nullptr;
    }

    bool hasMenuItem(const string &itemCode) const
    {
        for (const auto &item : menu)
        {
            if (item.getCode() == itemCode)
            {
                return true;
            }
        }
        return false;
    }
};

int Restaurant::nextRestaurantId = 0;

#endif