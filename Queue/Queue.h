#ifndef QUEUE_H
#define QUEUE_H

#pragma once

class Queue
{
private:
    int size{};
    int added_element{};
    int front{0};
    int rear{0};
    int *arr{};

public:
    Queue(int size = 0): size{size} {
        arr = new int[size];
    };
    ~Queue() {delete []arr;};

    void enqueue(int val);
    int dequeue();
    void display();
    int next(int node);
    bool is_full();
    bool is_empty();
    void set_size(int size) {
        this->size = size;
        arr = new int[size];
    }





    void enqueue_rear(int val);
    void enqueue_front(int val);
    int dequeue_rear();
    int dequeue_front();

    int prev(int pos) {
        pos--;
        if(pos == -1)
            return size - 1;
        return pos;
    }

};

#endif