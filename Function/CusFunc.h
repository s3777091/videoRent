#ifndef VIDEORENT_CUSFUNC_H
#define VIDEORENT_CUSFUNC_H

#include <sstream>

#include <fstream>
#include <iostream>
#include <string>
#include "../ADT/Customer.h"
#include "../List/CusList.h"
class CusFunc {
public:
    static void read_data_customer(ifstream &filein, Customer &cs);

    static void read_data_items(ifstream &filein, Items_str &it);

    static void insert_customer_file(ifstream &inFile, CustomerList *cus_list, vector<Customer> &cus_list_vector);

    static void Update_customer_information(const string &file, CustomerList &list);

    static void save_file_data(CustomerList &list, ofstream &fileout);
    static void Promote_Customer(const string &file, CustomerList &list);

    static void Display_customer_in_type(const vector<Customer> &ts);

    static void Search_customer(CustomerList &list);

    static void AddNewCustomer(CustomerList &list, string file);

};
#endif
