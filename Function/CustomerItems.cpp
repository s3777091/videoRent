//
// Created by Asus on 12/24/2021.
//

#include "CustomerItems.h"


void CustomerItems::read_items_collection(ifstream &filein, items_collection &itc) {
    getline(filein, itc.itc_id, ',');
    getline(filein, itc.itc_name, ',');
    getline(filein, itc.itc_types, ',');
    getline(filein, itc.itc_loans_types, ',');
    getline(filein, itc.itc_copies, ',');
    getline(filein, itc.itc_fees, ',');
    getline(filein, itc.itc_genre);
}

void CustomerItems::insert_file_items(ifstream &inFile, ItemsList *list) {
    if (!inFile) {
        cout << "can't open file'" << endl;
    } else {
        ItemsList list_items{};
        ItemsList::CreateListItems(list_items);
        Node_items_collection *node;
        while (!inFile.eof()) {
            items_collection itc;
            read_items_collection(inFile, itc);
            node = ItemsList::createNode_items(itc);
            ItemsList::AddTailItems(list_items, node);
        }

        *list = list_items;
    }
}
