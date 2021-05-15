#pragma once

#include <vector>

template <class T>
class InsertionSort {

public:
    void sort(std::vector<T>& arr) {
        auto size = arr.size();
        for (auto i = 1; i < size; i++) {
            for (auto j = i; j >= 0; j--) {
                if (arr[i] < arr[j]) {
                    break;
                }
                else if (arr[i] < arr[j]) {
                    auto temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
};