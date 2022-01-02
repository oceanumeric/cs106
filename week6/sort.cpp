/*
Sorting algorithms 
*/
#include<iostream>
#include<vector>


void print_vector(std::vector<int> & v);
std::vector<int> insertion_sort(std::vector<int> v);
std::vector<int> selection_sort(std::vector<int> v);
void vector_split(std::vector<int> v);
void merge_sort(std::vector<int> &v);
void merge(std::vector<int> &vec, std::vector<int> &v1, std::vector<int> &v2);

std::vector<int> merge_sort2(std::vector<int> v);
std::vector<int> merge2(std::vector<int> v1, std::vector<int> v2);

std::vector<int> quick_sort(std::vector<int> v);


int main() {

    std::vector<int> v1 {4, 5, 9, 10, 2, 1, 12};
    std::cout << "Insertion Sort: ";
    std::vector<int> isv = insertion_sort(v1);
    print_vector(isv);
    std::cout << "Selection Sort: ";
    std::vector<int> ssv = selection_sort(v1);
    print_vector(ssv);
    std::cout << "Merge Sort: ";
    std::vector<int> ms = merge_sort2(v1);
    print_vector(ms);
    std::cout << "Quick Sort: ";
    std::vector<int> qs = quick_sort(v1);
    print_vector(qs);
    std::cout << "Merge sort in place: ";
    merge_sort(v1);
    print_vector(v1);

    return 0; 
}


void print_vector(std::vector<int> & v) {
    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " "; 
    }
    std::cout << "]\n";
}


std::vector<int> insertion_sort(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        int temp = v[i];
        int j = i; 
        while (j >= 1 && v[j-1] > temp) {
            v[j] = v[j-1];
            j--;  // 
        }
        v[j] = temp; 
    }

    return v; 
}


std::vector<int> selection_sort(std::vector<int>  v) {
    for (int i = 0; i < v.size(); i++) {
        // find the index of the smallest value 
        int min = i; 
        for (int j = i+1; j < v.size(); j++) {
            if (v[j] < v[min]) {
                min = j; 
            }
        }
        // swap the value 
        if (i != min) {
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }

    return v;
}


void vector_split(std::vector<int> v) {
    // divide -> sort -> merge 
    int n= v.size();
    if (n <= 1) std::cout << "Null\n";
    // Divide: merge sort takes more space 
    std::vector<int> v1;
    std::vector<int> v2; 
    for (int i = 0; i < n; i++) {
        if (i < n/2) {
            v1.push_back(v[i]);
        } else {
            v2.push_back(v[i]);
        }
    }
    print_vector(v1);
    print_vector(v2);
}


void merge_sort(std::vector<int> &v) {
    // divide -> sort -> merge 
    int n= v.size();
    if (n <= 1) return;
    // Divide: merge sort takes more space 
    std::vector<int> v1;
    std::vector<int> v2; 
    for (int i = 0; i < n; i++) {
        if (i < n/2) {
            v1.push_back(v[i]);
        } else {
            v2.push_back(v[i]);
        }
    }
    // call the fuction recursively
    merge_sort(v1);
    merge_sort(v2);
    v.clear();
    merge(v, v1, v2);
}


void merge(std::vector<int> &vec, std::vector<int> &v1, std::vector<int> &v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    int p1 = 0;
    int p2 = 0;
    while (p1 < n1 && p2 < n2) {
        if (v1[p1] <= v2[p2]) {
            vec.push_back(v1[p1++]);
        } else {
            vec.push_back(v2[p2++]);
        }
    }
    // add other values 
    while (p1 < n1) {
        vec.push_back(v1[p1++]);
    }
    while (p2 < n2) {
        vec.push_back(v2[p2++]);
    }
}


std::vector<int> merge_sort2(std::vector<int> v) {
    int n = v.size();
    // base case 
    if (n <= 1) return v; 
    std::vector<int> v1; 
    std::vector<int> v2; 
    // partition 
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            v1.push_back(v[i]);
        } else {
            v2.push_back(v[i]);
        }
    }
    // call function recursively 
    v1 = merge_sort2(v1);
    v2 = merge_sort2(v2);

    return merge2(v1, v2);
}



std::vector<int> merge2(std::vector<int> v1, std::vector<int> v2) {
    std::vector<int> mv; 
    int n1 = v1.size();
    int n2 = v2.size();
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < n1 && idx2 < n2) {
        if (v1[idx1] <= v2[idx2]) {
            mv.push_back(v1[idx1++]);
        } else {
            mv.push_back(v2[idx2++]);
        }
    }
    // merge other values 
    while (idx1 < n1) {
        mv.push_back(v1[idx1++]);
    }

    while (idx2 < n2) {
        mv.push_back(v2[idx2++]);
    }

    return mv; 
}


std::vector<int> quick_sort(std::vector<int> v) {
    int n = v.size();
    if (n < 2) return v;
    int pivot = v[0];  // chose a pivot 

    std::vector<int> left, right;
    
    for (int i = 1; i < n; i++) {  // i = 1 
        if (v[i] <= pivot) {
            left.push_back(v[i]);
        } else {
            right.push_back(v[i]);
        }
    }

    left = quick_sort(left);
    right = quick_sort(right);

    left.push_back(pivot);

    left.insert(left.end(), right.begin(), right.end());

    return left;
}
