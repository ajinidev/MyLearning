#pragma once

#include <vector>

template <class T>
class InsertionSort {

public:
    void sort(std::vector<T>& arr) {
        auto size = arr.size();
        for (auto i = 1; i < size; i++) {
            for (auto j = i; j > 0; j--) {
                if (arr[j - 1] < arr[j]) {
                    break;
                }
                else if (arr[j] < arr[j - 1]) {
                    auto temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
            }
        }
    }
};