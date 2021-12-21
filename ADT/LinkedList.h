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

typedef struct items_collection {
    string itc_id;
    string itc_name;
    string itc_types;
    string itc_loans_types;
    string itc_copies;
    string itc_fees;
    string itc_genre;
} Items_Collection;

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

struct Node_items_collection {
    string node_itc_id;
    string node_itc_name;
    string node_itc_types;
    string node_itc_loans_types;
    string node_itc_copies;
    string node_itc_fees;
    string node_itc_genre;
    Node_items_collection * next;
};

struct LinkedList_Items_collection {
    Node_items_collection *head_items;
    Node_items_collection *tail_items;
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

int Length(LinkedList l);

void add_items(ofstream &fileout, Items_str &its);

Node_customer *Search_Customer(LinkedList list, const string &customer_id);

Node_customer *promote(LinkedList l, const string &number_id);

Node_customer *Update_Customer_node(LinkedList &l, const string &customer_id);

void display_customer_type(const vector<customer> &ts, const string &type);

Node_items_collection * createNode_items(Items_Collection &itc);

#endif