#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <sstream>

using namespace std;

typedef struct items {
    string i_id;
    string i_date;
} Item;

typedef struct customer {
    string cid;
    string name;
    string address;
    string phone;
    string hint_item;
    string type;
    int total_item{};
    vector<items> item_collection;
} Customer;

void get_information_customer(ifstream &filein, Customer &cs) {
    getline(filein, cs.cid, ',');
    getline(filein, cs.name, ',');
    getline(filein, cs.address, ',');
    getline(filein, cs.phone, ',');
    getline(filein, cs.hint_item, ',');
    stringstream items(cs.hint_item);
    items >> cs.total_item;
    getline(filein, cs.type);
}

void get_information_items_in_customer(ifstream &filein, Item &it) {
    getline(filein, it.i_id, '-');
    getline(filein, it.i_date);
}

void read_items_collection_of_customer(ifstream &filein, vector<customer> &list_customer) {
    while (!filein.eof()) {
        Customer cs;
        get_information_customer(filein, cs);
        for (int i = 0; i < cs.total_item; i++) {
            Item its;
            get_information_items_in_customer(filein, its);
            cs.item_collection.push_back(its);
        }
        list_customer.push_back(cs);
    }
}

void printf_customer(const Customer &cs) {
    cout << "List Customer";
    cout << "\nCustomer id: " << cs.cid;
    cout << "\nCustomer name: " << cs.name;
    cout << "\nCustomer address: " << cs.address;
    cout << "\nCustomer phone number: " << cs.phone;
    cout << "\nCustomer total hint items: " << cs.hint_item;
    cout << "\nCustomer type: " << cs.type << endl;
    cout << "====================================" << endl;
}

void printf_items_data(const Item &its) {
    cout << "items id: " << its.i_id << "-" << its.i_date << endl;
    cout << "====================================" << endl;
}


void add_customer_data(ofstream &outfile, Customer &cs) {
    cout << "\nEnter customer id: ";
    getline(cin, cs.cid);
    cout << "\nEnter customer name: ";
    getline(cin, cs.name);
    cout << "\nEnter customer address: ";
    getline(cin, cs.address);
    cout << "\nEnter customer phone number: ";
    getline(cin, cs.phone);
    cout << "\nEnter customer hint items: ";
    getline(cin, cs.hint_item);
    cout << "\nEnter customer type: ";
    getline(cin, cs.type);
    stringstream items(cs.hint_item);
    items >> cs.total_item;
    outfile << '\n' + cs.cid + ',' + cs.name + ',' + cs.address + ',' + cs.phone + ',' + cs.hint_item + ',' + cs.type;
}


void add_items_data(ofstream &outfile, Item &it) {
    cout << "Enter hint items: \n";
    getline(cin, it.i_id);
    cout << "Enter hint items date: \n";
    getline(cin, it.i_date);
    outfile << '\n' + it.i_id + '-' + it.i_date;
}

void read_items_collections(ofstream &outfile, vector<customer> &list_customer) {
    Customer cs;
    add_customer_data(outfile, cs);
    if (cs.total_item > 0) {
        for (int i = 0; i < cs.total_item; i++) {
            Item its;
            add_items_data(outfile, its);
        }
    }
    outfile.close();
}

void printf(const vector<Customer> &cs) {
    for (auto &c: cs) {
        printf_customer(c);
        for (auto &j: c.item_collection) {
            printf_items_data(j);
        }
    }
}


int main() {
    string customer = R"(C:\Users\Asus\Desktop\videoRent\Data\customers.txt)";

    cout << "==== Video online rent shop ====" << endl;

    ifstream filein;
    filein.open(customer, ios_base::in);
    vector<Customer> customer_collection;
    read_items_collection_of_customer(filein, customer_collection);
    printf(customer_collection);


    ofstream outfile;
    outfile.open(customer, ios::app);
    read_items_collections(outfile, customer_collection);
    filein.close();
    return 0;
}