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
    {
        this->name = name;
        this->location = location;
        this->restaurantId = ++nextRestaurantId;
    }

    ~Restaurant()
    {
        cout << "Destroying Restaurant: " << name << ", and clearing its menu." << endl;
        menu.clear();
    }

    // Getters and setters
    string getName() const
    {
        return name;
    }

    void setName(const string &n)
    {
        name = n;
    }

    string getLocation() const
    {
        return location;
    }

    void setLocation(const string &loc)
    {
        location = loc;
    }

    void addMenuItem(const MenuItem &item)
    {
        menu.push_back(item);
    }

    const vector<MenuItem> &getMenu() const
    {
        return menu;
    }

    int getId() const
    {
        return restaurantId;
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
};

int Restaurant::nextRestaurantId = 0;

#endif