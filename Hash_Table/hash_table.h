#pragma once
#include <vector>
#include <list>
#include <string>

class HashTable{
    public:
        int BUCKET{};
        std::vector<std::list<std::string>> table{};

        HashTable(int b);
        int hashFunction(const std::string &x);
        void insertItem(const std::string &key);
        bool searchItem(const std::string &key);
};