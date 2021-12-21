#include "VideoOnline.h"
#include <sstream>

void VideoOnline::read_data_customer(ifstream &filein, Customer &cs) {
    getline(filein, cs.cid, ',');
    getline(filein, cs.name, ',');
    getline(filein, cs.address, ',');
    getline(filein, cs.phone, ',');
    getline(filein, cs.hint_item, ',');
    stringstream items(cs.hint_item);
    items >> cs.total_item;
    getline(filein, cs.type);
}

void VideoOnline::read_data_items(ifstream &filein, Items_str &it) {
    getline(filein, it.i_id, '-');
    getline(filein, it.i_date);
}

void VideoOnline::read_items_collection(ifstream &filein, Items_Collection &itc){
    getline(filein, itc.itc_id, ',');
    getline(filein, itc.itc_name, ',');
    getline(filein, itc.itc_types, ',');
    getline(filein, itc.itc_loans_types, ',');
    getline(filein, itc.itc_copies, ',');
    getline(filein, itc.itc_fees, ',');
    getline(filein, itc.itc_genre);
}

void VideoOnline::insert_data_file_items(ifstream &inFile, vector<items_collection> &list_items){
    if (!inFile) {
        cout << "can't open file'" << endl;
    } else {
        while (!inFile.eof()) {
            Items_Collection itc;
            read_items_collection(inFile, itc);
            list_items.push_back(itc);
        }
    }
}

void VideoOnline::display(Items_Collection  &itc){
    cout << itc.itc_id << ' ';
    cout << itc.itc_name << ' ';
    cout << itc.itc_types << ' ';
    cout << itc.itc_loans_types << ' ';
    cout << itc.itc_copies << ' ';
    cout << itc.itc_fees << ' ';
    cout << itc.itc_genre << endl;
}

void VideoOnline::printf(const vector<Items_Collection> &its) {
    for (Items_Collection lius: its) {
        display(lius);
    }
}


void VideoOnline::insert_data_file(
        ifstream &inFile, LinkedList *cus_list, vector<customer> &cus_list_vector) {
    if (!inFile) {
        cout << "can't open file'" << endl;
    } else {
        LinkedList list_customer{};
        CreateList(list_customer);
        Node_customer *node;
        while (!inFile.eof()) {
            Customer cs;
            read_data_customer(inFile, cs);
            for (int i = 0; i < cs.total_item; i++) {
                Items_str its;
                read_data_items(inFile, its);
                cs.item_collection.push_back(its);
            }
            node = CreateNode(cs);
            AddTail(list_customer, node);
            cus_list_vector.push_back(cs);
        }
        *cus_list = list_customer;
    }
}

void VideoOnline::Search_customer(LinkedList &list) {
    string number;
    cout << "Enter Customer id: " << endl;
    getline(cin, number);
    Search_Customer(list, number);
}

void VideoOnline::Promote_Customer(LinkedList &list) {
    string number;
    cout << "Enter Customer id to promote: " << endl;
    getline(cin, number);
    promote(list, number);
    cout << "Sucess promote customer id: " << number << endl;
}

void VideoOnline::Update_customer_information(LinkedList &list, const string &file) {
    ofstream fileout(file);
    string number;
    cout << "Enter Customer id want to update: " << endl;
    getline(cin, number);
    Update_Customer_node(list, number);
    save_file_data(list, fileout);
    cout << "Customer at " << number << " Have been save for new Update" << endl;
    fileout.close();
}

void VideoOnline::save_file_data(LinkedList &list, ofstream &fileout) {
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
                    add_items(fileout, j);
                }
                node = node->next;
            }
        }
    } else {
        cout << "Can't Open file" << endl;
    }
}

void VideoOnline::Display_customer_in_type(const vector<customer> &ts) {
    string type;
    cout << "Enter the type of Customer to display: " << endl;
    cin >> type;
    display_customer_type(ts, type);
}
