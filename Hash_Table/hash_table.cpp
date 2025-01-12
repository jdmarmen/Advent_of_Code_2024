#include "hash_table.h"

HashTable::HashTable(int b){
    BUCKET=b;
    table.resize(BUCKET);
}

int HashTable::hashFunction(const std::string &x){
    int hash=0;
    for(char c:x){
        hash=(hash*31+c)%BUCKET;
    }
    return hash;
}

void HashTable::insertItem(const std::string &key){
    int index=hashFunction(key);
    table[index].push_back(key);
}

bool HashTable::searchItem(const std::string &key){
    int index=hashFunction(key);
    for(const auto &x:table[index]){
        if(x==key)
            return true;
    }
    return false;
}