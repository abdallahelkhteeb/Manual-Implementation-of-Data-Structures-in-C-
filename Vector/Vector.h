#ifndef VECTOR_H
#define VECTOR_H

#pragma once
/*
Challenge:
    1-right_shift
    2-left shift
    3-shift with num of times
    4-deleteing position
    5-transposition to the left after finding the element
*/
class Vector
{
private:
    int *a {nullptr};
    int size{0};
    int capacity{0};

public:

    Vector(int size); 
    void right_rotation();
    void left_rotation();
    void right_rotation(int num);
    void pop(int idx);
    int find_transpotion(int num);//left rotation
    int get(int index) const;
    void expand_capacity();
    void print() const;
    int find(int num) const;
    void AddNumber(int number);
    void insert(int num, int index);
    bool set(int index, int num);
    int &operator[](int idx);
    ~Vector();

};

#endif