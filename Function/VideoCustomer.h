#ifndef VIDEORENT_VIDEOONLINE_H
#define VIDEORENT_VIDEOONLINE_H

#include <fstream>
#include <iostream>
#include <string>
#include "../ADT/LinkedList.h"
#include "../ADT/ItemsList.h"

using namespace std;

class VideoCustomer {
public:
    static void read_data_customer(ifstream &filein, Customer &cs);
    static void read_data_items(ifstream &filein, Items_str &it);
    static void insert_data_file(ifstream &inFile, LinkedList *list_customer,vector<Customer> &list_vector);
    static void Search_customer(LinkedList &list);
    static void Update_customer_information(LinkedList &list, const string& file);
    static void save_file_data(LinkedList &list, ofstream &fileout);
    static void Promote_Customer(LinkedList &list);
    static void Display_customer_in_type(const vector<Customer>& ts);
};

#endif