#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#pragma once

#include <bits/stdc++.h>
using namespace std;

bool justonce = true;
struct node{
    int data;
    node *next{};
    node(int data) : data{data}{};
};

class Linked_List{
private:
    node *head {};
    node *tail{nullptr};
    int length{0};
public:
    void print();
    void insert_end(int n);
    node *get_nth(int n);
    int search(int n);

    ~Linked_List();
    void insert_front(int n);
    void delete_front();
    node *get_nth_back(int n);
    bool is_same(const Linked_List &list);
    int get_length();
    bool delete_node(int idx);
    int get_index(int data);
    bool delete_key(int value);
    void swap_two();
 
    void reverse();
    void delete_even();
    void sort();
    void embadded(node *n, int value);
    void insert_to_be_sorted(int value);
    void swap_head_tail();
    void rotate_left(int k);
    void delete_duplicated();
    bool remove_last(int value);
    void move_back(int value); 
    int max(node *head = nullptr, bool is_first = true);
    void insert_in(const node *n, node *prev);
    void delete_prev(node *prev);
    void arrange_odd_even ();
    void insert_alternate(Linked_List &another);
    void add_num(Linked_List &another);
    void RemoveDuplicated();
    void reverse(int k);
        
};


#endif