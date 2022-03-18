//
//  Stock.h
//  Hashing
//
//  Created by Prashanti Pokharel on 9/21/21.
//

#ifndef Stock_h
#define Stock_h

#include <iostream>
using namespace std;

class Stock
{
    string name;
    string symbol;
    double price;
public:
    Stock(const string& name="", const string& symbol="", double price=0)
    {
        this->name=name;
        this->symbol=symbol;
        this->price=price;
    }
    Stock(const Stock& s)
    {
    this->name= s.name;
    this->symbol=s.symbol;
    this->price=s.price;
    }
    void display () const
    {
        cout<<"Name"<<name<<endl;
        cout<<"Symbol"<<symbol<<endl;
        cout<<"Price"<<price<<endl;
    }
    string getName() const
    {
        return name;
    }
    string getSymbol() const{
        return symbol;
    }
    double getPrice() const
    {
        return price;
    }
    bool operator==(const Stock& rhs) const
    {
     if (this->symbol==rhs.symbol)
      {
          return true;
      }
      return false;
    }
    bool operator!=(const Stock& rhs) const
{
    if(this->symbol!=rhs.symbol)
    {
        return true;
    }
    return false;
}
    bool operator>(const Stock& rhs) const
    {
        return (this->symbol > rhs.symbol);
    }
    bool operator<(const Stock& rhs) const
    {
        return (this->symbol < rhs.symbol);
    }
    friend std::ostream& operator << (std::ostream & os, const Stock s)
    {
        return os<<"Name : " << s.name << " Symbol : " << s.symbol << " Price : " << s.price <<endl;
    }
    int hash (int size) const
    {
        int sum=0;
        for (int i=0; i<symbol.size();i++)
        {
            sum= sum+symbol[i];
        }
        return sum%size;
    }
};

#endif /* Stock_h */
