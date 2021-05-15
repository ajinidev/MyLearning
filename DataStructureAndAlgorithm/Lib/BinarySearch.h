#pragma once
#include <vector>

template <class T>
class BinarySearch {

public:
    int searchLoop(std::vector<T>& arr,T value) {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end) {
            auto middle = (start + end) / 2;
            if (arr[middle] == value) {
                return middle;
            }
            else if (arr[middle] < value) {
                start = middle + 1;
            }
            else {
                end = middle - 1;
            }
        }
        return -1;
    }

    int searchRecursion(std::vector<T>& arr, T value) {
        return searchRecursion(arr, value, 0, arr.size() - 1);
    }

private:

    int searchRecursion(std::vector<T>& arr, T value, int start, int end) {
        if (start <= end) {
            auto middle = start + end;
            if (arr[middle] == value) {
                return middle;
            }
            else if (arr[middle] < value) {
                return searchRecursion(arr, value, middle + 1, end);
            }
            return searchRecursion(arr, value, start, middle - 1);
        }
        return -1;
    }

};