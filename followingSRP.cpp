#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
  int price;
  string name;
  Product(int price, string name)
  {
    this->price = price;
    this->name = name;
  }
};

class shoppingCart
{
private:
  vector<Product *> products; // Make private for encapsulation

public:
  void addProduct(Product *p)
  { // Better method name
    products.push_back(p);
  }

  const vector<Product *> &getProducts() const
  { // Const method
    return products;
  }

  double calculateTotal() const
  { // Fixed: return the total
    double total = 0;
    for (auto p : products)
    {
      total += p->price;
    }
    return total; // Return instead of void
  }

  bool isEmpty() const
  {
    return products.empty();
  }
};

class printInvoiceClass
{
private:
  shoppingCart *cart;

public:
  printInvoiceClass(shoppingCart *cart)
  {
    this->cart = cart;
  }

  void printInvoice()
  { // Fixed method name
    cout << "=== INVOICE ===" << endl;
    cout << "Items:" << endl;

    if (cart->isEmpty())
    {
      cout << "No items in cart." << endl;
      return;
    }

    for (auto p : cart->getProducts())
    {
      cout << "- " << p->name << " : Rs." << p->price << endl;
    }
    cout << "-------------------" << endl;
    cout << "Total: Rs." << cart->calculateTotal() << endl;
    cout << "===================" << endl;
  }
};

class saveToDB
{
private:
  shoppingCart *cart;

public:
  saveToDB(shoppingCart *cart)
  {
    this->cart = cart;
  }

  void saveToDatabase()
  { // Better method name
    if (cart->isEmpty())
    {
      cout << "No items to save to database." << endl;
      return;
    }

    cout << "Saving cart to database..." << endl;
    cout << "Items saved: " << cart->getProducts().size() << endl;
    cout << "Total amount: Rs." << cart->calculateTotal() << endl;
    cout << "Successfully saved to DB!" << endl;
  }
};

int main()
{
  // Create shopping cart
  shoppingCart *cart = new shoppingCart();

  // Add products
  cart->addProduct(new Product(150000, "Laptop"));
  cart->addProduct(new Product(400000, "Dominar 400"));
  cart->addProduct(new Product(25000, "Smartphone"));
  cart->addProduct(new Product(5000, "Headphones"));

  cout << "Shopping Cart Demo - Following SRP" << endl;
  cout << "====================================" << endl
       << endl;

  // Print invoice using dedicated class
  printInvoiceClass *invoicePrinter = new printInvoiceClass(cart);
  invoicePrinter->printInvoice();

  cout << endl;

  // Save to database using dedicated class
  saveToDB *dbSaver = new saveToDB(cart);
  dbSaver->saveToDatabase();

  // Clean up memory
  for (auto product : cart->getProducts())
  {
    delete product;
  }
  delete cart;
  delete invoicePrinter;
  delete dbSaver;

  return 0;
}