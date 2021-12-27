#include "ItemLinkedList.h"
#pragma warning(disable:4996)

using namespace std;

Node_item*
ItemCreateNode(Item& item) {
    auto* node = new Node_item;
    node->item_id = item.id;
    node->item_title = item.title;
    node->item_rentaltype = item.rentaltype;
    node->item_loantype = item.loantype;
    node->item_stock = item.stock;
    node->item_fee = item.fee;
    node->item_status = item.status;
    node->next = nullptr;
    return node;
}

void ItemCreateList(ItemLinkedList& l) {
    l.head = nullptr;
    l.tail = nullptr;
}

void ItemAddTail(ItemLinkedList& l, Node_item* node) {
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
    }
    else {
        l.tail->next = node;
        l.tail = node;
    }
}

void PrintItemList(ItemLinkedList l) {
    if (l.head != nullptr) {
        Node_item* node = l.head;
        while (node != nullptr) {
            cout << node->item_id << ' ';
            cout << node->item_title << ' ';
            cout << node->item_rentaltype << ' ';
            cout << node->item_loantype << ' ';
            cout << node->item_stock << ' ';
            cout << node->item_fee << ' ';
            cout << node->item_status << '\n';
            node = node->next;
        }
    }
}

void add_items(ofstream& fileout, Item& item) {
    fileout << item.id <<','<<item.title<<','<<item.rentaltype<<','<<item.loantype<<','<<item.stock<<','<<item.fee<<','<<item.status << "\n";
}


int item_to_int(const string& item_id) {
    string string_number = item_id.substr(1, 3) + item_id.substr(4, 4);

    stringstream exchange_number(string_number);
    int x = 0;
    exchange_number >> x;
    return x;
}



Node_item* Search_item(ItemLinkedList l, const string& item_id) {
    Node_item* new_node;
    new_node = l.head;
    int i = 0;
    int number = item_to_int(item_id) - 1;
    while (new_node != nullptr && i != number) {
        new_node = new_node->next;
        i++;
    }
    if (i == number && new_node != nullptr) {
        cout << new_node->item_id << ' ';
        cout << new_node->item_title << ' ';
        cout << new_node->item_rentaltype << ' ';
        cout << new_node->item_loantype << ' ';
        cout << new_node->item_stock << ' ';
        cout << new_node->item_fee << ' ';
        cout << new_node->item_status << '\n';
    }
    return nullptr;
}


int ItemLength(ItemLinkedList l) {
    int count = 0;
    Node_item* node = l.head;
    while (node != nullptr) {
        count++;
        node = node->next;
    }
    return count;
}

Node_item* Update_item_node(ItemLinkedList& l, const string& item_id) {
    Node_item* new_item_node;
    new_item_node = l.head;
    int i = 0;
    int number = item_to_int(item_id) - 1;
    while (new_item_node != nullptr && i != number) {
        new_item_node = new_item_node->next;
        i++;
    }
    if (i == number && new_item_node != nullptr) {
        auto* new_item = new Item;
        cout << "Enter item tile to update: " << endl;
        getline(cin, new_item->title);
        new_item_node->item_title = new_item->title;

        cout << "Enter item status to update: " << endl;
        getline(cin, new_item->status);
        new_item_node->item_status= new_item->status;
    }
    return nullptr;
}


