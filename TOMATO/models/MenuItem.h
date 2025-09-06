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
  {
    this->id = id;
    this->dishName = dishName;
    this->price = price;
  }

  string getId() const
  {
    return id;
  }

  string getCode() const
  {
    return id; // Same as getId for compatibility
  }

  string getName() const
  {
    return dishName; // Same as getDishName for compatibility
  }

  void setId(const string &newId)
  {
    id = newId;
    cout << "Id updated successfully." << endl;
    return;
  }

  string getDishName() const
  {
    return dishName;
  }

  void setDishName(const string &newName)
  {
    dishName = newName;
    cout << "Name updated successfully." << endl;
    return;
  }

  double getPrice() const
  {
    return price;
  }

  void setPrice(double newPrice)
  {
    price = newPrice;
    cout << "Price updated successfully.";
    return;
  }
};
#endif