#ifndef DLL_H
#define DLL_H

#pragma once

struct Node {
    /* data */
    int data;
    Node *next {};
    Node *prev {};
    Node(int data = 0) : data{data} {
    };
};

class Dll
{
private:
    Node *head {};
    Node *tail {};
    int length {0}; // the same logic as SLL
public:
    void link_nodes(Node *first, Node *second);
    void insert_front(int value);
    void insert_end(int value);
    void print() const;
    void print_reversed() const;//that
    void insert_sorted(int value);
    void embaded_after(int value, Node *node);
    bool delete_front();
    bool delete_end();
    bool delete_node(Node *node);
    bool delete_key(int value);
    void delete_all_nodes_with_key(int value);
    void delete_even_pos();
    void delete_odd_pos();
    bool is_palindrome();
    void delete_and_link(Node *node);
    int find_the_middle();
    void swap_farward_with_back(int k);
    void reverse();
    void merge_2_sorted_lists(const Dll &b);
    void insert_before(int value, Node *temp);
};

#endif