#pragma once

#include <vector>
using std::vector;

#include "handy.h" // PRINT macro
using handy::swap;

template <class T>
void sort(vector<T> &items)
{
    bool modified = true;
    for (size_t n_sorted_at_back = 0; modified && n_sorted_at_back < items.size(); n_sorted_at_back++) {
        modified = false;
        for (size_t i = 0; i < items.size()-n_sorted_at_back-1; i++) {
            PRINT(items, i, -1, -1);

            if (items[i] > items[i + 1]) {
                swap(items[i], items[i + 1]);
                PRINT(items, i, i, i + 1);
                modified = true;
            }
        }
    }
}