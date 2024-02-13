#include "Trie.h"
void Trie::insert(std::string s, int idx) {
    if(idx == s.size())
        isLeaf = 1;
    else {
        int cur = s[idx] - 'a';
        if(!child[cur])
            child[cur] = new Trie();
        child[cur]->insert(s, ++idx);
    }
}
bool Trie::find_word(std::string word, int idx) {
    if(idx == word.size() && isLeaf) 
        return isLeaf;
    
    int cur = word[idx] - 'a';
    if(!child[cur])
        return 0;
    return child[cur]->find_word(word, ++idx);
}

bool Trie::find_prefix(std::string prefix, int idx) {
    if(idx == prefix.size())
        return 1;
    int cur = prefix[idx] - 'a';
    if(!child[cur])
        return 0;
    return child[cur]->find_prefix(prefix, ++idx);
}

void Trie::insert_iterative(std::string s, int idx) {
    Trie *cur = this;
    while(idx < s.size()) {
        int ch = s[idx] - 'a';
        if(cur->child[ch] == 0)
            cur->child[ch] = new Trie();
        cur = cur->child[ch];
        idx++;
    }
    cur->isLeaf = 1;
}


bool Trie::find_word_iterative(std::string s, int idx) {
    Trie *cur = this;
    while(idx < s.size()) {
        int ch = s[idx] - 'a';
        if(cur->child[ch] == 0)
            return 0;
        cur = cur->child[ch];
        idx++;
    }
    return cur->isLeaf;
}


std::string Trie::minimalPrifex(std::string s, int idx) {
    Trie *cur = this;
    std::string ans {""};
    while(idx < s.size()) {
        int ch = s[idx] - 'a';
        if(!cur->child[ch])
            return s;
        ans += s[idx];
        cur = cur->child[ch];
        if(cur->isLeaf)
            return ans;
        
        idx++;
    }
    return s;
}


bool Trie::is_suffix(std::string s, int idx) {
    bool res = (idx == s.size() && this->isLeaf);
    if(this->isLeaf)
        idx = 0;
    int ch = s[idx] - 'a';
    for(int i = 0; i < MAX_CHAR && !res; ++i) {
        if(child[i]) {
            if(i == ch) 
                res = child[i]->is_suffix(s, idx + 1);
            if(!res)
                res = child[i]->is_suffix(s, 0);
        }
    }
    return res;
}

void Trie::get_all_results(std::vector<std::string> &res, std::string s) {
    if(isLeaf)
        res.push_back(s);
    for(int i = 0; i < 26; ++i) {
        if(child[i]) {
            char ch = i + 'a';
            child[i]->get_all_results(res, s + ch);
        }
    }
}
Trie *Trie::get_prefix(std::string s, int i) {
    Trie *cur = this;
    while(i < s.size()) {
        int ch = s[i] - 'a';
        if(!cur->child[ch])
            return nullptr;
        cur = cur->child[ch];
        i++;
    }
    return cur;
}   

void Trie::auto_complete(std::vector<std::string> &res, std::string s) {
    Trie *tmp = get_prefix(s);
    if(!tmp)
        return;
    tmp->get_all_results(res, s);
}

bool Trie::word_exist_with_1_change(std::string str, int i, int change) {
    bool res = (i == str.size() && change == 1 && isLeaf);
    if(i == str.size())
        return res;
    for(int j = 0; j < MAX_CHAR && !res; ++j) {
        if(child[j]) {
            if(j  + 97 == str[i])
                res = child[j]->word_exist_with_1_change(str, i + 1, change);
            else if(change == 0)
                res = child[j]->word_exist_with_1_change(str, i + 1, change + 1);
        }
    }
    return res;
}

std::string Trie::find_substr(std::string s, int i, std::string out) {
    std::string res = "";
    if(out == s)
        return res = out;
    
    for(int j = 0; j < 26 && res.empty(); ++j) {
        if(child[j]) {
            if(s[i] == (j + 'a'))
                return child[j]->find_substr(s, i + 1, out + (char) (j + 'a'));
            else 
                return child[j]->find_substr(s, i, "");
        }
    }
    return res;
}