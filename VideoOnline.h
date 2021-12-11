
#ifndef VIDEORENT_VIDEOONLINE_H
#define VIDEORENT_VIDEOONLINE_H

#include <fstream>
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;


class VideoOnline {
public:
    static void get_data_collection(LinkedListItems list_items, LinkedList list,ifstream &inFile);
    static void read_data_customer(ifstream &filein, Customer &cs);
    static void read_data_items(ifstream &filein, Items_structer &it);
};


#endif //VIDEORENT_VIDEOONLINE_H
