#ifndef VIDEORENT_VIDEOONLINE_H
#define VIDEORENT_VIDEOONLINE_H

#include <fstream>
#include <iostream>
#include <string>
#include "ADT/LinkedList.h"

using namespace std;

class VideoOnline {
public:
    static void read_data_customer(ifstream &filein, Customer &cs);

    static void read_data_items(ifstream &filein, Items_str &it);

    static void insert_data_file(ifstream &inFile, Node_customer *node, LinkedList *list_customer);

    static void Search_customer(LinkedList &list, Node_customer *node);

    static void Update_customer_information(LinkedList &list, Node_customer *node, string file);

    static void save_file_data(LinkedList &list, ofstream &fileout);

    static void Promote_Customer(LinkedList &list, Node_customer *node);
};


#endif