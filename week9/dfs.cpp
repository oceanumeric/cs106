/*
Depth First Search Algorithm 
*/
#include<iostream>
#include<map>
#include<vector>


class Graph {
    public:
        Graph(int v);  // constructor 
        ~Graph();  // destructor 
        void add_edge(int v, int w);
        void dfs(int v);
        void detect_cycle(int v);
        bool cycle_present;
    private:
        int vertices;
        int edges;
        std::map<int, bool> visited_dfs;  // we need two maps to mark the visited
        std::map<int, bool> visited_cycle;  // otherwise, after running dfs all will be visited 
        std::map<int, bool> rec_stack;
        std::map<int, std::vector<int>> adj;
};


Graph::Graph(int v) {
    vertices = v;
    edges = 0;
    for (int i = 0; i < vertices; i++) {
        visited_dfs[i] = false;
        visited_cycle[i] = false;
        rec_stack[i] = false;
    }
    cycle_present = false;
}

Graph::~Graph() {
    edges = 0;
    visited_dfs.clear();
    visited_cycle.clear();
    adj.clear();
}

void Graph::add_edge(int v, int w) {
    // undirected graph 
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::dfs(int v) {
    visited_dfs[v] = true;
    std::cout << v << " ";
    for (auto elem : adj[v]) {
        if (!visited_dfs[elem]) {
            dfs(elem);  // visit all nodes recursively 
        }
    }
}

void Graph::detect_cycle(int v) {
    visited_cycle[v] = true;
    rec_stack[v] = true;
    for (auto elem : adj[v]) {
        if (rec_stack[elem]) {
            cycle_present = true;
            return;
        } else if (!visited_cycle[elem]) {
            detect_cycle(elem);
        }
    }
    // Before we backtrack unset the flag for the src vertex as it will
    // not be in the next traversal path
    rec_stack[v] = false;  // remove the vertices from the recursive stack
}

int main() {
    Graph g1 = Graph(9); 
    g1.add_edge(0, 1);
    g1.add_edge(0, 3);
    g1.add_edge(0, 8);
    g1.add_edge(1, 0);
    g1.add_edge(1, 7);
    g1.add_edge(2, 3);
    g1.add_edge(2, 5);
    g1.add_edge(2, 7);
    g1.add_edge(3, 0);
    g1.add_edge(3, 4);
    g1.add_edge(3, 2);
    g1.add_edge(4, 3);
    g1.add_edge(4, 8);
    g1.add_edge(5, 2);
    g1.add_edge(5, 6);
    g1.add_edge(6, 5);
    g1.add_edge(7, 1);
    g1.add_edge(7, 2);
    g1.add_edge(8, 0);
    g1.add_edge(8, 4);
    g1.dfs(0);
    g1.detect_cycle(0);
    if (g1.cycle_present) {
        std::cout << "There is a cycle starting from vertice 0\n";
    }
    return 0;
}
