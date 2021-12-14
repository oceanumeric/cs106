/*
The subset-sum problem
The inclusion/exclusion pattern 
*/
#include <iostream>
#include <set> 


// do not use reference operator & 
bool subsetSumExists(std::set <int> s, int target); 


int main () {
    std::cout << "Please construct your set by enter integers" << std::endl; 
    std::set <int> s; 

    char answer;  // to switch off the while loop 

    while (answer != 'y') {
        int n;
        std::cout << "Please enter an integer: ";
        std::cin >> n; 
        s.insert(n); 
        std::cout << "Would you like to stop entering a new value?"; 
        std::cin >> answer; 
    }

    std::cout << "This is your set: {"; 
    for (auto elem : s) {
        std::cout << elem << " ,";   
    }
    std::cout << " }" << std::endl; 

    std::cout << "Now, let's test the subsetSumExists problem: " << std::endl; 

    int target; 

    std::cout << "Please enter the target value: "; 
    std::cin >> target; 

    if (subsetSumExists(s, target)) {
        std::cout << "There IS a subset of those integers whose sum is equal to";
        std::cout << " " << target << std::endl; 
    } else {
        std::cout << "There is NO subset of those integers whose sum is equal to";
        std::cout << " " << target << std::endl; 
    }
}


bool subsetSumExists(std::set <int> s, int target) {
    if (s.empty()) {
        return target == 0; 
    } else {
        auto it = s.begin(); 
        int elem = *it; 
        s.erase(it);  // erase based on position  
        return subsetSumExists(s, target) || subsetSumExists(s, target-elem); 
    }
}