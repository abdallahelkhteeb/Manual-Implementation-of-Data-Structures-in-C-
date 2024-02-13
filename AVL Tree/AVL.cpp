#include "AVL.h"

// Node *AVL::right_ratation(Node *node) {
//     Node *p = node->left;
//     node->left = p->right;
//     p->right = node;
//     update_height(p);
//     update_height(node);    
//     return p;

// }
// Node *AVL::left_rotation(Node *node) {
//     Node *p = node->right;
//     node->right = p->left;
//     p->left = node;
//     update_height(p);
//     update_height(node);    
//     return p;
// }

// Node *AVL::balance(Node* node) {
//     if(balance_factor(node) == -2) {
//         if(balance_factor(node->right) == 1)
//             right_ratation(node->right);
//         left_rotation(node);
//     } else if(balance_factor(node) == 2) {
//         if(balance_factor(node->left) == -1)
//             left_rotation(node->left);
//         right_ratation(node);
//     }
//     return node;
// }
// Node *AVL::insert(int target) {
//     if(!root)
//         root = new Node(target);
//     else 
//         insert(root, target);
// }
std::pair<int, bool> AVL::lower_bound(int target, Node *cur) {
    if(!cur)
        return {INT_MIN, 1};
    if(target == cur->val)
        return {target, 1};
    
    std::pair<int, bool> res = {INT_MIN, 0};

    if(target < cur->val)
        res = lower_bound(target, cur->left);
    
    if(res.first == INT_MIN && res.second) 
        res.first = cur->val;
    

    if(!res.second && target > cur->val)
        res = lower_bound(target, cur->right);

    return res;
}
void AVL::print_inOrder(Node *node) {
    if(node->left)
        print_inOrder(node->left);
    
    std::cout << node->val << ' ';

    if(node->right)
        print_inOrder(node->right);
}