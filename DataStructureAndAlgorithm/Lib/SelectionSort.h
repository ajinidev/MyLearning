#pragma once
#include <vector>

template <class T>
class SelectionSort {

public:
    void sort(std::vector<T>& arr) {
        auto size = arr.size();
        for (auto i = 0; i < size; i++) {
            auto min = i;
            for (auto j = i + 1; j < size; j++) {
                if (arr[min] > arr[j]) {
                    min = j;
                }
            }
            if (min != i) {
                auto temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
            }
        }
    }
};