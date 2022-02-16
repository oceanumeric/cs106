## Graph 

### Definition

A graph consists of: a set of vertices (or nodes) a list (collection) of edges (or links) between two vertices of the graph. G = (V, E), for instance:
```
G1 = (V1, E1); V1 = {0, 1, 2, 3 4}; E1 = {(0, 1), (1, 2), (2, 0), (3, 4)}. 
```

### Properties of Graphs

Let G be a simple undirected graph with n vertices and m edges, then 
```r
m <= choose(2, n)  # m <= n(n-1)/2 or |E| = O(|V|^2) 
```
If a (undirected) graph G has m edges then: 
```
sum of deg(v) = 2m
```
If a directed graph G has m edges then: 
```
sum of indeg(v) = outdeg(v) = m 
```

### Data Sctructure

Commonly used data structures for graphs:
* Adjacency list: running time - O(m+n)
* Adjacency matrix: running time - O(n^2)

When a graph has a large number of edges, we will have m ~= n × n. Then no matter which representation you choose, the running time will be O(n × n)


### BFS 

The BFS algorithm is more akin to sending out, in all directions. 

### DFS 

The DFS follows one specific path for reaching to the end before exploring other vertices. 


### C++ Tips

```cpp
std::vector<int>* adj;  // a pointer to an an array that containing adjancy lists
adj = new std::vector<int>[V];  // array with size of V 
```

In C++, there is near to no distinction between arrays and pointers
```cpp
#include <iostream>
using namespace std;


void change_last(int array[]) {
    array[6] = 9;
}


int main()
{
    int size = 7;
    int array1[size]; 
    for (int i = 0; i < size; i++) {
        array1[i] = 0;
    }
    
    change_last(array1);
    
    cout << array1[6] << "\n";  // it will print 9 
}

```

### References:

* https://www.algotree.org/algorithms/tree_graph_traversal/depth_first_search/cycle_detection_in_directed_graphs/
