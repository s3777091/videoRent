#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

Node_customer *
CreateNode(Customer &cs) {
    auto *node = new Node_customer;
    node->customer_id = cs.cid;
    node->customer_name = cs.name;
    node->customer_address = cs.address;
    node->customer_phone = cs.phone;
    node->customer_type = cs.type;
    node->customer_hint_item = cs.hint_item;
    node->customer_item_collection = cs.item_collection;
    node->next = nullptr;
    return node;
}


void CreateList(LinkedList &l) {
    l.head = nullptr;
    l.tail = nullptr;
}

void AddTail(LinkedList &l, Node_customer *node) {
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void printf_items_data(Items_str &its) {
    cout << "items id: " << its.i_id << "-" << its.i_date << endl;
    cout << "====================================" << endl;
}


void PrintList(LinkedList l) {
    if (l.head != nullptr) {
        Node_customer *node = l.head;
        while (node != nullptr) {
            cout << node->customer_id << ' ';
            cout << node->customer_name << ' ';
            cout << node->customer_address << ' ';
            cout << node->customer_phone << ' ';
            cout << node->customer_hint_item << ' ';
            cout << node->customer_type << '\n';
            for (auto &j: node->customer_item_collection) {
                printf_items_data(j);
            }
            node = node->next;
        }
    }
}

