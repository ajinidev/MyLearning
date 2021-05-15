#pragma once
#include <vector>

template <class T>
class BubbleSort {

public:
    void sort(std::vector<T>& arr) {
        auto size = arr.size();
        for (auto i = 0; i < size; i++) {
            for (auto j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    auto temp = arr[j+1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};