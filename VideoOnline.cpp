//
// Created by Asus on 12/11/2021.
//

#include "VideoOnline.h"
#include <sstream>

void VideoOnline::read_data_customer(ifstream &filein, Customer &cs){
    getline(filein, cs.cid, ',');
    getline(filein, cs.name, ',');
    getline(filein, cs.address, ',');
    getline(filein, cs.phone, ',');
    getline(filein, cs.hint_item, ',');
    stringstream items(cs.hint_item);
    items >> cs.total_item;
    getline(filein, cs.type);
}

void VideoOnline::read_data_items(ifstream &filein, Items_structer &it){
    getline(filein, it.i_id, '-');
    getline(filein, it.i_date);
}

void VideoOnline::get_data_collection(
        LinkedListItems list_items, LinkedList list,ifstream &inFile){
    if (!inFile) {
      cout << "can't open file'" << endl;
    } else {
        Node_items* nodeItems;
        Node_customer* node;
        while (!inFile.eof()) {
            Customer cs;
            read_data_customer(inFile, cs);
            node = CreateNode(cs);
            AddTail(list, node);
            for (int i = 0; i < cs.total_item; i++) {
                Items_structer its;
                read_data_items(inFile, its);
                nodeItems = Create_node_items(its);
                AddTailitems(list_items, nodeItems);
            }
        }
        PrintList(list);
    }
}
