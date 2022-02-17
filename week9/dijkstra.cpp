#include <iostream>
#include <list>
#include <utility>
#include <set>
#include <vector>
#define INF 0x3f3f3f3f  // heximal number for  1061109567

/*
The set works as the priority queue which prioritize the vertice
with the minimum distance 
*/

class Graph {
    int V;  // number of vertices 
    std::list< std::pair<int, int>> *adj;  // <node weight>

    public:
        Graph(int vertices);  // constructor  
        ~Graph();  // destructor 
        void add_edge(int u, int v, int w);
        void shortest_path(int s);
        void print_path(std::vector<int> parent, int j);
}; 


Graph::Graph(int vertices) {
    V = vertices;
    adj = new std::list<std::pair<int, int>>[V];
}

Graph::~Graph() {
    delete[] adj; 
}

void Graph::add_edge(int u, int v, int w) {
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
}

void Graph::print_path(std::vector<int> parent, int j) {
    // base case 
    if (parent[j] == -1) {
        return;
    }
    print_path(parent, parent[j]);
    std::cout << j << " ";
}

void Graph::shortest_path(int src) {
    // set to store vertices that are being visited <vertice, weight>
    std::set<std::pair<int, int>> setds; 
    // a vector for distances and initialize all distances as infinite 
    std::vector<int> dist(V, INF);
    // a vector for storing path
    std::vector<int> parent(V, -1);

     // set maintains the elements in ascending order
    // That's why we did s.insert({d[v],v}); and not s.insert({v,d[v]});
    // by default the pairs are sorted by the first value
    // (if the first values are equal then by the second value)

    setds.insert(std::make_pair(0, src));
    dist[src] = 0;

    while (!setds.empty()) {
        // extract the vertices with the minimum distance 
        std::pair<int, int> temp = *(setds.begin());
        setds.erase(setds.begin());

        int u = temp.second;

        // get all adjacent vertices of a vertext 
        for (auto elem : adj[u]) {
            int v = elem.first;
            int weight = elem.second;

            if (dist[v] > dist[u] + weight) {
                if (dist[v] != INF) {
                    setds.erase(setds.find(std::make_pair(dist[v], v)));
                }
                // update the distance of v
                dist[v] = dist[u] + weight;
                setds.insert(std::make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }
    // print out the shotest path
    std::cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; ++i) {
        std::cout << i << "            " << dist[i] << " the path is: ";
        print_path(parent, i);
        std::cout << "\n";
    }
}


int main() {
    // set are sorted based on the first value of pairs
    // in
    std::set<std::pair<int, int>> s2; 
    s2.insert(std::make_pair(5, 0)); 
    s2.insert(std::make_pair(3, 1)); 
    for (auto elem : s2) {
        std::cout << '(' << elem.first << ' ' << elem.second << ")\n"; 
    }
    std::set<int> s1;
    s1.insert(8);
    s1.insert(3);
    for (auto elem : s1) {
        std::cout << elem << "\n"; 
    }
    Graph g(5);
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 10);
    g.add_edge(1, 2, 3);
    g.add_edge(1, 3, 11);
    g.add_edge(2, 3, 2);
    g.add_edge(3, 4, 3);

    g.shortest_path(4);

    return 0;
}