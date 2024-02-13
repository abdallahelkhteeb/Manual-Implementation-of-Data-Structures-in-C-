#include "Hash.h"
int Hash::hash(const string &key) {
    int h = 0;
    for(int i = 0; i < key.size(); ++i) 
        h = ((int) key[i] + h * 23) % SZ;
    
    return h % SZ;
}

void Hash::set(const string &key, int val) {
    int idx = hash(key);
    if(!table[idx].size()) {
        table[idx].push_bacl;
    } else {
      
    }
}

void Hash::printTable() {
    for(int i = 0; i < SZ; ++i) {
        Node<string, int>*head= Data_Map[i];
        std::cout << i << ":\n";
        while(head) {
            std::cout << "\t{" << head->key << "," << head->val << "}\n";
            head = head->next;
        }
    }
}

int Hash::get(const string &key) {
    int idx = hash(key);
    Node<string, int> *head = Data_Map[idx];
    while(head) {
        if(head->key == key)
            return head->val;
    }

    set(key, 0);
    return 0;
}


int Hash::folder_hash(const string &s) {
    int h {}, cnt {};
    for(int i = 0; i < s.size(); ++i) {
        if(i % 4 == 0) {
            h = (h + cnt) % SZ;
            cnt = (s[i] % SZ);
        } else 
            cnt = (cnt * 23 + s[i]) % SZ;
    }
    return (h + cnt) % SZ;
}



void Hash::rehashing() {
    int sz = 2 * SZ;
    vector<int> table2[sz];
    for(int i = 0; i < SZ; ++i) {
        for(auto &a : table[i])
            table2[i].push_back(a);
    }
}

















// int Hash::hash(int key) {
//     return key % SZ;
// }

// void Hash::set(int key, int val) {
//     int idx = hash(key);
//     if(!Data_Map[idx]) {
//         Data_Map[idx] = new Node(key, val);
//     } else {
//         Node<int, int>* head = Data_Map[idx];
//         while(head->next) {
//             if(head->key == key) {
//                 head->val = val;
//                 return;
//             }
//             head = head->next;
//         }
//         head->next = new Node(key, val);
//     }
    
// }

// int Hash::get(int key, int val) {
//     int idx = hash(key);
//     Node<int, int> *head = Data_Map[idx];
//     while(head) {
//         if(head->key == key)
//             return head->val;
//     }

//     set(key, 0);
//     return 0;
// }