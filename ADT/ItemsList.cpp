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

int ItemsList::to_int(const string& item_id) {
    string string_number = item_id.substr(1, 3) + item_id.substr(5,4);
    stringstream exchange_number(string_number);
    int x = 0;
    exchange_number >> x;
    return x;
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

void ItemsList::showNode(Node_items_collection* node) {
    cout << node->node_itc_id << ' ';
    cout << node->node_itc_name << ' ';
    cout << node->node_itc_types << ' ';
    cout << node->node_itc_loans_types << ' ';
    cout << node->node_itc_copies << ' ';
    cout << node->node_itc_fees << ' ';
    cout << node->node_itc_genre << '\n';
}

Node_items_collection *ItemsList::SearchItem(ItemsList list, const string& item_id) {
    Node_items_collection* new_node;
    new_node = list.head_items;
    int i = 0;
    int number = ItemsList::to_int(item_id) - 1;
    while (new_node != nullptr && i != number) {
        new_node = new_node->next;
        i++;
    }
    if (i == number && new_node != nullptr) {
        ItemsList::showNode(new_node);
    }
    return nullptr;
}

