#ifndef VIDEORENT_ITEMS_H
#define VIDEORENT_ITEMS_H

#include<vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class items_collection {
public:
    string itc_id;
    string itc_name;
    string itc_types;
    string itc_loans_types;
    string itc_copies;
    string itc_fees;
    string itc_genre;
};

class Node_items_collection {
public:
    string node_itc_id;
    string node_itc_name;
    string node_itc_types;
    string node_itc_loans_types;
    string node_itc_copies;
    string node_itc_fees;
    string node_itc_genre;
    Node_items_collection *next;

    explicit Node_items_collection(items_collection &it) {
        this->node_itc_id = it.itc_id;
        this->node_itc_name = it.itc_name;
        this->node_itc_types = it.itc_types;
        this->node_itc_loans_types = it.itc_loans_types;
        this->node_itc_copies = it.itc_copies;
        this->node_itc_fees = it.itc_fees;
        this->node_itc_genre = it.itc_genre;
    }
};

#endif
