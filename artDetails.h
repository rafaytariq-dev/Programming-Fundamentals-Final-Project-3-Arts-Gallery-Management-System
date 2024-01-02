#include <iostream>
#include<fstream>
using namespace std;

struct artDetails {
    int serialnum;
    string typeofart;
    string paintername;
    string modeofart;
};

int maxIO=100;
void addRecord(artDetails detail[], int &counter){
    char addMore;
    
    do{
   

    cout<<"Enter the Serial Number for the Art Piece\n";
    cin>>detail[counter].serialnum;
    cout<<"Enter the Type of Art for the Art Piece\n";
    cin>>detail[counter].typeofart;
    cout<<"Enter the Painter Name for the Art Piece\n";
    cin>>detail[counter].paintername;
    cout<<"Enter the Mode of Art for the Art Piece\n";
    cin>>detail[counter].modeofart;

    counter++;

    cout<<"Enter Y or y to add more data or press anyother key to exit\n";
    cin>>addMore;
    }
    while (addMore=='y' || addMore=='Y');
    
}

void displayrecord(artDetails detail[], int &counter)
{   
    for(int i=0; i<counter; ++i){

    cout<<"\n Art Details "<< i << ":\n";
    cout<<"Serial Number"<<"\t"<<"Type of Art"<<"\t"<<"Painter Name"<<"\t"<<"Mode of Art\n";
    cout<<detail[counter].serialnum<<"\t"<<detail[counter].typeofart<<"\t"<<detail[counter].paintername<<"\t"<<detail[counter].modeofart;
    }
}

void saveDetailsToFile(const artDetails detail[], int counter) {
    // Implement save details to file functionality
    ofstream outFile("artDetails.txt");

    if (outFile.is_open()) {
        for (int i = 0; i < counter; ++i) {
            outFile << detail[i].serialnum << " " << detail[i].typeofart<<" "<<detail[i].paintername<<" "<<detail[i].modeofart << "\n";
        }

        outFile.close();
        cout << "Details saved to file successfully.\n";
    } else {
        cout << "Unable to open file to save details.\n";
    }
}

void printDetailsFromFile(artDetails detail[], int &counter) {
    // print reservations from file functionality
    ifstream inFile("artDetails.txt");

    if (inFile.is_open()) {
        while (inFile >> detail[counter].serialnum >> detail[counter].typeofart>> detail[counter].paintername>> detail[counter].modeofart) {
            counter++;
            if (counter >= maxIO) {
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

void searchdata(artDetails detail[], int &counter){
    int searchvariable;
    bool found=false;
    cout<<"Enter the Serial Number you want to find\n";
    cin>>searchvariable;
    cout<<"Serial Number"<<"\t"<<"Type of Art"<<"\t"<<"Painter Name"<<"\t"<<"Mode of Art\n";
    for(int i=0; i<counter; i++){
        if(detail[counter].serialnum==searchvariable){
        found = true;
        cout<<detail[counter].serialnum<<"\t"<<detail[counter].typeofart<<"\t"<<detail[counter].paintername<<"\t"<<detail[counter].modeofart;
        break;
        }
    }
    if (!found) {
        cout << "Data not found." << endl;
    }
    
}