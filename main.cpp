#include <iostream>
#include "LinkedList.h"
#include "VideoOnline.h"

using namespace std;

int main() {

    string file = R"(C:\Users\Asus\Desktop\videoRent\Data\customers.txt)";
    ifstream inFile(file);
    // Create a linked list
    LinkedList list_customer{};
    LinkedListItems list_Items{};

    VideoOnline::insert_data_file(inFile, &list_customer, &list_Items);

    PrintList(list_customer);

    PrintList_items(list_Items);
    inFile.close();
    return 0;
}