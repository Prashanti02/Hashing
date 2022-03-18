//
//  main.cpp
//  Hashing
//
//  Created by Prashanti Pokharel on 9/21/21.
//

#include <iostream>
#include "Stock.h"
using namespace std;

template<typename T>
struct HTElement
{
    T item;
    int status;
};

template <typename T>
class HashTable
{
public:
    HashTable(int size =10);
    ~HashTable();
    void remove(const T& item);
    void insert(const T& item);
    void display() const;
    T* search(const T& item) const;
private:
    HTElement <T>* table;
    int tableSize;
};

template <typename T>
HashTable<T>::HashTable(int size)
{
    table = new HTElement <T> [size];
    tableSize = size;
    for (int i = 0; i < size; i++)
    {
        table[i].status = 0;
    }
}

template <typename T>
HashTable<T>::~HashTable()
{
    delete[] table;
}

template <typename T>
void HashTable<T>::remove(const T& item)
{
    int index;
    index = item.hash(tableSize);
    bool found = false;
    int i = 1;
    do {
        if (table[index].item == item || table[index].status == 0)
        {
            if (table[index].status == 0)
            {
                cout << "The value is not found" << endl;
                break;
            }
            table[index].status = -1;
            found = true;
        }
        else
        {
            index = (item.hash(tableSize) + i ^ 2) % tableSize;
            i++;
        }
    } while (found == false);

}

template <typename T>
void HashTable<T>::insert(const T& item)
{
    int index;
    index = item.hash(tableSize);
    int i = 1;
    bool inserted = false;
    do
    {
        if (table[index].status != 1)
        {
            table[index].item = item;
            table[index].status = 1;
            inserted = true;
        }
        else
        {
            index = (item.hash(tableSize) + i ^ 2) % tableSize;
        }
        i++;
    }
    while (inserted==false);
}

template <typename T>
void HashTable<T>::display() const
{
    for(int i = 0;i<tableSize;i++)
    {
        if (table[i].status == 1)
        {
            cout << table[i].item;
        }
    }
}

template <typename T>
T* HashTable<T>::search(const T& item) const
{
    T* result = nullptr;
    int index;
    index = item.hash(tableSize);
    bool found = false;
    int i = 1;
    do {
        if (table[index].item == item || table[index].status==0)
        {
            if (table[index].status == 0)
            {
                return result;
            }
            result = new T(table[index].item);
            found = true;
        }
        else
        {
            index = (item.hash(tableSize) + i ^ 2) % tableSize;
            i++;
        }
    } while (found == false);

    return result;
}

 int main()
 {
     Stock s1("Ferrari ", "F", 500);
     Stock s2("BMW ", "B", 200);
     Stock s3("Chevrolet ", "C", 800);
     Stock s4("Volskwagen ", "V", 1000);
    //initial insert
     HashTable<Stock> H;
     H.insert(s1);
     H.insert(s2);
     H.insert(s3);
     H.insert(s4);
     H.display();
     
     //search
     cout<<endl;
     Stock * x = H.search(s3);
     if(x!=nullptr)
     {
         cout<<"Copied value is : "<<endl;
         HashTable<Stock> x1;
         x1.insert(*x);
         x1.display();
     }
     else{
         cout<<"Not found"<<endl;
     }
     //delete
     cout << endl;
     H.remove(s3);
     cout << "Hash table after deletion :  " << endl;
     H.display();
    
     //replacing after deletion
     cout<<endl;
     Stock x1("Audi ", "A", 599 );
     H.insert(x1);
     H.display();

     return 0;
 }
