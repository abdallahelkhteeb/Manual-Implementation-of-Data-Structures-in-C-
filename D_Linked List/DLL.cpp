#include "DLL.h"
#include <iostream>


void Dll::link_nodes(Node *first, Node *second) {
    if(first)
        first->next = second; 
    if(second)
         second->prev = first;
}

void Dll::insert_front(int value) {
    Node *temp = new Node (value);
    if(!head) 
        head = tail = temp;
    else {
        link_nodes(temp, head);
        head = temp;
    }
    length++;
}
void Dll::insert_end(int value) {
    Node *temp = new Node(value);
    if(!head) 
        head = tail = temp;
    else {
        link_nodes(tail, temp);
        tail = temp;
    }
    length++;
}
void Dll::embaded_after(int value, Node *node) {
    Node *temp = new Node(value);
    Node *next = node->next;

    link_nodes(node, temp);

    link_nodes(temp, next);
    length++;
}
void Dll::insert_sorted(int value) {
    if(value <= head->data)
        insert_front(value);
    else if(value >= tail->data)
        insert_end(value);
    else {//the data is before the final
        for(Node *cur = head; cur; cur = cur->next) {
            if(cur->data >= value)
                embaded_after(value, cur->prev);
        }
    }
}
void Dll::print() const{
    for(Node *cur = head; cur; cur = cur->next) 
        std::cout << cur->data << ' ';
    std::cout << std::endl;
}

void Dll::print_reversed() const {
    for(Node *cur = tail; cur; cur = cur->prev) 
        std::cout << cur->data << ' ';
    std::cout << std::endl;
}
bool Dll::delete_front() {
    if(!head)
        return 0;
    Node *temp = head->next;
    delete_node(head);
    head = temp;

    if(head)
        head->prev = nullptr;
    if(!length)
        tail = nullptr;
    return 1;
}
bool Dll::delete_end() {
    if(!tail)
        return 0;
    Node *temp = tail->prev;
    delete_node(tail);
    tail = temp;

    if(tail)
        tail->next = nullptr;
    if(!length)
        head = nullptr;
    return 1;
}
bool Dll::delete_node(Node *node) {
    if(!node)
        return 0;
    delete node;
    length--;
    return 1;
}

bool Dll::delete_key(int value) {
    if(!length)
        return false;
    if(head->data == value) {
        delete_front();
        return 1;
    }
    else if(tail->data == value) {
        delete_end();
        return 1;
    }
    else {
        for(Node *cur = head; cur; cur= cur->next) {
            if(cur->data == value) {
                link_nodes(cur->prev, cur->next);
                delete_node(cur);
                return 1;
            }
        }
    }
    return 0;
}

void Dll::delete_all_nodes_with_key(int value) {
    for(Node *cur = head; cur;) {
        if(cur->data == value) {
            Node *temp = cur;
            cur = cur->next;
            link_nodes(temp->prev, temp->next);
            if(!cur)
                tail = temp->prev;
            delete_node(temp);

        } else
            cur = cur->next;
    }
}
void Dll::delete_and_link(Node *node) {
    link_nodes(node->prev, node->next);
    delete_node(node);
}
void Dll::delete_even_pos() {
    if(!head)
        return;
    for(Node *cur = head; cur && cur->next; cur = cur->next) {
        delete_and_link(cur->next);
        if(!cur->next)
            tail = cur;
    }
}
void Dll::delete_odd_pos() {
    insert_front(-1);
    delete_even_pos();
    delete_front();
}
bool Dll::is_palindrome() {
    if(!length)
        return 0;
    if(length == 1)
        return 1;
    Node *cur_head = head, *cur_tail = tail;
    int len = length/2;
    while(len--) {
        if(cur_head->data != cur_tail->data)
            return 0;
        cur_head = cur_head->next;
        cur_tail = cur_tail->prev;
    }
    return 1;
}
int Dll::find_the_middle() {
    if(length == 0)
        return -1;
    for(Node *cur_head = head, *cur_tail = tail;;cur_head = cur_head ->next, cur_tail = cur_tail->prev) {
        if(cur_head == cur_tail || cur_head->next == cur_tail)
            return cur_tail->data;
    }
}
/*
vector<node> nodes;
loop 
    vector.push_back
    and 
    return vector[vector.size()/2]

*/
void swap(Node *first, Node *second) {
    std::swap(first, second);
    std::swap(first->data, second->data);
}
void Dll::swap_farward_with_back(int k) {
    if(length <= 1)
        return;
    k = (k > length/2)? (length + 1 - k) : k;
    for(Node *cur_head = head, *cur_tail = tail;;cur_head = cur_head ->next, cur_tail = cur_tail->prev, k--) {
        if(k == 1) {
            swap(cur_head, cur_tail);
            if(tail == cur_head) {
                tail = cur_head;
                head = cur_tail;
            }
            break;
        }
    }
}
void Dll::reverse() {
    if(!head)
        return;
    for(Node *cur = head, *prev = nullptr; cur; prev = cur, cur = cur->prev) {
        cur->prev = cur->next;
        cur->next = prev;        
    }
    std::swap(head, tail);
}
void Dll::insert_before(int value, Node *cur) {
    Node *t = new Node (value);
    if(!head) {
        head = tail = t;
    } else if(cur == head) {
        insert_front(value);
    } else {
        Node *prev = cur->prev;
        link_nodes(prev, t);
        link_nodes(t, cur);
    }   
}
void Dll::merge_2_sorted_lists(const Dll &b) {
    if(b.length == 0)
        return;
    Node *cur1 = head, *cur2 = b.head;
    while(cur2) {
        if(cur1) {
            //the smaller value has the priority
            if(cur1->data < cur2->data)
                cur1 = cur1->next;
            else {
                insert_before(cur2->data, cur1);
                cur2 = cur2->next;
            }
        } else {
            link_nodes(this->tail, cur2);
            tail = b.tail;
            break;
        }
    }
    length += b.length;
}