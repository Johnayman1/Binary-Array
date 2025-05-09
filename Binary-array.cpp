/*
* Authors:
    * Author1: Esraa Emary Abd El-Salam      ID: 20230054
    * Author2: Mariam Badr Yehia             ID: 20230391
    * Author3: John Ayman Demian             ID: 20230109
    * Author4: Mohammed Atef Abd El-Kader    ID: 20231143
    * Author5: George Malak Magdy            ID: 20231042
 * Date : 8/3/2025
 * Prof : Dr. Besheer
 * Description: This is a program that manages "Iftar Invitations" which makes you add a guest,
                display it and edit the date of invitation.
 * Version: V3.0
*/
// < ========================================================================================== >

#include <bits/stdc++.h>

using namespace std;


class binary_array {

    int size = 0 ;
    int sizeOfSub = 0;
    int *arr;
    public:
    binary_array(int size = 100 , int sizeOfSub = 0) ;
    ~binary_array();
    int minNumFlips();
    void runFromTerminal();
    void runFromFile();
    void displayMenu();


};

//=================================== constructor
binary_array::binary_array(int size , int sizeOfSub ) {
    this->size = size;
    this->sizeOfSub = sizeOfSub;
    this->arr = new int[size];
}


//=================================== Calculate Flips
int binary_array::minNumFlips() {

    int flips , res;
    flips = res =0;
    for (int i = 0; i < this->size; i++) {
        if (i - this->sizeOfSub >= 0 and arr[i - this->sizeOfSub] == 2)
            flips--;
        if ((arr[i] + flips) % 2 == 0) {
            if (i + this->sizeOfSub > this->size )
                return -1;
            res++;
            flips++;
            this->arr[i] = 2;
        }
    }
    return res;
}
//=================================== Method for run from terminal
void binary_array::runFromTerminal(){

    cout<<"Enter the number of elements in the array: ";
    cin >> this->size ;
    delete[] this->arr;
    this->arr = new int[this->size];
    cout << "Please enter binary elements (0 or 1) only! "<<endl;
    for (int i = 0; i < this->size; i++) {
        while (true) {
            cout << "Enter the "<< i+1 <<" element: ";
            cin >> this->arr[i];
            if (arr[i] == 0 || arr[i] == 1)
                break;
            cout << "Invalid input. Enter 0 or 1 only!!"<<endl;
        }
    }
    while (true) {
        cout << "Enter the size of subarray to flip: ";
        cin >> this->sizeOfSub ;
        if (this->sizeOfSub >= 0) {
            break;
        }
    }
    int res = 0;
    res = minNumFlips();
    cout<<"Minimum number of flips is : "<< res <<endl;
}


//=================================== Method for run from file
void binary_array::runFromFile() {
    string fileName;
    cout << "\nPlease, enter file name:";
    while (true) {
        getline(cin, fileName);
        // Input the file and check from existing
        if (fileName.size() < 5 || fileName.substr(fileName.size() - 4) != ".txt") {
            cout << "\nThe file name should be like this ----> (file name).txt\n";
            cout << "Please, enter a valid file name:";
            continue;
        }
        ifstream file(fileName);
        if (!file.is_open()) {
            cout << "\nFile not found! Please, enter a valid file name:";
        }
        int numOfTests;
        file >> numOfTests;
        for (int j = 1; j <= numOfTests; j++){
            file >> this->size;
            delete[] this->arr;
            this->arr = new int[this->size];
            for (int i = 0; i < this->size; i++) {
                file >> this->arr[i];
            }

            file >> this->sizeOfSub;

            cout << "\nTest Case #" << j << endl;
            cout << "\nArray Size: " << this->size << endl;
            cout << "Array Elements: ";
            for (int i = 0; i < this->size; i++) {
                cout << this->arr[i] << " ";
            }
            cout << "\nSubarray Size: " << this->sizeOfSub << endl;
            int res = 0;
            res = minNumFlips();
            cout << "Minimum number of flips is: " << res << endl;
        }
        file.close();
        break;
    }
}

//=================================== Display Menu
void binary_array::displayMenu() {
    string choice;
    while (true) {
        while (true) {
            cout << "\nWhat do you want to do?" << endl;
            cout << "1) Run From Terminal." << endl;
            cout << "2) Run From File." << endl;
            cout << "3) Exit." << endl;
            cout << "\nPlease, enter your choice : ";
            getline(cin, choice);

            // Check the validity of input.
            if (choice == "1" || choice == "2" || choice == "3") break;
            cout << "Invalid choice. Please, Try again." << endl;
        }

        // Run from the terminal.
        if (choice == "1") {
            runFromTerminal();
            cin.ignore();
        }
        // Run from the file.
        else if (choice == "2") runFromFile();
        else break;
    }
}
binary_array::~binary_array() {
    delete[] arr;
}


int main() {

    cout<<"***************** Welcome to our Binary Array ****************"<<endl;
    binary_array myArray;
    myArray.displayMenu();
    cout << "\n----- Thank you for using our system! Goodbye! -----" << endl;
    return 0;
}



