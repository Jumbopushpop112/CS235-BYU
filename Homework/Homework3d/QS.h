#pragma once
#include <vector>
#include <utility>
using namespace std;
template <class T>
int medianThree(vector<T> &array, int low, int high) {
    int middle = (low+high)/2;
    //if table[first] is > table[middle], exchange first and middle
    if (array[low] > array[middle]) {
        swap(array[low],array[middle]);
    }
    //if table[last] < table[middle], exchange last and middle
    if (array[high] < array[middle]) {
        swap(array[high],array[middle]);
    }
    //if table[middle < table[first], exchange middle and first
    if (array[middle] < array[low]) {
        swap(array[middle],array[low]);
    }
    return middle;
}
template <class T>
int partition(vector<T> &array,int left, int right, int pivotIndex) {
    swap(array[left],array[pivotIndex]);
    int up = left+1;
    int down = right;
    do {
        while ((array[up] <= array[left]) && (up < right)) {
            up++;
        }
        while ((array[down] > array[left]) && (down > left)) {
            down--;
        }
        if (up < down) {
            swap(array[up],array[down]);
        }
    }while (up < down);
    swap(array[left],array[down]);
    return down;
}
template <class T>
void quickSortHelper(vector<T> &array, int low, int high) {
    if ((high-low) < 1) {
        return;
    }
    int pivotIndex = medianThree(array,low,high);
    pivotIndex = partition(array,low,high,pivotIndex);
    quickSortHelper(array,low,pivotIndex-1);
    quickSortHelper(array,pivotIndex+1,high);
}
template <class T>
void sort(std::vector<T> &array)
{
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
    quickSortHelper(array,0,array.size()-1);
}


