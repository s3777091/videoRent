#include <iostream>
#include <string>
#include "Function/VideoCustomer.h"
#include "Function/CustomerItems.h"

using namespace std;

int main() {
    //string customer = R"(C:\Users\Aisaka\Desktop\Working\RMIT\2021c\Software Engineering Design\videoRent\Data\customers.txt)";
//    ifstream inFile(customer);
//    LinkedList list_customer{};
//    vector<Customer> vst;
//    VideoCustomer::insert_data_file(inFile, &list_customer, vst);
//    VideoCustomer::Display_customer_in_type(vst);

    //string items_file = R"(C:\Users\Aisaka\Desktop\Working\RMIT\2021c\Software Engineering Design\videoRent\Data\items.txt)";
    //ifstream openFile(items_file);
    int input;
    cout << "Welcome to Genie's video store!" << endl;
    cout << "How can we help you? Please input an option." << endl;
    cout << "1. I'd like to add new item, update or delete an existing item" << endl;
    cout << "2. I'd like to add new customer or update an existing customer" << endl;
    cout << "3. I'd like to promote an existing customer" << endl;
    cout << "4. I'd like to rent an item" << endl;
    cout << "5. I'd like to return an item" << endl;
    cout << "6. I'd like to display all items" << endl;
    cout << "7. I'd like to display out-of-stock item" << endl;
    cout << "8. I'd like to display all customers" << endl;
    cout << "9. I'd like to display group of customers" << endl;
    cout << "10. I'd like to search items or customers" << endl;
    cout << "Please type 'Exit' whenever to end the program" << endl;
    cout << "Please input an option: ";
    cin >> input;

    while (input < 1 || input > 10) {
        cerr << "The option is invalid. Please re-input an option: ";
        cin >> input;
    }

    while (input != 'Exit') {
        if (input == 1) {
                cout << "Would you like to: " << endl;
                cout << "1. Add a new item?" << endl;
                cout << "2. Update an existing item?" << endl;
                cout << "3. Delete an existing item?" << endl;
                cout << "Please input an option: ";
                cin >> input;
                while (input < 1 || input > 3) {
                    cerr << "The option is invalid. Please re-input an option: ";
                    cin >> input;
                }
        }
        else if (input == 2){
                cout << "Would you like to: " << endl;
                cout << "1. Add a new customer?" << endl;
                cout << "2. Update an existing customer?" << endl;
                cout << "Please input an option: ";
                cin >> input;
                while (input < 1 || input > 3) {
                    cerr << "The option is invalid. Please re-input an option: ";
                    cin >> input;
                }
        }
        else if (input == 10) {
                cout << "Would you like to: " << endl;
                cout << "1. Search for items?" << endl;
                cout << "2. Search for customers?" << endl;
                cout << "Please input an option: ";
                cin >> input;
                    while (input < 1 || input > 3) {
                    cerr << "The option is invalid. Please re-input an option: ";
                    cin >> input;
                }
        }
    }







    //ItemsList items{};
    //CustomerItems::insert_file_items(openFile, &items);
    //ItemsList::PrintListItems(items);


    //openFile.close();
    return 0;
}