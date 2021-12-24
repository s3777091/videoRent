//
// Created by Asus on 12/24/2021.
//

#include "ItemsList.h"

Node_items_collection * ItemsList::createNode_items(items_collection &itc){
    auto * node = new Node_items_collection(itc);
    node->next = nullptr;
    return node;
}

void ItemsList::CreateListItems(ItemsList &l) {
    l.head_items = nullptr;
    l.tail_items = nullptr;
}

void ItemsList::AddTailItems(ItemsList &l, Node_items_collection *node) {
    if (l.head_items == nullptr) {
        l.head_items = node;
        l.tail_items = node;
    } else {
        l.tail_items->next = node;
        l.tail_items = node;
    }
}



void ItemsList::showList(Node_items_collection *node){
    cout << node->node_itc_id << ' ';
    cout << node->node_itc_name << ' ';
    cout << node->node_itc_types << ' ';
    cout << node->node_itc_loans_types << ' ';
    cout << node->node_itc_copies << ' ';
    cout << node->node_itc_fees << ' ';
    cout << node->node_itc_genre << endl;
}


void ItemsList::PrintListItems(ItemsList l) {
    if (l.head_items != nullptr) {
        Node_items_collection *node = l.head_items;
        while (node != nullptr) {
            ItemsList::showList(node);
            node = node->next;
        }
    }
}