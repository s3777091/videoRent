#ifndef LinkedList_hpp
#define LinkedList_hpp
using namespace std;

typedef struct items {
    string i_id;
    string i_date;
} Items_structer;

typedef struct customer {
    string cid;
    string name;
    string address;
    string phone;
    string hint_item;
    string type;
    int total_item{};
} Customer;


struct Node_customer {
    string customer_id;
    string customer_name;
    string customer_address;
    string customer_phone;
    string customer_hint_item;
    string customer_type;
    Node_customer* next;
};

struct Node_items{
    string items_id;
    string items_date;
    Node_items* next_items;
};

struct LinkedList
{
    Node_customer* head;
    Node_customer* tail;
};

struct LinkedListItems
{
    Node_items* head_items;
    Node_items* tail_items;
};

Node_customer* CreateNode(Customer &cs);
void CreateList(LinkedList& l);
void AddTail(LinkedList& l, Node_customer* node);
void PrintList(LinkedList l);

Node_items * Create_node_items(Items_structer &its);
void CreateList_items(LinkedListItems& l);
void AddTailitems(LinkedListItems &l, Node_items *nodeitems);
void PrintList_items(LinkedListItems l);

#endif