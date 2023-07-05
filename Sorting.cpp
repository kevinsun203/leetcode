#include <vector>
#include <algorithm>
#include "iostream"

// Select pivot, shuffle it around and return the pivot index
int selectAndShuffle(std::vector<int>& a, int begin, int end) {
    int pivotValue = a[begin]; // pick first index as pivot. Can also pick any arbitrary index and swap it with the first element
    int current = begin;

    for (int i=begin+1; i<=end; i++) {
        if (a[i] < pivotValue) {
            current++;
            std::swap(a[current], a[i]);
        }
    }
    std::swap(a[begin], a[current]);
    return current;
}

void qsort(std::vector<int>& a, int begin, int end) {
    int pivotIndex = selectAndShuffle(a, begin, end);
    if (pivotIndex - 1 > begin) {
        qsort(a, begin, pivotIndex-1);
    } 
    if (pivotIndex + 1 < end) {
        qsort(a, pivotIndex+1, end);
    }

    return;
}

int main() {
    std::vector<int> toSort = {1,4,5,2,3,-1,0};
    qsort(toSort, 0, toSort.size()-1);

    for (int i=0; i<toSort.size(); i++) {
        std::cout << toSort[i] << std::endl;
    }

    return 0;
}