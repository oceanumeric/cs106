/*
To review the sort algorithm
Sequence structure (property of position): 
    set, array, linked list, dynamic array
        static: get at
        dynamic: insert or delete at 
Sorted sequence: leverage binary search to find element (property of elements)
*/
#include<iostream>
#include<vector>


/* selection sort
Find a largest number in prefix A[:i] and swap it to A[i-1]
*/

int prefix_max(std::vector<int> &v, int i) {
    /*Return index of maximum in A[:i]*/
    int j = 0; 
    if (i > 0) {
        j = prefix_max(v, i-1); 
        if (v[i] < v[j]) {
            return j; 
        }
    }
    return i; 
}


void selection_sort(std::vector<int> &v, int i=-1) {
    if (i == -1) i = v.size() - 1; 
    if (i > 0) {
        int j = prefix_max(v, i); 
        int temp = v[j]; 
        v[j] = v[i];
        v[i] = temp; 
        selection_sort(v, i-1); 
    }
}


void insert_last(std::vector<int> &v, int i) {
    if (i > 0 && v[i] < v[i-1]) {
        int temp = v[i-1];
        v[i-1] = v[i];
        v[i] = temp; 
        insert_last(v, i-1); 
    }
}


void insertion_sort(std::vector<int> &v, int i=-1){
    if (i == -1) i = v.size() -1 ; 
    if (i > 0) {
        insertion_sort(v, i-1); 
        insert_last(v, i); 
    }
}


int main() {
    std::vector<int> vtest{8, 2, 4, 9, 3};
    selection_sort(vtest); 
    for (int elem : vtest) {
        std::cout << elem << " "; 
    }
    std::vector<int> vtest2{8, 2, 4, 9, 3};
    insertion_sort(vtest2); 
    for (int elem : vtest2) {
        std::cout << elem << " "; 
    }
}
