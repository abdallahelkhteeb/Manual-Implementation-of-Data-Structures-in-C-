#include "Heap.h"

int Heap::parent(int child) {
    if(child)
        return (child - 1) / 2;
    return -1;
}
void Heap::heapify_up(int child_pos) {
    int par_pos = parent(child_pos);
    if(par_pos == -1 || arr[par_pos] <= arr[child_pos])
        return;
    std::swap(arr[par_pos], arr[child_pos]);
    
    heapify_up(par_pos); 
} 
void Heap::expand_capacity() {
    mx_size = size * 10;
    int *copy = new int[size + 1];
    for(int i = 0; i < size; ++i)// I think it is uneffecient way to do that.
        copy[i] = arr[i];
    delete arr;
    arr = new int[mx_size];
    for(int i = 0; i < size; ++i)
        arr[i] = copy[i]; 
}
void Heap::push(int target) {
    if(size + 1 == mx_size)
        expand_capacity();
    
    arr[size++] = target;
    heapify_up(size - 1);
}

int Heap::top() {
    if(!size)
        return 0;
    return arr[0];
}


int Heap::left(int parent) {
    return (parent * 2 + 1 < size ? parent * 2 + 1 : -1);
}

int Heap::right(int parent) {
    return (parent * 2 + 2 < size ? parent * 2 + 2 : -1);
}
void Heap::heapify_down(int par_pos) {
    int left_child = left(par_pos);
    int right_child = right(par_pos);

    if(left_child == -1)
        return;
    if(right_child != -1 && arr[right_child] < arr[left_child]) 
        left_child = right_child;

    if(arr[left_child] < arr[par_pos]) {
        std::swap(arr[left_child], arr[par_pos]);
        heapify_down(left_child);
    }
}

void Heap::pop() {
    if(!size)
        return;
    arr[0] = arr[--size];
    heapify_down(0);
}

void Heap::print_less_than(int val, int st_pos) {
    if(st_pos == -1 || arr[st_pos] >= val)
        return; 
    std::cout << arr[st_pos] << ' ';
    print_less_than(val, right(st_pos));
    print_less_than(val, left(st_pos));
    
}