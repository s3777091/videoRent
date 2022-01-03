#ifndef VIDEORENT_CUSTOMER_H
#define VIDEORENT_CUSTOMER_H

using namespace std;

#include<vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

typedef struct items {
    string i_id;
    string i_date;
} Items_str;

class Customer {
public:
    string cid;
    string name;
    string address;
    string phone;
    string hint_item;
    string type;
    int total_item{};
    vector<items> item_collection;
};

class Node_customer {
public:
    string customer_id;
    string customer_name;
    string customer_address;
    string customer_phone;
    string customer_hint_item;
    string customer_type;
    vector<items> customer_item_collection;
    Node_customer *next{};

    explicit Node_customer(Customer &cs) {
        this->customer_id = cs.cid;
        this->customer_name = cs.name;
        this->customer_address = cs.address;
        this->customer_phone = cs.phone;
        this->customer_hint_item = cs.hint_item;
        this->customer_type = cs.type;
        this->customer_item_collection = cs.item_collection;
    }
};


#endif //VIDEORENT_CUSTOMER_H
