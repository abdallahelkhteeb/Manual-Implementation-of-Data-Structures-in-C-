#ifndef AVL_H
#define AVL_H

#pragma once
#include <utility>
#include <algorithm>
class AVL {
private:
    struct Node {
        int val {};
        int height {};
        Node *left {nullptr};
        Node *right {};
        Node(int def_val = 0, int def_height = 0, Node *def_left = nullptr
        ,Node *def_right = nullptr) : val {def_val}, height {def_height}, left {def_left}
        , right {def_right} {};
    };
    Node *root {};

    Node *insert(Node *node, int target) {
        if(target > node->val) {
            if(node->right)
                node->right = insert(node->right, target);
            else
                node->right = new Node(target);
        } else if(target < node->val) {
            if(node->left)
                node->left = insert(node->left, target);
            else
                node->left = new Node(target);
        }
        update_height(node);
        return balance(node);
    }

   
    std::pair<int, bool> lower_bound(int target, Node *cur);
    void print_inOrder(Node *node);
public:
    int ce_height(Node *cur) {
        if(!cur)
            return -1;
        return cur->height;
    }
    void update_height(Node *cur) {
        cur->height = 1 + std::max(ce_height(cur->left), ce_height(cur->right));
    }
    int balance_factor(Node *cur) {
        return ce_height(cur->left) - ce_height(cur->right);
    }
    Node *right_ratation(Node *node){
        Node *p = node->left;
        node->left = p->right;
        p->right = node;
        update_height(p);
        update_height(node);    
        return p;

    }
    Node *left_rotation(Node *node){
        Node *p = node->right;
        node->right = p->left;
        p->left = node;
        update_height(p);
        update_height(node);    
        return p;
    }
    Node *balance(Node *node){
        if(balance_factor(node) == -2) {
            if(balance_factor(node->right) == 1)
                right_ratation(node->right);
            node = left_rotation(node);
        } else if(balance_factor(node) == 2) {
            if(balance_factor(node->left) == -1)
                left_rotation(node->left);
            node = right_ratation(node);
        }
        return node;
    }
    void insert(int target) {
        if(!root)
            root = new Node(target);
        else 
            root = insert(root, target);
    }
    int lower_bound(int target) {
        std::pair<int, bool> res = lower_bound(target, root);
        if(res.first != INT_MIN)
            return res.first;
        else 
            return -1;
    }
    void print_inOrder() {
        if(root)
            print_inOrder(root);
        std::cout << '\n';
    }
    int upper_bound(int target) {
        std::pair<int, bool> res = lower_bound(target + 1, root);
        if(res.first != INT_MIN)
            return res.first;
        else 
            return -1;
    }
    
};

#endif