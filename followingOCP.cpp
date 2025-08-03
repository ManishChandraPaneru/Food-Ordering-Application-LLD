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

// Abstract base class - defines interface (Open for extension)
class Persistence{
  public:
    virtual void save(shoppingCart *cart) = 0;
    virtual ~Persistence() {} // Virtual destructor for proper cleanup
};

// Concrete implementations (Closed for modification)
class sqlPersistence: public Persistence{
  public:
    void save(shoppingCart *cart) override{
      if(cart->isEmpty()){
        cout << "No data to save to SQL database." << endl;
        return;
      }
      cout << "Saving to SQL Database..." << endl;
      cout << "Items saved: " << cart->getProducts().size() << endl;
      cout << "Total amount: Rs." << cart->calculateTotal() << endl;
      cout << "Successfully saved to SQL DB!" << endl;
    }
};

class mongoPersistence : public Persistence{
  public:
    void save(shoppingCart *cart) override{
      if(cart->isEmpty()){
        cout << "No data to save to MongoDB." << endl;
        return;
      }
      cout << "Saving to MongoDB..." << endl;
      cout << "Document created with " << cart->getProducts().size() << " items" << endl;
      cout << "Total value: Rs." << cart->calculateTotal() << endl;
      cout << "Successfully saved to MongoDB!" << endl;
    }
};

class cassandraPersistence : public Persistence{
  public: 
    void save(shoppingCart *cart) override{
      if(cart->isEmpty()){
        cout << "No data to save to Cassandra DB." << endl;
        return;
      }
      cout << "Saving to Cassandra DB..." << endl;
      cout << "Column family updated with " << cart->getProducts().size() << " rows" << endl;
      cout << "Total amount: Rs." << cart->calculateTotal() << endl;
      cout << "Successfully saved to Cassandra DB!" << endl;
    }
};

// New persistence type can be added without modifying existing code
class redisPersistence : public Persistence{
  public:
    void save(shoppingCart *cart) override{
      if(cart->isEmpty()){
        cout << "No data to cache in Redis." << endl;
        return;
      }
      cout << "Caching to Redis..." << endl;
      cout << "Key-value pairs created for " << cart->getProducts().size() << " items" << endl;
      cout << "Cache TTL: 3600 seconds" << endl;
      cout << "Successfully cached to Redis!" << endl;
    }
};

// Context class that uses different persistence strategies
class PersistenceManager{
private:
  Persistence* persistenceStrategy;

public:
  PersistenceManager(Persistence* strategy){
    this->persistenceStrategy = strategy;
  }

  void setPersistenceStrategy(Persistence* strategy){
    this->persistenceStrategy = strategy;
  }

  void saveToDB(shoppingCart* cart){
    if(persistenceStrategy != nullptr){
      persistenceStrategy->save(cart);
    }
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

  cout << "Shopping Cart Demo - Following OCP" << endl;
  cout << "====================================" << endl << endl;

  // Print invoice using dedicated class
  printInvoiceClass *invoicePrinter = new printInvoiceClass(cart);
  invoicePrinter->printInvoice();

  cout << endl;

  // Demonstrate OCP - Multiple persistence options without modifying existing code
  cout << "=== PERSISTENCE DEMO (OCP) ===" << endl;

  // SQL Persistence
  PersistenceManager* manager = new PersistenceManager(new sqlPersistence());
  manager->saveToDB(cart);
  cout << endl;

  // Switch to MongoDB without changing existing code
  manager->setPersistenceStrategy(new mongoPersistence());
  manager->saveToDB(cart);
  cout << endl;

  // Switch to Cassandra
  manager->setPersistenceStrategy(new cassandraPersistence());
  manager->saveToDB(cart);
  cout << endl;

  // New Redis persistence - added without modifying existing classes
  manager->setPersistenceStrategy(new redisPersistence());
  manager->saveToDB(cart);
  cout << endl;

  cout << "=== OCP DEMONSTRATION COMPLETE ===" << endl;
  cout << "New persistence types can be added without modifying existing code!" << endl;

  // Clean up memory
  for(auto product : cart->getProducts()){
    delete product;
  }
  delete cart;
  delete invoicePrinter;
  delete manager;

  return 0;
}