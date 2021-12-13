#ifndef VIDEORENT_VIDEOONLINE_H
#define VIDEORENT_VIDEOONLINE_H

#include <fstream>
#include <iostream>
#include <string>
#include "ADT/LinkedList.h"

using namespace std;


class VideoOnline {
public:
    static void read_data_customer(ifstream &filein, Customer &cs);
    static void read_data_items(ifstream &filein, Items_str &it);
    static void insert_data_file(ifstream &inFile,Node_customer *node, LinkedList * list_customer);
};


#endif //VIDEORENT_VIDEOONLINE_H