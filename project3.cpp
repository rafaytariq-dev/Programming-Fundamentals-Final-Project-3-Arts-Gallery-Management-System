#include <iostream>
#include "artDetails.h"
//#include "artInventory.h"
#include "artPrice.h"
using namespace std;

void detailsMenu( artDetails detail[] , int currentrow )
{

   //making an integer variable to ask user what he wants to do
    int choice;
    //using a do while loop
    do{

    //print this body for users information    
    cout<<"Enter numbers from 1 till 6 to view menu: \n"
        <<"1: Search Record\n"
        <<"2: View Record\n"
        <<"3: Add Record\n"
        <<"4: Save Record to File\n"
        <<"5: Print Record from File\n"
        <<"6: Exit Menu\n";
    //take input from user for menu choice
    cin>>choice;

    //assigning choice to switch statement
    switch(choice){
        //if user enters 1 in choice
        case 1:
        //run search data function
        searchdata(detail, currentrow);
        //stop after running the search function once
        break;

        //if user enters 2 in choice
        case 2:
        //run display record function
        displayrecord(detail, currentrow);
        //stop after running the display function once
        break;

        //if user enters 3 in choice
        case 3:
        //run add record function
        addRecord(detail, currentrow);
        //stop after running the add function once
        break;

         //if user enters 4 in choice
        case 4:
        saveDetailsToFile(detail, currentrow);
        break;
        case 5:
        printDetailsFromFile(detail, currentrow);
        break;
        case 6:
        //print exiting the program
        cout<<"Exiting the program\n";
        //exit the program
        exit(0);
    //switch statements closes    
    }
    //do statement closes
    }
    //while choice is not equal to 6
    while (choice != 6 );
    //print this body
    {
        //wrong input
        cout<<"Wrong Input";
    }
//function definition ends   
}

void priceMenu( artPrice price[] , int currentrow )
{

   //making an integer variable to ask user what he wants to do
    int choice;
    //using a do while loop
    do{

    //print this body for users information    
    cout<<"Enter numbers from 1 till 5 to view menu: \n"
        <<"1: Add Record\n"
        <<"2: Display Record\n"
        <<"3: Save Data to File\n"
        <<"4: Print Record from File\n"
        <<"5: Exit\n";

    //take input from user for menu choice
    cin>>choice;

    //assigning choice to switch statement
    switch(choice){
        //if user enters 1 in choice
        case 1:
        //run add record function
        addRecord(price, currentrow);
        //stop after running the add record function once
        break;

        //if user enters 2 in choice
        case 2:
        //run display record function
        displayrecord(price, currentrow);
        //stop after running the display record function once
        break;

        //if user enters 3 in choice
        case 3:
        saveDetailsToFile(price, currentrow);
        break;

        case 4:
        printDetailsFromFile(price, currentrow);
        break;

        case 5:
        //print exiting the program
        cout<<"Exiting the program\n";
        //exit the program
        exit(0);


    //switch statements closes    
    }
    //do statement closes
    }
    //while choice is not equal to 5
    while (choice != 5);
    //print this body
    {
        //wrong input
        cout<<"Wrong Input";
    }
//function definition ends   
}

/*void inventoryMenu(inventory stock[], int currentrow, artDetails detail[], int &counter, artPrice price[], int row)
{

   //making an integer variable to ask user what he wants to do
    int choice;
    //using a do while loop
    do{

    //print this body for users information    
    cout<<"Enter numbers from 1 till 5 to view menu: \n"
        <<"1: Add Record\n"
        <<"2: Display Record\n"
        <<"3: Exit Menu\n";
    //take input from user for menu choice
    cin>>choice;

    //assigning choice to switch statement
    switch(choice){
        //if user enters 1 in choice
        case 1:
        //run search data function
        addInventory(stock, currentrow, detail, counter, price, row);
        //stop after running the search function once
        break;

        //if user enters 2 in choice
        case 2:
        //run display record function
        displayInventory(stock, currentrow);
        //stop after running the display function once
        break;

        //if user enters 3 in choice
        case 3:
        //print exiting the program
        cout<<"Exiting the program\n";
        //exit the program
        exit(0);

    //switch statements closes    
    }
    //do statement closes
    }
    //while choice is not equal to 3
    while (choice != 3 );
    //print this body
    {
        //wrong input
        cout<<"Wrong Input";
    }
//function definition ends   
}*/

struct inventory{
    int totalStock;
    int availableStock;
    int soldStock;
};

//int maxInput=100;
void addInventory(inventory stock[], int currentrow, artDetails detail[], int &counter, artPrice price[], int row){
    char addMore;
    
    if (currentrow==maxInput){
    bool sfound = false;
    int fserialnum;
    cout<<"Enter Serial Number";
    cin>>fserialnum;
    bool found = false;
    for(int i=0; i<counter; i++){
        if (detail[i].serialnum == fserialnum) {
            sfound = true;
            break;
        }
    }
    
    if (!sfound) {
        cout << "Serial Number not found.\n";
        return;
    }
    
    int pricef;
    cout<<"Enter Price for the art piece";
    cin>>pricef;

    bool artPrice = false;
        for (int i = 0; i < row; ++i) {
            if (price[i].orgprice == pricef) {
                artPrice = true;
                break;
            }
        }

        if (!artPrice) {
            cout << "Price not found.\n";
            return;
        }

    cout<<"ADD INVENTORY\n";
    cout<<"Enter Total Stock";
    cin>>stock[currentrow].totalStock;
    cout<<"Enter Stock Saled";
    cin>>stock[currentrow].soldStock;
    cout<<"Enter Available Stock";
    cin>>stock[currentrow].availableStock;

    currentrow++;

    cout<<"Inventory Added Successfully";
    }
    else{
    cout<<"Failed to Add Inventory";
    }
}

void displayInventory(inventory stock[], int currentrow)
{   
    for(int i=0; i<currentrow; ++i){

    cout<<"\n Inventory "<< i << ":\n";
    cout<<"Total Stock"<<"\t"<<"Sold Stock"<<"\t"<<"Available Stock\n";
    cout<<stock[currentrow].totalStock<<"\t"<<stock[currentrow].soldStock<<"\t"<<stock[currentrow].availableStock;
    }
}

void inventoryMenu(inventory stock[], int currentrow, artDetails detail[], int &counter, artPrice price[], int row)
{
     cout << "Enter the operation you want to perform" << endl;
        cout << "1. Add Inventory\n2. Display Inventory\n3. Exit\n";

        int option;
        cin >> option;

        switch (option) {
            case 1:
                addInventory(stock, currentrow, detail, counter, price, row);
                break;
            case 2:
                displayInventory(stock, currentrow);
                break;
            case 3:
                exit(0);
                cout<<"Exiting Inventory";
                break;

}
}





int main(){
    int maxInput=100;
    int currentrow=0;
    int row =0;
    int counter=0;
    artDetails details[maxInput];
    artPrice price[maxInput];
    inventory stock[maxInput];

        while (true) {
        cout << "ART GALLERY MANAGEMENT SYSTEM" << endl;
        cout << "Enter the operation you want to perform" << endl;
        cout << "1. Art Details Managment\n2. Student Management\n3. Inventory Management\n4. Exit\n";

        int option;
        cin >> option;

        switch (option) {
            case 1:
                detailsMenu(details, currentrow);
                break;
            case 2:
                priceMenu(price, currentrow);
                break;
            case 3:
                inventoryMenu(stock, currentrow, details, counter, price, row);
                break;
            case 4:
                exit(0);
                cout << "Program ends\n";
                return 0;
            default:
                cout << "Invalid option!\n";
        }
    }
}

