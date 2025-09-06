#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
using namespace std;

class MenuItem
{
private:
  string id;
  string dishName;
  double price;

public:
  MenuItem(const string &id, const string &dishName, double price)
      : id(id), dishName(dishName), price(price) {}

  // Getters
  string getId() const { return id; }
  string getCode() const { return id; } // Alias for compatibility
  string getName() const { return dishName; }
  string getDishName() const { return dishName; }
  double getPrice() const { return price; }

  // Setters
  void setId(const string &newId)
  {
    id = newId;
  }

  void setDishName(const string &newName)
  {
    dishName = newName;
  }

  void setPrice(double newPrice)
  {
    if (newPrice >= 0)
    {
      price = newPrice;
    }
  }
};
#endif