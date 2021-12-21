#include <iostream>
#include "VideoOnline.h"

using namespace std;

int main() {
    string file = R"(C:\Users\Asus\Desktop\School\videoRent\Data\items.txt)";
    ifstream inFile(file);
//    LinkedList list_customer{};
//    vector<customer> vst;
//    VideoOnline::insert_data_file(inFile, &list_customer, vst);
//    VideoOnline::Display_customer_in_type(vst);


    Items_Collection itc;
    vector<items_collection> itlist;
    VideoOnline::insert_data_file_items(inFile, itlist);
    VideoOnline::printf(itlist);


    inFile.close();
    return 0;
}