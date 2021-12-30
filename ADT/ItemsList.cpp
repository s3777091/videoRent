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
    cout << node->node_itc_title << ' ';
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
    cout << node->node_itc_title << ' ';
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

Node_items_collection::Node_items_collection() {
    this->node_itc_id = "I000 - 0000";
    this->node_itc_title = "Item Title";
    this->node_itc_types = "Item Type";
    this->node_itc_loans_types = "Item Loan Type";
    this->node_itc_copies = "Item Copies";
    this->node_itc_fees = "0.99";
    this->node_itc_genre = ' ';
}

Node_items_collection::Node_items_collection(string id, string title, string type, string loan_type, string copies, string fee) {
    this->node_itc_id = id;
    this->node_itc_title = title;
    this->node_itc_types = type;
    this->node_itc_loans_types = loan_type;
    this->node_itc_copies = copies;
    this->node_itc_fees = fee;
}

Node_items_collection::Node_items_collection(string id, string title, string type, string loan_type, string copies, string fee, string genre) {
    this->node_itc_id = id;
    this->node_itc_title = title;
    this->node_itc_types = type;
    this->node_itc_loans_types = loan_type;
    this->node_itc_copies = copies;
    this->node_itc_fees = fee;
    this->node_itc_genre = genre;
}

string Node_items_collection::getID() {
    return this->node_itc_id;
}
string Node_items_collection::getTitle() {
    return this->node_itc_title;
}
string Node_items_collection::getType() {
    return this->node_itc_types;
}
string Node_items_collection::getLoantype() {
    return this->node_itc_loans_types;
}
string Node_items_collection::getCopies() {
    return this->node_itc_copies;
}
string Node_items_collection::getFee() {
    return this->node_itc_fees;
}
string Node_items_collection::getGenre() {
    return this->node_itc_genre;
}

void Node_items_collection::setId(string ID) {
    this->node_itc_id = ID;
}
void Node_items_collection::setTitle(string Title) {
    this->node_itc_title = Title;
}
void Node_items_collection::setType(string Type) {
    this->node_itc_types = Type;
}
void Node_items_collection::setLoanType(string loan_type) {
    this->node_itc_loans_types = loan_type;
}
void Node_items_collection::setCopies(string copies) {
    this->node_itc_copies = copies;
}
void Node_items_collection::setFee(string fee) {
    this->node_itc_fees = fee;
}
void Node_items_collection::setGenre(string Genre) {
    this->node_itc_genre = Genre;
}
void Node_items_collection::setAll(string ID, string Title, string Type, string loan_type, string copies, string fee, string genre) {
    this->node_itc_id = ID;
    this->node_itc_title = Title;
    this->node_itc_types = Type;
    this->node_itc_loans_types = loan_type;
    this->node_itc_copies = copies;
    this->node_itc_fees = fee;
    this->node_itc_genre = genre;
}