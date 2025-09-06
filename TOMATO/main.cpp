#include <iostream>
#include "app.h"
using namespace std;

int main()
{
  cout << "=== WELCOME TO TOMATO FOOD DELIVERY ===" << endl;

  // Create TomatoApp Object
  TomatoApp *tomato = new TomatoApp();

  // Simulate a user coming in
  User *user = new User(101, "Aditya", "Delhi");
  cout << "\nUser: " << user->getName() << " is active." << endl;

  // Restaurant Search
  cout << "\nSearching restaurants in " << user->getAddress() << "..." << endl;
  vector<Restaurant *> restaurantList = tomato->searchRestaurants("Delhi");

  if (restaurantList.empty())
  {
    cout << "No restaurants found!" << endl;
    return 0;
  }

  cout << "\nFound " << restaurantList.size() << " restaurants:" << endl;
  for (size_t i = 0; i < restaurantList.size(); i++)
  {
    cout << i + 1 << ". " << restaurantList[i]->getName() << " (" << restaurantList[i]->getLocation() << ")" << endl;
  }

  // Selecting Restaurant
  tomato->selectRestaurant(user, restaurantList[0]);
  cout << "\nSelected restaurant: " << restaurantList[0]->getName() << endl;

  // Show menu
  cout << "\nMenu available:" << endl;
  const vector<MenuItem> &menu = restaurantList[0]->getMenu();
  for (const auto &item : menu)
  {
    cout << item.getCode() << " - " << item.getName() << " - ₹" << item.getPrice() << endl;
  }

  // Item addition
  cout << "\nAdding items to cart..." << endl;
  tomato->addToCart(user, "P1");
  tomato->addToCart(user, "P2");

  // Show cart
  cout << "\n";
  tomato->printUserCart(user);

  // Checkout
  cout << "\nProcessing checkout..." << endl;
  Order *order = tomato->checkoutNow(user, "Delivery", new UPIPaymentStrategy("1234567890"));

  if (order)
  {
    tomato->payForOrder(user, order);
    cout << "\nOrder placed successfully!" << endl;
  }
  else
  {
    cout << "\nOrder failed!" << endl;
  }

  // Demonstrate different order type
  cout << "\n=== TESTING PICKUP ORDER ===" << endl;
  User *user2 = new User(102, "Priya", "Delhi");

  if (restaurantList.size() > 1)
  {
    tomato->selectRestaurant(user2, restaurantList[1]); // Select second restaurant
  }
  else
  {
    tomato->selectRestaurant(user2, restaurantList[0]); // Use first restaurant if only one available
  }

  tomato->addToCart(user2, "P1"); // Add one item

  tomato->printUserCart(user2);
  Order *pickupOrder = tomato->checkoutNow(user2, "Pickup", new UPIPaymentStrategy("9876543210"));
  if (pickupOrder)
  {
    tomato->payForOrder(user2, pickupOrder);
  }

  // Cleanup Code.
  delete tomato;
  delete user;
  delete user2;

  cout << "\nThank you for using TOMATO!" << endl;
  return 0;
}