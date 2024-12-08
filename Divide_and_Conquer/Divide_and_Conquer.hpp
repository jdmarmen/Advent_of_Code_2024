#pragma once

#include <vector>

class MergeSort{
    public:
    MergeSort();
    static void merge(std::vector<int>* vector,int start,int mid,int end);
    static void merge_sort(std::vector<int>* arr, int start, int end);
};