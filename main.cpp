#include <iostream>
#include "LinkedList.h"
#include "VideoOnline.h"

using namespace std;

int main() {

    string file = "C:\\Users\\Asus\\Desktop\\videoRent\\Data\\customers.txt";
    ifstream inFile(file);
    // Create a linked list
    LinkedList list{};
    CreateList(list);

    LinkedListItems lists{};
    CreateList_items(lists);

    VideoOnline::get_data_collection(lists, list, inFile);

    inFile.close();

    return 0;
}