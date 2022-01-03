#ifndef VIDEORENT_ITEMLIST_H
#define VIDEORENT_ITEMLIST_H
#include "../ADT/Items.h"

class ItemList {
public:
    Node_items_collection *head_items;
    Node_items_collection *tail_items;

    static Node_items_collection *createNode_items(items_collection &itc);
    static void CreateListItems(ItemList &l);
    static void AddTailItems(ItemList &l, Node_items_collection *node);

    static void showList(Node_items_collection *node);

    static void PrintListItems(ItemList l);

    static Node_items_collection *addNewItems(ItemList &list);

    static Node_items_collection *Update_Items_node(ItemList &l, const int &number_id);
};

#endif
