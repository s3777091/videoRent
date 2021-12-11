#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

Node_customer *
CreateNode(Customer &cs) {
    Node_customer *node = new Node_customer;
    node->customer_id = cs.cid;
    node->customer_name = cs.name;
    node->customer_address = cs.address;
    node->customer_phone = cs.phone;
    node->customer_type = cs.type;
    node -> customer_hint_item = cs.hint_item;
    node->next = NULL;
    return node;
}

Node_items *
Create_node_items(Items_structer &its) {
    Node_items *nit = new Node_items;
    nit->items_id = its.i_id;
    nit->items_date = its.i_date;
    nit->next_items = NULL;
    return nit;
}

void CreateList(LinkedList &l) {
    l.head = NULL;
    l.tail = NULL;
}

void CreateList_items(LinkedListItems& l){
    l.head_items = NULL;
    l.tail_items = NULL;
}

void AddTail(LinkedList &l, Node_customer *node) {
    if (l.head == NULL) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void AddTailitems(LinkedListItems &l, Node_items *nodeitems) {
    if (l.head_items == NULL) {
        l.head_items = nodeitems;
        l.tail_items = nodeitems;
    } else {
        l.tail_items->next_items = nodeitems;
        l.tail_items = nodeitems;
    }
}


void PrintList(LinkedList l) {
    if (l.head != NULL) {
        Node_customer *node = l.head;
        while (node != NULL) {
            cout << node->customer_id << ' ';
            cout << node->customer_name << ' ';
            cout << node->customer_address << ' ';
            cout << node->customer_phone << ' ';
            cout << node -> customer_hint_item << ' ';
            cout << node -> customer_type << '\n';
            node = node->next;
        }
    }
}

void PrintList_items(LinkedListItems l) {
    if (l.head_items != NULL) {
        Node_items *node = l.head_items;
        while (node != NULL) {
            cout << node->items_id << '-' << node->items_date << '\n';
            node = node->next_items;
        }
    }
}