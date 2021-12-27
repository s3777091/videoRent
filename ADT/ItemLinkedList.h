#pragma once
#ifndef ItemLinkedList_hpp
#define ItemLinkedList_hpp

using namespace std;

#include<vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>


typedef class item {
public:
    string id;
    string title;
    string rentaltype;
    string loantype;
    int stock;
    double fee;
    string status;
} Item;


class Node_item {
public:
    string item_id;
    string item_title;
    string item_rentaltype;
    string item_loantype;
    int item_stock;
    double item_fee;
    string item_status;
    Node_item* next;
};

class ItemLinkedList {
public:
    Node_item* head;
    Node_item* tail;
};

Node_item* ItemCreateNode(Item& item);

void ItemCreateList(ItemLinkedList& l);

void ItemAddTail(ItemLinkedList& l, Node_item* node);

void PrintItemList(ItemLinkedList l);

int ItemLength(ItemLinkedList l);

void add_items(ofstream& fileout, Item& item);

Node_item* Search_item(ItemLinkedList list, const string& item_id);

Node_item* Update_item_node(ItemLinkedList& l, const string& item_id);

#endif