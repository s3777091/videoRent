#ifndef LinkedList_hpp
#define LinkedList_hpp

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

class LinkedList {
public:
    static Node_customer *CreateNode(Customer &cs);

    static void CreateList(LinkedList &l);

    static void AddTail(LinkedList &l, Node_customer *node);

    static void PrintList(LinkedList l);

    static void printf_items_data(Items_str &its);

    static void add_items(ofstream &fileout, Items_str &its);

    static Node_customer *Search_Customer(LinkedList list, const string &customer_id);

    static Node_customer *promote(LinkedList l, const string &number_id);

    static Node_customer *Update_Customer_node(LinkedList &l, const string &customer_id);

    static void display_customer_type(const vector<Customer> &ts, const string &type);

    static void showNode(Node_customer *node);

    Node_customer *head;
    Node_customer *tail;
};


#endif