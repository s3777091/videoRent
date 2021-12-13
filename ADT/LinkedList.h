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

typedef struct customer {
    string cid;
    string name;
    string address;
    string phone;
    string hint_item;
    string type;
    int total_item{};
    vector<items> item_collection;
} Customer;


struct Node_customer {
    string customer_id;
    string customer_name;
    string customer_address;
    string customer_phone;
    string customer_hint_item;
    string customer_type;
    vector<items> customer_item_collection;
    Node_customer *next;
};


struct LinkedList {
    Node_customer *head;
    Node_customer *tail;
};

Node_customer *CreateNode(Customer &cs);

void CreateList(LinkedList &l);

void AddTail(LinkedList &l, Node_customer *node);

void PrintList(LinkedList l);

void printf_items_data(Items_str &its);

void add_items(ofstream &fileout, Items_str &its);

Node_customer *Search_Customer(LinkedList list, Node_customer *node, const string& customer_id);
Node_customer *promote(LinkedList l, Node_customer *node,const string& number_id);
Node_customer *Update_Customer_node(LinkedList &l, Node_customer *node, const string& customer_id);

#endif