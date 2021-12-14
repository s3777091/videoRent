#include <iostream>
#include "VideoOnline.h"

using namespace std;

int main() {
    string file = R"(C:\Users\Asus\Desktop\School\videoRent\Data\customers.txt)";
    ifstream inFile(file);
    LinkedList list_customer{};
    vector<customer> vst;
    VideoOnline::insert_data_file(inFile, &list_customer, vst);
    VideoOnline::Display_customer_in_type(vst);
    inFile.close();
    return 0;
}