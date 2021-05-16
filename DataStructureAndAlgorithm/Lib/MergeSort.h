#pragma once

#include <vector>

template<class T>
class MergeSort {

public:
    void sort(std::vector<T>& arr) {
        std::vector<T> out = mergeSort(arr);
        arr = std::move(out);
    }

private:
    std::vector<T> mergeSort(std::vector<T>& arr) {
        if (arr.size() <= 1) {
            return std::move(arr);
        }
        int middle = arr.size() / 2;
        auto left = mergeSort(std::vector<T>(arr.begin(), arr.begin() + middle));
        auto right = mergeSort(std::vector<T>(arr.begin() + middle, arr.end()));
        return std::move(merge(left, right));
    }

    std::vector<T> merge(std::vector<T>& left, std::vector<T>& right) {
        std::vector<T> out;
        int l = 0, r = 0;
        while (l < left.size() && r < right.size()) {
            if (left[l] < right[r]) {
                out.push_back(left[l++]);
            }
            else {
                out.push_back(right[r++]);
            }
        }
        while (l < left.size()) {
            out.push_back(left[l++]);
        }
        while (r < right.size()) {
            out.push_back(right[r++]);
        }
        return std::move(out);
    }
};