#pragma once

template <class T>
class Array {
private:
    T* _arr;
    int _length;
    int _capacity;

public:
    Array(): Array(2) {
        
    }

    Array(int capacity) {
        if (capacity < 0) {
            throw "Invalid capacity.";
        }
        _capacity = capacity;
        _arr = static_cast<T*>(malloc(_capacity * sizeof(T)));;
        _length = 0;
    }

    int size() {
        return length;
    }

    bool isEmpty() {
        return size() == 0;
    }

    T get(int idx) {
        return _arr[idx];
    }

    void set(int idx, T ele) {
        _arr[idx] = ele;
    }

    void clear() {
        delete _arr;
        _arr = nullptr;
    }

    void add(T ele) {
        if (_length == _capacity) {
            grow();
        }
        _arr[_length++] = ele;
    }

    T removeAt(int idx) {
        if (idx >= _length) {
            throw "Invalid Index";
        }
        auto data = _arr[idx];
        _length--;
        for (auto i = idx; i < _length; i++) {
            _arr[i] = _arr[i + 1];
        }
        return data;
    }

    bool remove(T obj) {
        auto i = indexOf(obj);
        if (-1 == i) {
            return false;
        }
        removeAt(i);
        return true;
    }

    int indexOf(T obj) {
        for (auto i = 0; i < _length; i++) {
            if (_arr[i] == obj) {
                return i;
            }
        }
        return -1;
    }

    bool contains(T obj) {
        return indexOf(obj) != -1;
    }


private:
    void grow() {
        auto temp = static_cast<T*>(malloc(_capacity * 2 * sizeof(T)));
        // memcpy_s(_arr, sizeof(T) * _capacity, temp, sizeof(T) * _capacity);
        for (auto i = 0; i < _length; i++) {
            temp[i] = _arr[i];
        }
        free(_arr);
        _capacity *= 2;
        _arr = temp;
    }
};