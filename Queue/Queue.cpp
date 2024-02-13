#include "Queue.h"
#include <iostream>
#include <cassert>
bool Queue::is_full() {return added_element == size;}




bool Queue::is_empty() {return added_element == 0;}



void Queue::enqueue(int val) {
    assert(!is_full());
    arr[rear] = val;
    rear = next(rear);  
    added_element++;    
}

int Queue::dequeue() {
    assert(!is_empty());
    int val = arr[front];
    front = next(front);
    added_element--;
    return val;
}

void Queue::display() {
    if(is_empty()) {
        std::cout << "empty" << std::endl;
        return;
    }
    for(int cur = front, step = 0; step < added_element; step++, cur = next(cur))
        std::cout << arr[cur] << ' ';
    std::cout << std::endl;
}

int Queue::next(int node) {
    return (node + 1) % size;
}









