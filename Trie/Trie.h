#ifndef TRIE_H
#define TRIE_H

#pragma once
#include <vector>
#include <cstring>
#include <string>
class Trie
{
private:
    static const int MAX_CHAR {26};
    Trie *child[MAX_CHAR];
    bool isLeaf {}; 
public:
    Trie() {
        memset(child, 0, sizeof(child));
    }
    void insert(std::string s, int idx = 0);
    bool find_word(std::string word, int idx = 0);
    bool find_prefix(std::string prefix, int idx = 0);
    void insert_iterative(std::string s, int idx = 0);
    bool find_word_iterative(std::string s, int idx = 0);
    std::string minimalPrifex(std::string s, int idx = 0);
    bool is_suffix(std::string s, int idx = 0);
    void get_all_results(std::vector<std::string> &res, std::string s = "");
    void auto_complete(std::vector<std::string> &res, std::string s = "");
    Trie* get_prefix(std::string s, int i = 0);
    bool word_exist_with_1_change(std::string str, int i = 0, int changes = 0);
    std::string find_substr(std::string s, int i = 0, std::string out = "");
    void list_substrs(const std::string& str, std::vector<std::string> &queries) {
        this->insert_iterative(str);
        for(int i = 0; i < queries.size(); ++i) {
            std::cout << find_substr(queries[i]) << std::endl;
        }
    }

};

#endif