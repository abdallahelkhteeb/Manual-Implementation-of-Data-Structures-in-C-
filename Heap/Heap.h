#ifndef HEAP_H
#define HEAP_H

#pragma once

#include <bits/stdc++.h>
class Heap
{
private:
    int *arr;
    int size = 0;
    int mx_size {1000};
public:
    Heap() {
        arr = new int [mx_size];
    };
    int parent(int child);
    void heapify_up(int child_pos);
    void expand_capacity(); 
    void push(int target);
    int top();
    int left(int parent);
    int right(int parent);
    void pop();
    void heapify_down(int parent_pos);
    int sz() {return this->size;}
    void print_less_than(int val, int st_pos = 0);
    
};

#endif