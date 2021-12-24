#include "LinkedList.h"
using namespace std;

Node_customer *
LinkedList::CreateNode(Customer &cs) {
    auto *node = new Node_customer(cs);
    node->next = nullptr;
    return node;
}

void LinkedList::CreateList(LinkedList &l) {
    l.head = nullptr;
    l.tail = nullptr;
}

void LinkedList::AddTail(LinkedList &l, Node_customer *node) {
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void LinkedList::printf_items_data(Items_str &its) {
    cout << "items id: " << its.i_id << "-" << its.i_date << endl;
    cout << "====================================" << endl;
}

void LinkedList::showNode(Node_customer *node) {
    cout << node->customer_id << ' ';
    cout << node->customer_name << ' ';
    cout << node->customer_address << ' ';
    cout << node->customer_phone << ' ';
    cout << node->customer_hint_item << ' ';
    cout << node->customer_type << '\n';
    for (auto &j: node->customer_item_collection) {
        LinkedList::printf_items_data(j);
    }
}

void LinkedList::PrintList(LinkedList l) {
    if (l.head != nullptr) {
        Node_customer *node = l.head;
        while (node != nullptr) {
            LinkedList::showNode(node);
            node = node->next;
        }
    }
}

void LinkedList::add_items(ofstream &fileout, Items_str &its) {
    fileout << its.i_id << '-' << its.i_date << "\n";
}

int to_int(const string &number_id) {
    string string_number = number_id.substr(1, 4);
    stringstream exchange_number(string_number);
    int x = 0;
    exchange_number >> x;
    return x;
}

Node_customer *LinkedList::Search_Customer(LinkedList l, const string &number_id) {
    Node_customer *new_node;
    new_node = l.head;
    int i = 0;
    int number = to_int(number_id) - 1;
    while (new_node != nullptr && i != number) {
        new_node = new_node->next;
        i++;
    }
    if (i == number && new_node != nullptr) {
        LinkedList::showNode(new_node);
    }
    return nullptr;
}


Node_customer *LinkedList::promote(LinkedList l, const string &number_id) {
    Node_customer *new_node;
    new_node = l.head;
    int i = 0;
    int number = to_int(number_id) - 1;
    while (new_node != nullptr && i != number) {
        new_node = new_node->next;
        i++;
    }
    if (i == number && new_node != nullptr) {
        if (new_node->customer_type == "VIP") {
            cout << "Highest Customer Type can't Promote" << endl;
        } else if (new_node->customer_type == "Regular") {
            string to_vip = "VIP";
            new_node->customer_type = to_vip;
        } else if (new_node->customer_type == "Guest") {
            string to_regular = "Regular";
            new_node->customer_type = to_regular;
        }
    }
    return nullptr;
}


Node_customer *LinkedList::Update_Customer_node(LinkedList &l, const string &number_id) {
    Node_customer *new_node;
    new_node = l.head;
    int i = 0;
    int number = to_int(number_id) - 1;
    while (new_node != nullptr && i != number) {
        new_node = new_node->next;
        i++;
    }
    if (i == number && new_node != nullptr) {
        auto *new_customer = new Customer;
        cout << "Enter customer name to update: " << endl;
        getline(cin, new_customer->name);
        new_node->customer_name = new_customer->name;

        cout << "Enter customer address to update: " << endl;
        getline(cin, new_customer->address);
        new_node->customer_address = new_customer->address;

        cout << "Enter customer Phone to update: " << endl;
        getline(cin, new_customer->phone);
        new_node->customer_phone = new_customer->phone;
    }
    return nullptr;
}


void LinkedList::display_customer_type(const vector<Customer> &cus_list, const string &type) {
    for (auto &cus: cus_list) {
        if (stricmp(cus.type.c_str(), type.c_str()) == 0) {
            cout << cus.cid << ' ';
            cout << cus.name << ' ';
            cout << cus.phone << ' ';
            cout << cus.address << ' ';
            cout << cus.hint_item << '\n';
            for (const Items_str &list_items: cus.item_collection) {
                cout << list_items.i_id << '-' << list_items.i_date << endl;
                cout << "====================================" << endl;
            }
        }
    }
}