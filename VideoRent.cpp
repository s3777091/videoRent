#include "VideoRent.h"


void VideoRent::connect_data(
        ifstream &inFileCustomer, ifstream &inFileItems,
        CustomerList *cuslist, vector<Customer> &cus_list_vector,
        ItemList *list) {
    insert_customer_file(inFileCustomer, cuslist, cus_list_vector);
    insert_file_items(inFileItems, list);
}
