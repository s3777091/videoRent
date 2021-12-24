#include <iostream>
#include "Function/VideoCustomer.h"
#include "Function/CustomerItems.h"

using namespace std;

int main() {
    string customer = R"(C:\Users\Asus\Desktop\School\videoRent\Data\customers.txt)";
//    ifstream inFile(customer);
//    LinkedList list_customer{};
//    vector<Customer> vst;
//    VideoCustomer::insert_data_file(inFile, &list_customer, vst);
//    VideoCustomer::Display_customer_in_type(vst);

    string items_file = R"(C:\Users\Asus\Desktop\School\videoRent\Data\items.txt)";
    ifstream openFile(items_file);

    ItemsList items{};
    CustomerItems::insert_file_items(openFile, &items);
    ItemsList::PrintListItems(items);


    openFile.close();
    return 0;
}