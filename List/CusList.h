#ifndef VIDEORENT_CUSLIST_H
#define VIDEORENT_CUSLIST_H


#include "../ADT/Customer.h"

class CustomerList {
public:
    static Node_customer *CreateNode(Customer &cs);

    static void CreateList(CustomerList &l);

    static void AddTail(CustomerList &l, Node_customer *node);

    static void PrintList(CustomerList l);

    Node_customer *head;
    Node_customer *tail;

    static void showNode(Node_customer *node);

    static void printf_items_data(Items_str &its);

    static Node_customer *Update_Customer_node(CustomerList &l, const int &customer_id);

    static void add_items(ofstream &fileout, Items_str &its);

    static Node_customer *promote(CustomerList l, const int &number_id);

    static void PrintListAllCustomer(CustomerList l);

    static void printfAll(Node_customer *node);

    static void display_customer_type(const vector <Customer> &cus_list, const string &type);

    static Node_customer *Search_Customer(CustomerList l, const int &number_id);

    static Node_customer *addNew(CustomerList &list);
};


#endif //VIDEORENT_CUSLIST_H
