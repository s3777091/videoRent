#include "ItemList.h"

Node_items_collection *ItemList::createNode_items(items_collection &itc) {
    auto *node = new Node_items_collection(itc);
    node->next = nullptr;
    return node;
}

void ItemList::CreateListItems(ItemList &l) {
    l.head_items = nullptr;
    l.tail_items = nullptr;
}

void ItemList::AddTailItems(ItemList &l, Node_items_collection *node) {
    if (l.head_items == nullptr) {
        l.head_items = node;
        l.tail_items = node;
    } else {
        l.tail_items->next = node;
        l.tail_items = node;
    }
}

void ItemList::showList(Node_items_collection *node) {
    cout << node->node_itc_id << ',';
    cout << node->node_itc_name << ',';
    cout << node->node_itc_types << ',';
    cout << node->node_itc_loans_types << ',';
    cout << node->node_itc_copies << ',';
    cout << node->node_itc_fees << ',';
    cout << node->node_itc_genre << endl;
}

void ItemList::PrintListItems(ItemList l) {
    if (l.head_items != nullptr) {
        Node_items_collection *node = l.head_items;
        while (node != nullptr) {
            ItemList::showList(node);
            node = node->next;
        }
    }
}

Node_items_collection *ItemList::addNewItems(ItemList &list) {
    Node_items_collection *node;
    node = list.head_items;
    items_collection its;
    int items_id, i = 0;
    cout << "Enter new Items Id: " << endl;
    cin >> items_id;
    while (node != nullptr && i != items_id - 1) {
        node = node->next;
        i++;
    }
    if (i == items_id - 1 && node != nullptr) {
        cout << "Items Id already existing !" << endl;
    } else {
        int x = items_id;
        string s;
        stringstream ss;
        string year;
        string name;
        string loans_type;
        string stock;
        string price;
        cout << "what is items types: " << endl;
        bool quit = false;
        string genre;
        do {
            cout << "1. Game " << endl;
            cout << "2. Record" << endl;
            cout << "3. DVD" << endl;
            cout << "5. Quit" << endl;
            cout << "Please input an option: ";
            int confirm;
            cin >> confirm;
            switch (confirm) {
                case 1:
                    its.itc_types = "Game";
                    cout << "Enter year of this items: " << endl;
                    cin >> year;
                    ss << x;
                    ss >> s;
                    its.itc_id = "I00" + s + "-" + year;
                    cout << "Enter name of this items: " << endl;
                    cin >> name;
                    its.itc_name = name;
                    cout << "Enter loans day: " << endl;
                    cin >> loans_type;
                    its.itc_loans_types = loans_type;
                    cout << "Enter copies of items want to add: " << endl;
                    cin >> stock;
                    its.itc_copies = stock;
                    cout << "Enter items price: " << endl;
                    cin >> price;
                    its.itc_fees = price;
                    node = ItemList::createNode_items(its);
                    ItemList::AddTailItems(list, node);
                    quit = true;
                    break;
                case 2:
                    its.itc_types = "Record";
                    cout << "Enter genre of items: " << endl;
                    cin >> genre;
                    its.itc_genre = genre;
                    cout << "Enter year of this items: " << endl;
                    cin >> year;
                    ss << x;
                    ss >> s;
                    its.itc_id = "I00" + s + "-" + year;
                    cout << "Enter name of this items: " << endl;
                    cin >> name;
                    its.itc_name = name;
                    cout << "Enter loans day: " << endl;
                    cin >> loans_type;
                    its.itc_loans_types = loans_type;
                    cout << "Enter copies of items want to add: " << endl;
                    cin >> stock;
                    its.itc_copies = stock;
                    cout << "Enter items price: " << endl;
                    cin >> price;
                    its.itc_fees = price;
                    node = ItemList::createNode_items(its);
                    ItemList::AddTailItems(list, node);
                    quit = true;
                    break;
                case 3:
                    its.itc_types = "DVD";
                    cout << "Enter genre of items: " << endl;
                    cin >> genre;
                    its.itc_genre = genre;
                    cout << "Enter year of this items: " << endl;
                    cin >> year;
                    ss << x;
                    ss >> s;
                    its.itc_id = "I00" + s + "-" + year;
                    cout << "Enter name of this items: " << endl;
                    cin >> name;
                    its.itc_name = name;
                    cout << "Enter loans day: " << endl;
                    cin >> loans_type;
                    its.itc_loans_types = loans_type;
                    cout << "Enter copies of items want to add: " << endl;
                    cin >> stock;
                    its.itc_copies = stock;
                    cout << "Enter items price: " << endl;
                    cin >> price;
                    its.itc_fees = price;
                    node = ItemList::createNode_items(its);
                    ItemList::AddTailItems(list, node);
                    quit = true;
                    break;
                case 5:
                    quit = true;
                    break;
                default:
                    cout << "invalid selection" << endl;
                    break;
            }
        } while (!quit);
    }
    return nullptr;
};


Node_items_collection *ItemList::Update_Items_node(ItemList &l, const int &number_id) {
    Node_items_collection *new_node;
    new_node = l.head_items;
    int i = 0;
    while (new_node != nullptr && i != number_id - 1) {
        new_node = new_node->next;
        i++;
    }
    if (i == number_id - 1 && new_node != nullptr) {
        if(new_node->node_itc_types == "DVD" || new_node->node_itc_types == "Record"){
            auto *new_items = new items_collection;
            cout << "Enter items name: " << endl;
            cin >> new_items->itc_name;
            new_node->node_itc_name = new_items->itc_name;

            cout << "Enter items day loans: " << endl;
            cin >> new_items->itc_loans_types;
            new_node->node_itc_loans_types = new_items->itc_loans_types;

            cout << "Enter items copies: : " << endl;
            cin >> new_items->itc_copies;
            new_node->node_itc_copies = new_items->itc_copies;

            cout << "Enter items prices: : " << endl;
            cin >> new_items->itc_fees;
            new_node->node_itc_fees = new_items->itc_fees;

            cout << "Enter items genre: " << endl;
            cin >> new_items->itc_genre;
            new_node->node_itc_genre = new_items->itc_genre;
        } else{
            auto *new_items = new items_collection;
            cout << "Enter items name: " << endl;
            cin >> new_items->itc_name;
            new_node->node_itc_name = new_items->itc_name;

            cout << "Enter items day loans: " << endl;
            cin >> new_items->itc_loans_types;
            new_node->node_itc_loans_types = new_items->itc_loans_types;

            cout << "Enter items copies: : " << endl;
            cin >> new_items->itc_copies;
            new_node->node_itc_copies = new_items->itc_copies;

            cout << "Enter items prices: : " << endl;
            cin >> new_items->itc_fees;
            new_node->node_itc_fees = new_items->itc_fees;
        }
    }
    return nullptr;
}