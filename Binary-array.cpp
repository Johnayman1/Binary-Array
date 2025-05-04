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


int minNumFlips(int arr[],int n ,int k) {

    int flips , res;
    flips = res =0;
    for (int i = 0; i < n; i++) {
        if (i - k >= 0 and arr[i-k] == 2)
            flips--;
        if ((arr[i] + flips) % 2 == 0) {
            if (i + k > n)
                return -1;
            res++;
            flips++;
            arr[i] = 2;
        }
    }
    return res;
}

void runFromTerminal(){
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin>>n;
    int arr[n];
    cout << "Enter the binary elements (0 or 1): ";
    for (int i = 0; i < n; i++) {
        while (true) {
            cin >> arr[i];
            if (arr[i] == 0 || arr[i] == 1)
                break;
            cout << "Invalid input. Enter 0 or 1 only: ";
        }
    }
    int k;
    cout << "Enter the size of subarray to flip: ";
    cin>>k;
    int res = minNumFlips(arr,n,k);
    cout<<res<<endl;
}
void runFromFile() {
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
            continue;
        }
    }
}

int main() {

    cout<<"***************** Welcome to our Binary Array ****************"<<endl;
    string choice;
    while (true) {
        while (true) {
            cout << "\nWhat do you want to do?" << endl;
            cout << "1) Run From Terminal." << endl;
            cout << "2) Initialize in main." << endl;
            cout << "3) Exit." << endl;
            cout << "\nPlease, enter your choice : ";
            getline(cin, choice);

            // Check the validity of input.
            if (choice == "1" || choice == "2" || choice == "3") break;
            cout << "Invalid choice. Please, Try again." << endl;
        }

        // Run from the terminal.
        if (choice == "1") runFromTerminal();

        // Initialize in main.
        else if (choice == "2") runFromFile();
        else break;
        cin.ignore();
    }

    cout << "\n----- Thank you for using our system! Goodbye! -----" << endl;
    return 0;
}



