#include "ItmFunc.h"
void ItmFunc::read_items_collection(ifstream &filein, items_collection &itc) {
    getline(filein, itc.itc_id, ',');
    getline(filein, itc.itc_name, ',');
    getline(filein, itc.itc_types, ',');
    getline(filein, itc.itc_loans_types, ',');
    getline(filein, itc.itc_copies, ',');
    getline(filein, itc.itc_fees, ',');
    getline(filein, itc.itc_genre);
}

void ItmFunc::insert_file_items(ifstream &inFile, ItemList *list) {
    if (!inFile) {
        cout << "can't open file'" << endl;
    } else {
        ItemList list_items{};
        ItemList::CreateListItems(list_items);
        Node_items_collection *node;
        while (!inFile.eof()) {
            items_collection itc;
            read_items_collection(inFile, itc);
            node = ItemList::createNode_items(itc);
            ItemList::AddTailItems(list_items, node);
        }
        *list = list_items;
    }
}

void ItmFunc::save_file_data(ItemList &list, ofstream &fileout) {
    if (fileout.is_open()) {
        if (list.head_items != nullptr) {
            Node_items_collection *node = list.head_items;
            while (node != nullptr) {
                fileout << node->node_itc_id << ',';
                fileout << node->node_itc_name << ',';
                fileout << node->node_itc_types << ',';
                fileout << node->node_itc_loans_types << ',';
                fileout << node->node_itc_copies << ',';
                if(node->node_itc_genre == ""){
                    fileout << node->node_itc_fees << '\n';
                } else{
                    fileout << node->node_itc_fees << ',';
                    fileout << node->node_itc_genre << '\n';
                }
                node = node->next;
            }
        }
    } else {
        cout << "Can't Open file" << endl;
    }
}

void ItmFunc::AddNewItems(ItemList &list, string file) {
    ofstream fileout(file);
    ItemList::addNewItems(list);
    ItemList::PrintListItems(list);
    bool quit = false;
    do {
        cout << "1. Save Data? " << endl;
        cout << "2. Quit" << endl;
        cout << "Please input an option: ";
        int confirm;
        cin >> confirm;
        switch (confirm) {
            case 1:
                save_file_data(list,fileout);
                quit = true;
                break;
            case 2:
                cout << "Nothing to save" << endl;
                quit = true;
                break;
            default:
                cout << "invalid selection" << endl;
                break;
        }
    } while (!quit);
    fileout.close();
}

void ItmFunc::Update_Items_information(const string &file, ItemList &list) {
    ItemList::PrintListItems(list);
    ofstream fileout(file);
    int number;
    cout << "Enter items id want to update: ";
    cin >> number;
    cout << '\n' << endl;
    ItemList::Update_Items_node(list,number);
    ItemList::PrintListItems(list);
    bool quit = false;
    do {
        cout << "1. Save Data? " << endl;
        cout << "2. Quit" << endl;
        cout << "Please input an option: ";
        int confirm;
        cin >> confirm;
        switch (confirm) {
            case 1:
                save_file_data(list, fileout);
                quit = true;
                break;
            case 2:
                cout << "Nothing to save" << endl;
                quit = true;
                break;
            default:
                cout << "invalid selection" << endl;
                break;
        }
    } while (!quit);
    fileout.close();
}

