item.h:

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string.h>

using namespace std;

class Item
{
    public:
        Item() {}
        virtual ~Item() {}

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        long Getid() { return id; }
        void Setid(long val) { id = val; }
        double Getprice() { return price; }
        void Setprice(double val) { price = val; }
        int Getstock() { return stock; }
        void Setstock(int val) { stock = val; }

    protected:

    private:
        string name;
        long id;
        double price;
        int stock;
};

ostream &operator << (ostream &out, const Item item){
    return (out << "Name: " << item.Getname() << endl << "ID: " << item.Getid() << endl
            << "Price: " << item.Getprice() << endl << "Stock: " << item.Getstock() << endl);
}

#endif // ITEM_H
Store.h:

#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string.h>
#include <item>
#include "Order.h"
#include <vector>

class Store
{
    public:
        Store() {}
        virtual ~Store() {}

        Item Getitems[100]() { return items[100]; }
        void Setitems[100](Item val) { items[100] = val; }

void print(){
            cout << "Store: " << endl;
            for (int i = 0; i < 100; i++){
                if (this->items[i] == NULL){
                    break;
                }

                else{
                    cout << this->items[i].Getname() << " x " << this->items[i].Getstock() << endl;
                }
            }


        void processOrder(const Order &order){
            vector<Item> itemsOrdered = order->Getitems();

            for (int i = 0; i < 10; i++){
                for (int y = 0; y < 100; y++){
                    if (this->items[y] == NULL){
                        continue;
                    }

                    else if (itemsOrdered.at(i).Getname() == this->items[y].Getname()){
                        this->items[y].Setstock(this->items[y].Getstock() - itemsOrdered.at(i).Getstock());
                        break;
                    }
                }
            }
        }

    protected:

    private:
        Item items[100];
};

ostream &operator << (ostream &out, const Store &store){
    out << "Store: " << endl;
    Item items[100] = store->Getitems();

    for (int i = 0; i < 100; i++){
        if (items[i] == NULL){
            break;
        }

        else{
            out << items[i].Getname() << " x " << items[i].Getstock() << endl;
        }
    }
}

