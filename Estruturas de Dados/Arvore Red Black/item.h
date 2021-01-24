#ifndef ITEM_H
#define ITEM_H
#include "string"
using std::string;

#include <iostream>
using std::cout;
using std::cin;

class Item
{
private:
    int key;
    string nome;
public:
    bool setKey (unsigned int);
    int getKey ()const;
    void setNome (string);
    string getNome ()const;
    string empacotaItem () const;
};

#endif // ITEM_H
