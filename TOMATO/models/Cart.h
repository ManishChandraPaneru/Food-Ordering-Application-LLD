#ifndef CART_H
#define CART_H 

#include<iostream>
#include<vector>
#include"../models/MenuItem.h"
#include"../models/Restraunt.h"
using namespace std;

class Cart{
private:
    int total;
    Restraunt* restraunt;
    vector<MenuItem> items;

public:
    Cart(){
        restraunt = nullptr;
        total = 0; 
    }

    void addItem(const MenuItem &item){
        if(!restraunt){
            cout << "Please select restraunt first." << endl;
            return;
        }
        items.push_back(item);
    }

    const vector<MenuItem>& getItems() const {
        return items;
    }

    void setReatraunt(Restraunt *r){
        restraunt = r;
    }

    Restraunt* getRestraunt() const {  
        return restraunt;
    }

    double getTotalCost() const {
        double cost = 0;
        for(const auto &it : items){
            cost += it.getPrice();
        }
        return cost;
    }

    void clearCart(){
        if(items.empty()){ 
            cout << "Nothing to delete." << endl;
            return;
        }
        items.clear();
        restraunt = nullptr;
        cout << "Cart is now empty." << endl;
    }

    bool isEmpty() const {  
        return items.empty(); 
    }
};

#endif