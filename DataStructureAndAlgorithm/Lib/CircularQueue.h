#pragma once
#include <functional>

template <class T>
class CircularQueue {

private:
    T* mQueue = nullptr;
    int size = 2;
    int front = -1;
    int rear = -1;
public:
    CircularQueue() {
        mQueue = new T[size];
        front = -1;
        rear = -1;
    }

    void enqueue(T data) {
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
            mQueue[rear] = data;
            return;
        }
        if ((rear + 1) % size == front) {
            grow();
        }
        rear = (++rear) % size;
        mQueue[rear] = data;
    }

    T dequeue() {
        if (front == -1) {
            throw "Queue is empty";
        }
        if (front == rear) { // if there is only one element
            auto data = mQueue[front];
            front = rear = -1;
            return data;
        }
        else {
            auto data = mQueue[front];
            front = (++front) % size;
            return data;
        }
    }

    std::string to_string(std::function<std::string(T)> to_string) {
        std::string str = "";
        if (front == -1 && rear == -1) {
            return str;
        }
        for (auto idx = front; idx != (rear + 1) % size; idx++) {
            str += to_string(mQueue[idx]);
        }
        return str;
    }

private:

    void grow() {
        auto newQueue = new T[size * 2];
        for (auto idx = front, i = 0; i < size; idx++, i++) {
            newQueue[i] = mQueue[idx];
        }
        front = 0;
        rear = size - 1;
        size *= 2;
        delete[] mQueue;
        mQueue = newQueue;
    }
};