#include "Divide_and_Conquer.hpp"

MergeSort::MergeSort(){}

void MergeSort::merge(std::vector<int>* vector,int start,int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = (*vector)[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = (*vector)[mid + 1 + j];

    int i = 0, j = 0;
    int k = start;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            (*vector)[k] = L[i];
            i++;
        }
        else {
            (*vector)[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        (*vector)[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        (*vector)[k] = R[j];
        j++;
        k++;
    }
}


void MergeSort::merge_sort(std::vector<int>* arr, int start, int end){
    if(start<end){
        int mid=start+(end-start)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }

}