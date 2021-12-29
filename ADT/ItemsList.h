#ifndef VIDEOONLINE_H_ITEMSLIST_H
#define VIDEOONLINE_H_ITEMSLIST_H

using namespace std;

#include<vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class items_collection {
public:
    string itc_id;
    string itc_name;
    string itc_types;
    string itc_loans_types;
    string itc_copies;
    string itc_fees;
    string itc_genre;
};

class Node_items_collection {
public:
    string node_itc_id;
    string node_itc_name;
    string node_itc_types;
    string node_itc_loans_types;
    string node_itc_copies;
    string node_itc_fees;
    string node_itc_genre;
    Node_items_collection *next;

    explicit Node_items_collection(items_collection &it) {
        this->node_itc_id = it.itc_id;
        this->node_itc_name = it.itc_name;
        this->node_itc_types = it.itc_types;
        this->node_itc_loans_types = it.itc_loans_types;
        this->node_itc_copies = it.itc_copies;
        this->node_itc_fees = it.itc_fees;
        this->node_itc_genre = it.itc_genre;
    }

};


class ItemsList {
public:
    Node_items_collection *head_items;
    Node_items_collection *tail_items;

    static Node_items_collection *createNode_items(items_collection &itc);

    static void CreateListItems(ItemsList &l);

    static void AddTailItems(ItemsList &l, Node_items_collection *node);

    static void showList(Node_items_collection *node);

    static int to_int(const string& item_id);

    static void showNode(Node_items_collection *node);

    static void PrintListItems(ItemsList l);

    static Node_items_collection *SearchItem(ItemsList list, const string& item_id);
};


#endif //VIDEOONLINE_H_ITEMSLIST_H
