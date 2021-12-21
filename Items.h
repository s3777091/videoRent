//
// Created by Aisaka on 12/19/2021.
//

#ifndef MAIN_CPP_ITEMS_H
#define MAIN_CPP_ITEMS_H
#include <iostream>
#include <string.h>


using namespace std;

class Items {
private:
    string ID;
    string Title;
    string RentalType;
    string LoanType;
    int Copies;
    double Fees;
    bool Status;

public:
    Items();

    //Setters
    void setID() {ID = ID;}
    void setTitle() {Title =Title;}
    void setRentalType() {RentalType = RentalType;}
    void setLoanType() {LoanType = LoanType;}
    void setCopies() {Copies = Copies;}
    void setFees () {Fees = Fees;}
    void setStatus() {Status = Status;}

    //Getters
    string getID() {return this->ID;}
    string getTitle() {return this->Title;}
    string getRentalType() {return this->RentalType;}
    string getLoanType() {return this->LoanType;}
    int getCopies() {return this->Copies;}
    double getFees() {return this->Fees;}
    bool getStatus() {return this->Status;}

    ~Items();
};

#endif //MAIN_CPP_ITEMS_H
