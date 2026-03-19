#pragma once

#include <vector>
using namespace std;
template <class T>

void sort(vector<T> &array)
{
    for (int i = 1; i<array.size(); i++) {
        int nextPos = i;
        T nextVal = array[nextPos];
        while (nextPos > 0 && nextVal < array[nextPos-1]) {
            array[nextPos] = array[nextPos-1];
            nextPos--;
        }
        array[nextPos] = nextVal;
    }
}
