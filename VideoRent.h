#ifndef VIDEORENT_VIDEORENT_H
#define VIDEORENT_VIDEORENT_H


#include "Function/CusFunc.h"
#include "Function/ItmFunc.h"

class VideoRent : CusFunc, ItmFunc{
public:
    static void connect_data(ifstream &inFile, ifstream  &inFileItems,
                             CustomerList *cuslist, vector<Customer> &cus_list_vector,
                             ItemList *list);
};

#endif;
