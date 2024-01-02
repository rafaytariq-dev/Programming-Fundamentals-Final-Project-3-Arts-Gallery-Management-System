#include <iostream>
using namespace std;

struct artPrice{
    int orgprice;
    int discount;
    int newprice;   
};

int maxInput = 100;
void addRecord(artPrice price[], int row){
    char addMore;
    
    do{
    cout<<"Enter the Original Price for the Art Piece\n";
    cin>>price[row].orgprice;
    cout<<"Enter the Discount for the Art Piece\n";
    cin>>price[row].discount;
    cout<<"Enter the New Price for the art Piece\n";
    cin>>price[row].newprice;

    row++;


    cout<<"Enter Y or y to add more data or press anyother key to exit\n";
    cin>>addMore;
    }
    while (addMore=='y' || addMore=='Y');

}

void saveDetailsToFile(const artPrice price[], int row) {
    // Implement save details to file functionality
    ofstream outFile("artPrice.txt");

    if (outFile.is_open()) {
        for (int i = 0; i < row; ++i) {
            outFile << price[i].orgprice << " " << price[i].discount<<" "<<price[i].newprice<< "\n";
        }

        outFile.close();
        cout << "Details saved to file successfully.\n";
    } else {
        cout << "Unable to open file to save details.\n";
    }
}

void printDetailsFromFile(artPrice price[], int &row) {
    // print reservations from file functionality
    ifstream inFile("artPrice.txt");

    if (inFile.is_open()) {
        while (inFile >> price[row].orgprice >> price[row].discount>> price[row].newprice) {
            row++;
            if (row >= maxInput) {
                break;
            }
        }

        inFile.close();
        cout << "Details printed successfully from file.\n";
    }
    else
    {
        cout << "Unable to open file print details. Starting with an empty reservation list.\n";
    }
}

void displayrecord(artPrice price[], int row)
{   
    for(int i=0; i<row; ++i){

    cout<<"\n Price "<< i << ":\n";
    cout<<"Original Price"<<"\t"<<"Discount"<<"\t"<<"New Price\n";
    cout<<price[row].orgprice<<"\t"<<price[row].discount<<"\t"<<price[row].newprice<<endl;
    }
}
