/*
Breadth First Search
Reference: http://www.mathcs.emory.edu/~cheung/Courses/253/Syllabus/Graph/bfs.html
*/
#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>


// a class for undirected graph
class Graph{
    public: 
        Graph(int vertices);  // constructor
        ~Graph();  // destructor 
        void add_edge(int v, int w);
        void bfs(int s);  // print out the breadth first search 
        void print_shortest_path(int start, int dest);
    private:
        int V;  // number of vertices
        int E;  // number of edges
        std::vector<int>* adj;  // a pointer to an an array that containing adjancy lists 
        bool _bfs(int start, int dest, int pred[], int dist[]) {
            // a queue to store the vertices 
            std::queue<int> gq; 
            bool visited[V];

            // initialize the arrays  
            for (int i = 0; i < V; i++) {
                visited[i] = false; 
                pred[i] = -1;
                dist[i] = INT_MAX;  // maximum of int 
            }

            visited[start] = true; 
            dist[start] = 0;
            gq.push(start);

            // bfs search 
            while(!gq.empty()) {
                int u = gq.front();  // access the first element 
                gq.pop();

                // check edges from adjacency list
                for (auto elem : adj[u]) {
                    // if not visit 
                    if (!visited[elem]) {
                        visited[elem] = true;
                        dist[elem] = dist[u] + 1;
                        pred[elem] = u;  // predecessor 
                        gq.push(elem);  // enqueue the vertice from adjacency list 

                        // stop BFS when we find the destination 
                        if (elem == dest) {
                            return true; 
                        }
                    }
                }
            }

            return false;  // return false if bfs does not reach to the destination 
        }
};


Graph::Graph(int vertices) {
    V = vertices;
    adj = new std::vector<int>[V];  // array with size of V 
}

Graph::~Graph() {
    delete[] adj; 
}

void Graph::add_edge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
    E++; 
}

void Graph::bfs(int s) {
    // use queue to visit all your neighbors before your neighbor's neighbors
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;  // mark all vertices as false 
    }
    std::queue<int> gq;  // create a queue for the graph 

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    gq.push(s);

    while (!gq.empty()) {
        int v = gq.front();  // access the first element in the queue
        std::cout << v << "\n";
        gq.pop();  // dequeue the first element 
        // Get all adjacent vertices of the dequeued
        for (auto elem : adj[v]) {
            // if not marked 
            if (!visited[elem]) {
                visited[elem] = true;  // mark it now
                gq.push(elem);
            }
        }
    }

    delete[] visited;
}

void Graph::print_shortest_path(int start, int dest) {
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[V], dist[V]; 
    bool reach = _bfs(start, dest, pred, dist);
    if (reach == false) {
        std::cout << "Given source " << start << " and destination "
                  << dest << " are not connected\n";
        return;
    }

    std::vector<int> path;  // vector path stores the shortest path
    int crawl = dest; 
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    // print out the shortest distance
    std::cout << "The shortest distance from " << start << " to " << dest
              << " is " << dist[dest] << "\n";

    // printing path from source to destination
    for (int i = path.size() - 1; i >= 0; i--) {
        std::cout << path[i] << " ";
    }
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
    g1.bfs(0);
    g1.print_shortest_path(0, 2);
    g1.print_shortest_path(8, 7);
    g1.print_shortest_path(0, 6);
}