#ifndef VIDEORENT_ITMFUNC_H
#define VIDEORENT_ITMFUNC_H

#include "../ADT/Items.h"
#include "../List/ItemList.h"
#include "../ADT/Items.h"
#include "../List/ItemList.h"

class ItmFunc {
    static void read_items_collection(ifstream &filein, items_collection &itc);

protected:
    static void insert_file_items(ifstream &inFile, ItemList *list);

public:
    static void AddNewItems(ItemList &list, string file);

    static void save_file_data(ItemList &list, ofstream &fileout);

    static void Update_Items_information(const string &file, ItemList &list);
};


#endif
