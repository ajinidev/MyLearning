#pragma once
#include <vector>

template<class T>
class QuickSort {

public:
    void sort(std::vector<T>& arr) {
        sort(arr, 0, arr.size() - 1);
    }

private:
    void sort(std::vector<T>& arr, int start, int end) {
        if (start >= end) {
            return;
        }
        auto pivot = start;
        auto left = pivot + 1;
        auto right = end;
        while (right >= left) {
            if (arr[left] > arr[pivot] && arr[right] < arr[pivot]) {
                swap(arr, left, right);
            }
            if (arr[left] <= arr[pivot]) {
                left++;
            }
            if (arr[right] >= arr[pivot]) {
                right--;
            }
        }
        swap(arr, pivot, right);
        sort(arr, start, right - 1);
        sort(arr, right + 1, end);
    }

    void swap(std::vector<T>& arr, int left, int right) {
        auto temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
};