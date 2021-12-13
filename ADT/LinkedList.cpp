#include "LinkedList.h"
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

void add_items(ofstream &fileout, Items_str &its){
    fileout << its.i_id << '-' << its.i_date << "\n";
}


int to_int(const string& number_id) {
    string string_number = number_id.substr(1, 4);

    stringstream exchange_number(string_number);
    int x = 0;
    exchange_number >> x;
    return x;
}

Node_customer *Search_Customer(LinkedList l, Node_customer *node,const string& number_id) {
    node = l.head;
    int i = 0;
    int number = to_int(number_id) - 1;
    while (node != nullptr && i != number) {
        node = node->next;
        i++;
    }
    if (i == number && node != nullptr) {
        cout << node->customer_id << ' ';
        cout << node->customer_name << ' ';
        cout << node->customer_address << ' ';
        cout << node->customer_phone << ' ';
        cout << node->customer_hint_item << ' ';
        cout << node->customer_type << '\n';
        for (auto &j: node->customer_item_collection) {
            printf_items_data(j);
        }
    }
    return nullptr;
}


Node_customer *promote(LinkedList l, Node_customer *node,const string& number_id) {
    node = l.head;
    int i = 0;
    int number = to_int(number_id) - 1;
    while (node != nullptr && i != number) {
        node = node->next;
        i++;
    }
    if (i == number && node != nullptr) {
        if(node->customer_type == "VIP"){
            cout << "Highest Customer Type can't Promote" << endl;
        } else if(node->customer_type == "Regular"){
            string to_vip = "VIP";
            node->customer_type = to_vip;
        } else if(node->customer_type == "Guest"){
            string to_regular = "Regular";
            node->customer_type = to_regular;
        }
    }
    return nullptr;
}

Node_customer *Update_Customer_node(LinkedList &l, Node_customer *node,const string& number_id) {
    node = l.head;
    int i = 0;
    int number = to_int(number_id) - 1;
    while (node != nullptr && i != number) {
        node = node->next;
        i++;
    }
    if (i == number && node != nullptr) {
        auto * new_customer = new Customer;
        cout << "Enter customer name to update: " << endl;
        getline(cin, new_customer->name);
        node->customer_name = new_customer->name;

        cout << "Enter customer address to update: " << endl;
        getline(cin, new_customer->address);
        node->customer_address = new_customer->address;

        cout << "Enter customer Phone to update: " << endl;
        getline(cin, new_customer->phone);
        node->customer_phone = new_customer->phone;
    }
    return nullptr;
}