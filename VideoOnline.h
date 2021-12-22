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

    static void insert_data_file(ifstream &inFile, LinkedList *list_customer,vector<customer> &list_vector);

    static void Search_customer(LinkedList &list);

    static void Update_customer_information(LinkedList &list, const string& file);

    static void save_file_data(LinkedList &list, ofstream &fileout);

    static void Promote_Customer(LinkedList &list);

    static void Display_customer_in_type(const vector<customer>& ts);

    static void read_items_collection(ifstream &filein, Items_Collection &itc);

    static void display(Items_Collection &itc);

    static void insert_data_file_items(ifstream &inFile, vector<items_collection> &list_items);

    static void printf(const vector<Items_Collection> &its);
};

#endif