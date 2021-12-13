#include <iostream>
#include "VideoOnline.h"

using namespace std;

int main() {

    string file = R"(C:\Users\Asus\Desktop\School\videoRent\Data\customers.txt)";
    ifstream inFile(file);
    // Create a linked list
    LinkedList list_customer{};

    auto *node = new Node_customer;

    VideoOnline::insert_data_file(inFile, node, &list_customer);

    PrintList(list_customer);
    inFile.close();
    return 0;
}