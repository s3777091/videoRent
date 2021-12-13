#include <iostream>
#include "VideoOnline.h"

using namespace std;

int main() {
    string file = R"(C:\Users\Asus\Desktop\School\videoRent\Data\customers.txt)";
    ifstream inFile(file);
    LinkedList list_customer{};
    auto *node = new Node_customer;
    VideoOnline::insert_data_file(inFile, node, &list_customer);
    VideoOnline::Search_customer(list_customer, node);
    inFile.close();
    return 0;
}