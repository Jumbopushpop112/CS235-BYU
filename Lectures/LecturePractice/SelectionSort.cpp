//
// Created by matth on 2/23/2026.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
void selectionSort(int arr[],int n) {
    /*for i from 0 to n-1:
    min_index = i
    for j from i+1 to n:
        if array[j] < array[min_index]:
            min_index = j
    swap array[i] and array[min_index]*/
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i + 1; j<n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    // Print sorted array
    cout << "SORTED ARRAY" << endl;
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}
int main(int argc, char*argv[]) {
    int arr[10];
    srand(time(0));  // Seed random number generator
    for(int i = 0; i < 10; i++) {
        arr[i] = rand() % 100 + 1;  // Random numbers between 1 and 100
    }
    cout << "ORGINAL ARRAY" << endl;
    cout << "[";
    for (int i = 0; i<10; i++) {
        cout << arr[i];
        if (i < 9) cout << ", ";
    }
    cout << "]" << endl;
    selectionSort(arr,10);
    return 0;
}