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

int main() {


    cout<<"***************** Welcome to our Binary Array ****************"<<endl;
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin>>n;
    int arr[n];
    cout << "Enter the binary elements (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int k;
    cout << "Enter the size of subarray to flip: ";
    cin>>k;
    int res = minNumFlips(arr,n,k);
    cout<<res<<endl;
    return 0;
}

