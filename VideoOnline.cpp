//
// Created by Asus on 12/11/2021.
//

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

void VideoOnline::read_data_items(ifstream &filein, Items_structer &it) {
    getline(filein, it.i_id, '-');
    getline(filein, it.i_date);
}


void VideoOnline::insert_data_file(ifstream &inFile, LinkedList *cus_list, LinkedListItems *items_list) {
    if (!inFile) {
        cout << "can't open file'" << endl;
    } else {
        LinkedList list_customer{};
        CreateList(list_customer);
        Node_customer *node;

        LinkedListItems lists_items{};
        CreateList_items(lists_items);
        Node_items *node_it;

        while (!inFile.eof()) {
            Customer cs;
            read_data_customer(inFile, cs);
            node = CreateNode(cs);
            AddTail(list_customer, node);
            for (int i = 0; i < cs.total_item; i++) {
                Items_structer its;
                read_data_items(inFile, its);
                node_it = Create_node_items(its);
                AddTailitems(lists_items, node_it);
            }
        }
        *items_list = lists_items;
        *cus_list = list_customer;
    }
}

