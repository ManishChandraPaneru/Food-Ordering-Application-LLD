#include<bits/stdc++.h>
using namespace std;

class Product{
  public:
    int price;
    string name;
    Product(int price,string name){
      this->price=price;
      this->name=name;
    }
};

class shoppingCart{
  private:
  vector<Product*> products;

  public:
  void addProduct(Product* p){
    products.push_back(p);
  }

  const vector<Product*>& getProducts(){
    return products;
  }

  int calculateTotal(){
    double total=0;
    for(auto p:products){
      total+=p->price;
    }
    cout<<"Total price:"<<total;
  }
  
  void printInvoice(){
    for(auto p:products){
      cout<<p->name<<"-"<<p->price<<endl;
    }
    cout<<calculateTotal();
  }

  void saveToDatabase(){
    cout<<"Saving to database";
  }

};

int main(){
  shoppingCart *cart= new shoppingCart();
  cart->addProduct(new Product(150000,"Laptop"));
  cart->addProduct(new Product(400000,"Dominar 400"));
  return 0;
}