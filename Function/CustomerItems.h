//
// Created by Asus on 12/24/2021.
//

#ifndef VIDEOONLINE_H_CUSTOMERITEMS_H
#define VIDEOONLINE_H_CUSTOMERITEMS_H

#include <fstream>
#include <iostream>
#include <string>
#include "../ADT/ItemsList.h"

using namespace std;
class CustomerItems {

public:
    static void read_items_collection(ifstream &filein, items_collection &itc);
    static void insert_file_items(ifstream &inFile, ItemsList *list);
    static void search_items_id(ItemsList& list);
    //static void search_items_title(ItemsList& list);
};


#endif //VIDEOONLINE_H_CUSTOMERITEMS_H
