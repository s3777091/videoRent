#include "CusFunc.h"

void CusFunc::read_data_customer(ifstream &filein, Customer &cs) {
    getline(filein, cs.cid, ',');
    getline(filein, cs.name, ',');
    getline(filein, cs.address, ',');
    getline(filein, cs.phone, ',');
    getline(filein, cs.hint_item, ',');
    stringstream items(cs.hint_item);
    items >> cs.total_item;
    getline(filein, cs.type);
}

void CusFunc::read_data_items(ifstream &filein, Items_str &it) {
    getline(filein, it.i_id, '-');
    getline(filein, it.i_date);
}

void CusFunc::insert_customer_file(
        ifstream &inFile, CustomerList *cus_list, vector<Customer> &cus_list_vector) {
    if (!inFile) {
        cout << "can't open file'" << endl;
    } else {
        CustomerList list_customer{};
        CustomerList::CreateList(list_customer);
        Node_customer *node;
        while (!inFile.eof()) {
            Customer cs;
            read_data_customer(inFile, cs);
            for (int i = 0; i < cs.total_item; i++) {
                Items_str its;
                read_data_items(inFile, its);
                cs.item_collection.push_back(its);
            }
            node = CustomerList::CreateNode(cs);
            CustomerList::AddTail(list_customer, node);
            cus_list_vector.push_back(cs);
        }
        *cus_list = list_customer;
    }
}

void CusFunc::AddNewCustomer(CustomerList &list, string file) {
    ofstream fileout(file);
    CustomerList::addNew(list);
    CustomerList::PrintList(list);
    bool quit = false;
    do {
        cout << "1. Save Data? " << endl;
        cout << "2. Quit" << endl;
        cout << "Please input an option: ";
        int confirm;
        cin >> confirm;
        switch (confirm) {
            case 1:
                save_file_data(list, fileout);
                break;
            case 2:
                cout << "Nothing to save" << endl;
                quit = true;
                break;
            default:
                cout << "invalid selection" << endl;
                break;
        }
    } while (!quit);
    fileout.close();
}


void CusFunc::save_file_data(CustomerList &list, ofstream &fileout) {
    if (fileout.is_open()) {
        if (list.head != nullptr) {
            Node_customer *node = list.head;
            while (node != nullptr) {
                fileout << node->customer_id << ',';
                fileout << node->customer_name << ',';
                fileout << node->customer_address << ',';
                fileout << node->customer_phone << ',';
                fileout << node->customer_hint_item << ',';
                fileout << node->customer_type << '\n';
                for (auto &j: node->customer_item_collection) {
                    CustomerList::add_items(fileout, j);
                }
                node = node->next;
            }
        }
    } else {
        cout << "Can't Open file" << endl;
    }
}

void CusFunc::Update_customer_information(const string &file, CustomerList &list) {
    CustomerList::PrintList(list);
    ofstream fileout(file);
    int number;
    cout << "Enter Customer id want to update: ";
    cin >> number;
    cout << '\n' << endl;

    CustomerList::Update_Customer_node(list, number);
    CustomerList::PrintList(list);
    bool quit = false;
    do {
        cout << "1. Save Data? " << endl;
        cout << "2. Quit" << endl;
        cout << "Please input an option: ";
        int confirm;
        cin >> confirm;
        switch (confirm) {
            case 1:
                save_file_data(list, fileout);
                quit = true;
                break;
            case 2:
                cout << "Nothing to save" << endl;
                quit = true;
                break;
            default:
                cout << "invalid selection" << endl;
                break;
        }
    } while (!quit);
    fileout.close();
}

void CusFunc::Promote_Customer(const string &file, CustomerList &list) {
    int number;
    ofstream fileout(file);
    CustomerList::PrintList(list);
    cout << "Enter Customer id to promote: " << endl;
    cin >> number;
    CustomerList::promote(list, number);
    CustomerList::PrintList(list);
    cout << "Success promote customer id: " << number << endl;
    bool quit = false;
    do {
        cout << "1. Save Data? " << endl;
        cout << "2. Quit" << endl;
        cout << "Please input an option: ";
        int confirm;
        cin >> confirm;
        switch (confirm) {
            case 1:
                save_file_data(list, fileout);
                quit = true;
                break;
            case 2:
                cout << "Nothing to save" << endl;
                quit = true;
                break;
            default:
                cout << "invalid selection" << endl;
                break;
        }
    } while (!quit);
    fileout.close();
}

void CusFunc::Display_customer_in_type(const vector<Customer> &ts) {
    char type[20];
    cout << "Enter the type of Customer to display: " << endl;
    cin >> type;
    CustomerList::display_customer_type(ts, type);
}

void CusFunc::Search_customer(CustomerList &list) {
    int number;
    cout << "Enter Customer id: " << endl;
    cin >> number;
    CustomerList::Search_Customer(list, number);
}