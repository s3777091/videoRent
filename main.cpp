#include <iostream>
#include <string>
#include "VideoRent.h"

using namespace std;

static string customer = R"(C:\Users\Asus\Desktop\School\videoRent\Data\customer.txt)";
static string items_file = R"(C:\Users\Asus\Desktop\School\videoRent\Data\items.txt)";

static CustomerList list_customer{};
static vector<Customer> vst;
static ItemList items{};

//Function for checking and/or alternating items
static void itemsCheck() {
    int input;
    bool quit = false;
    do {   
        //Sub-menu for item checking
        cout << "1. Add a new items?" << endl;
        cout << "2. Update an existing item?" << endl;
        cout << "3. Remove an items? " << endl;
        cout << "4. Quit" << endl;
        cout << "Please input an option: ";
        cin >> input;
        
        //Catching wrong input from user
        while (input < 1 || input > 4) {
            cerr << "The option is invalid. Please re-input an option: ";
            cin >> input;
        }
        
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
            /*default:
                cout << "invalid selection" << endl;
                break;*/
        }
    } while (!quit);
}


//Function for checking and/or alternating customers
static void customer_check() {
    int input;
    bool quit = false;
    do {        
        //Sub-menu for customer checking
        cout << "1. Add a new customer?" << endl;
        cout << "2. Update an existing customer?" << endl;
        cout << "3. Quit" << endl;
        cout << "Please input an option: ";
        cin >> input;
        //Catching wrong input from user
        while (input < 1 || input > 3) {
            cerr << "The option is invalid. Please re-input an option: ";
            cin >> input;
        }
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
            /*default:
                cout << "invalid selection" << endl;
                break;*/
        }
    } while (!quit);
}


//Function for searching either Items or Customers
static void search() {
    int input;
    bool quit = false;
    do {       
        //Sub-menu for searching
        cout << "1. Search Items? " << endl;
        cout << "2. Search Customer?" << endl;
        cout << "3. Quit" << endl;
        cout << "Please input an option: ";
        cin >> input;
        //Catching wrong input from user
        while (input < 1 || input > 3) {
            cerr << "The option is invalid. Please re-input an option: ";
            cin >> input;
        }
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
            /*default:
                cout << "invalid selection" << endl;
                break;*/
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
        
        //Main menu
        cout << "====================================" << endl;
        cout << "Welcome to Genie's video store!" << endl;
        cout << "How can we help you?" << endl;
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
        //Catching wrong input from user
        while (choose < 1 || choose > 12) {
            cerr << "The option is invalid. Please re-input an option: ";
            cin >> choose;
        }
        cout << "====================================" << endl;
        
        //Using Switch to be compatible with user's choice
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
                cout << "Thank you for using this service !" << endl;
                cout << "This was originally developed by: GROUP 05\n"
                     << "s3777091 - DAT HUYNH\n"
                     << "s3845565 - SON DO\n"
                     << "s3915177 - DUC TRINH" << endl;
                quit = true;
                break;
            
            /*default:
                cout << "invalid selection" << endl;
                break; */
        }
    } while (!quit);
    inFileCustomer.close();
    inFileItems.close();
    return 0;
}
