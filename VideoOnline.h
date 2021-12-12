
#ifndef VIDEORENT_VIDEOONLINE_H
#define VIDEORENT_VIDEOONLINE_H

#include <fstream>
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;


class VideoOnline {
public:
    static void read_data_customer(ifstream &filein, Customer &cs);
    static void read_data_items(ifstream &filein, Items_structer &it);
    static void insert_data_file(ifstream &inFile, LinkedList * list_customer, LinkedListItems * list_its);
};


#endif //VIDEORENT_VIDEOONLINE_H
