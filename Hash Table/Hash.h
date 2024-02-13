#ifndef HASH_H
#define HASH_H

#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Hash
{
private:
    static const int SZ = 13;
    vector<int> table[SZ];

public:
    int hash(const string &key); 
    int folder_hash(const string &key);
    void set(const string &key, int val);
    int get(const string &key);
    // int hash(int key);
    // void set(int key, int val);
    // int get(int key, int val);
    void printTable();
    void rehashing();

};

#endif