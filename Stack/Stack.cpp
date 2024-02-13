#include "Stack.h"
#include <iostream>

bool Stack::push(int num) {//O(1)
    if(is_full())
        return 0;
    arr[--index] = num;
    return 1;
}
bool Stack::push(char c) {//O(1)
    if(is_full())
        return 0;
    arr[--index] = c;
    return 1;
}
bool Stack::is_full() {//O(1)
    if(index == 0)
        return 1;
    return false;
}
bool Stack::is_empty() {//O(1)
    if(index == size)
        return true;
    return false;
}

bool Stack::pop() {// O(1)
    if(is_empty()) 
        return 0;
    arr[index++] = 0;
    return 1;
}

// char Stack::peek() { //O(1)
//     if(!is_empty());
//         return arr[index];
//     return -1;
// }
int Stack::peek() { //O(1)
    if(!is_empty());
        return arr[index];
    return -1;
}

void Stack::display() const {
    for(int i = index; i < size; ++i) 
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

}
void Stack::dispaly_and_pop() {
    for(; index < size; ++index)
        std::cout << peek();
}
void Stack::display_string() {
    for(int i = size - 1; i >= index; --i)
        std::cout << char(arr[i]);
}

int Stack::reverse_num(int num) {
    while(num) 
        push(num % 10), num /= 10;
    
    //Rebuild the sum.
    int ten {1};
    while(!is_empty()) 
        num += peek() * ten, ten *= 10, pop();
    
    return num;
}
void Stack::reserve_display() {
    Stack reverse(size);
    for(int i = index; i < size; ++i) 
        reverse.push(arr[i]);
    reverse.display();
}

void Stack::insert_at_bottom(int num) {
    if(is_empty())
        push(num);
    else {
        int t = peek();
        pop();
        insert_at_bottom(num);
        push(t);
    }
}

void Stack::reverse() {
    if(is_empty()) 
        return;
    
    int t = peek();
    pop();
    reverse();
    insert_at_bottom(t);
    
}
