#include "VideoCustomer.h"
#include <sstream>

void VideoCustomer::read_data_customer(ifstream &filein, Customer &cs) {
    getline(filein, cs.cid, ',');
    getline(filein, cs.name, ',');
    getline(filein, cs.address, ',');
    getline(filein, cs.phone, ',');
    getline(filein, cs.hint_item, ',');
    stringstream items(cs.hint_item);
    items >> cs.total_item;
    getline(filein, cs.type);
}

void VideoCustomer::read_data_items(ifstream &filein, Items_str &it) {
    getline(filein, it.i_id, '-');
    getline(filein, it.i_date);
}

void VideoCustomer::insert_data_file(
        ifstream &inFile, LinkedList *cus_list, vector<Customer> &cus_list_vector) {
    if (!inFile) {
        cout << "can't open file'" << endl;
    } else {
        LinkedList list_customer{};
        LinkedList::CreateList(list_customer);
        Node_customer *node;
        while (!inFile.eof()) {
            Customer cs;
            read_data_customer(inFile, cs);
            for (int i = 0; i < cs.total_item; i++) {
                Items_str its;
                read_data_items(inFile, its);
                cs.item_collection.push_back(its);
            }
            node = LinkedList::CreateNode(cs);
            LinkedList::AddTail(list_customer, node);
            cus_list_vector.push_back(cs);
        }
        *cus_list = list_customer;
    }
}

void VideoCustomer::Search_customer(LinkedList &list) {
    string number;
    cout << "Enter Customer id: " << endl;
    getline(cin, number);
    LinkedList::Search_Customer(list, number);
}

void VideoCustomer::Promote_Customer(LinkedList &list) {
    string number;
    cout << "Enter Customer id to promote: " << endl;
    getline(cin, number);
    LinkedList::promote(list, number);
    cout << "Success promote customer id: " << number << endl;
}

void VideoCustomer::Update_customer_information(LinkedList &list, const string &file) {
    ofstream fileout(file);
    string number;
    cout << "Enter Customer id want to update: " << endl;
    getline(cin, number);
    LinkedList::Update_Customer_node(list, number);
    save_file_data(list, fileout);
    cout << "Customer at " << number << " Have been save for new Update" << endl;
    fileout.close();
}

void VideoCustomer::save_file_data(LinkedList &list, ofstream &fileout) {
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
                    LinkedList::add_items(fileout, j);
                }
                node = node->next;
            }
        }
    } else {
        cout << "Can't Open file" << endl;
    }
}

void VideoCustomer::Display_customer_in_type(const vector<Customer> &ts) {
    string type;
    cout << "Enter the type of Customer to display: " << endl;
    cin >> type;
    LinkedList::display_customer_type(ts, type);
}
