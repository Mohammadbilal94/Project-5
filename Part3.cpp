#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Items
{
public:
        string name;
        double price;
        int quantity;
        Items(string name, double price, int quantity)
        {
                this->name = name;
                this->price = price;
                this->quantity = quantity;
        }

};
vector<Items> v;
class Store
{
public:
        void addItem(Items i)
        {
                v.push_back(i);
        }
        void printItems()
        {
                for (int i = 0; i < v.size(); i++)
                {
                        Items curr = v[i];
                        cout << curr.name << " x " << curr.quantity << endl;
                        //cout << endl;
                }
        }
};

int32_t main()
{
        Items i1("Book", 120, 3);
        Items i2("Colored pencil", 35, 2);
        Store s1;
        s1.addItem(i1);
        s1.addItem(i2);
        s1.printItems();
        return 0;
}