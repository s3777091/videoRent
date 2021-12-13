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


void VideoOnline::insert_data_file(ifstream &inFile, Node_customer *node, LinkedList *cus_list) {
    if (!inFile) {
        cout << "can't open file'" << endl;
    } else {
        LinkedList list_customer{};
        CreateList(list_customer);
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
        }
        *cus_list = list_customer;
    }
}
