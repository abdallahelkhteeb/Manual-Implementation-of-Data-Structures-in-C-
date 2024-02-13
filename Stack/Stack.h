#ifndef STACK_H
#define STACK_H

#pragma once

class Stack {
private:
    int *arr;
    int index{};
    int size{0};
    int capacity{0};
public:
    Stack(int size) : size{size}, capacity {5 * size} , index{size}{
        arr = new int(capacity); //O(n)
    };
    ~Stack() = default; //O(n)
    bool push(int num);
    bool push(char c);
    bool is_full();
    bool is_empty();
    bool pop();
    // char peek();
    int peek();
    void display() const; //O(n)
    void dispaly_and_pop();
    void display_string();
    int reverse_num(int num);
    void reserve_display();
    void insert_at_bottom(int num);
    void reverse();
    


};

#endif