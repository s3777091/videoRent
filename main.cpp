#include <iostream>
#include <string>
#include "VideoRent.h"

using namespace std;

static string customer = R"(C:\Users\Asus\Desktop\School\videoRent\Data\customer.txt)";
static string items_file = R"(C:\Users\Asus\Desktop\School\videoRent\Data\items.txt)";

static CustomerList list_customer{};
static vector<Customer> vst;
static ItemList items{};

static void itemsCheck() {
    int input;
    bool quit = false;
    do {
        cout << "1. Add a new items?" << endl;
        cout << "2. Update an existing customer?" << endl;
        cout << "3. Remove an items? " << endl;
        cout << "4. Quit" << endl;
        cout << "Please input an option: ";
        cin >> input;
        switch (input) {
            case 1:
                ItmFunc::AddNewItems(items, items_file);
                break;
            case 2:
                break;
            case 3:
                cout << "Remove " << endl;
                break;
            case 4:
                quit = true;
                break;
            default:
                cout << "invalid selection" << endl;
                break;
        }
    } while (!quit);
}


static void customer_check() {
    int input;
    bool quit = false;
    do {
        cout << "1. Add a new customer?" << endl;
        cout << "2. Update an existing customer?" << endl;
        cout << "3. Quit" << endl;
        cout << "Please input an option: ";
        cin >> input;
        switch (input) {
            case 1:
                CusFunc::AddNewCustomer(list_customer, customer);
                break;
            case 2:
                CusFunc::Update_customer_information(customer, list_customer);
                break;
            case 3:
                quit = true;
                break;
            default:
                cout << "invalid selection" << endl;
                break;
        }
    } while (!quit);
}

static void search() {
    int input;
    bool quit = false;
    do {
        cout << "1. Search Items? " << endl;
        cout << "2. Search Customer?" << endl;
        cout << "3. Quit" << endl;
        cout << "Please input an option: ";
        cin >> input;
        switch (input) {
            case 1:
                cout << "Dont have" << endl;
                break;
            case 2:
                CusFunc::Search_customer(list_customer);
                break;
            case 3:
                quit = true;
                break;
            default:
                cout << "invalid selection" << endl;
                break;
        }
    } while (!quit);

}


int main() {
    int choose;
    string number;
    bool quit = false;
    ifstream inFileCustomer(customer);
    ifstream inFileItems(items_file);
    do {
        VideoRent::connect_data(inFileCustomer, inFileItems, &list_customer, vst, &items);
        cout << "====================================" << endl;
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
        cout << "11. Please type 'Exit' whenever to end the program" << endl;
        cout << "Please input an option: ";
        cin >> choose;
        cout << "====================================" << endl;
        switch (choose) {
            case 1:
                itemsCheck();
                break;
            case 2:
                customer_check();
                break;
            case 3:
                CusFunc::Promote_Customer(customer, list_customer);
                break;
            case 6:
                ItemList::PrintListItems(items);
                break;
            case 8:
                CustomerList::PrintListAllCustomer(list_customer);
                break;
            case 9:
                CusFunc::Display_customer_in_type(vst);
                break;
            case 10:
                search();
                break;
            case 11:
                cout << "S3777091 - HUYNH DAC TAN DAT " << endl;
                quit = true;
                break;
            default:
                cout << "invalid selection" << endl;
                break;
        }
    } while (!quit);
    inFileCustomer.close();
    inFileItems.close();
    return 0;
}
