#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct graph_t {
    vector<vector<size_t>> adj_list;
    vector<bool> is_visited;
};

void add_to_queue(graph_t &graph, queue<size_t> &vertex_queue, size_t vertex) {
    
    for (size_t i = 0; i < graph.adj_list[vertex].size(); i++) {
        size_t vrtx = graph.adj_list[vertex][i];
        
        if (!graph.is_visited[vrtx]) {
            graph.is_visited[vrtx] = true;
            vertex_queue.push(vrtx);
        }
    }

    return;
}

void BFS(graph_t &graph, size_t init_vertex) {
    
    // Init queue
    queue<size_t> vertex_queue;
    add_to_queue(graph, vertex_queue, init_vertex);
    
    // BFS
    while (!vertex_queue.empty()) {
        size_t vertex = vertex_queue.front();
        vertex_queue.pop();

        // Do something
        // For example
        cout << "Visited vertex " << vertex << endl;

        add_to_queue(graph, vertex_queue, vertex);
    }

    return;
}

int main(int argc, char const *argv[]) {
    
    // Init adjacency list
    // For example
    vector<vector<size_t>> adj_list{
        {1, 2, 4, 6},
        {0, 3, 6},
        {0, 3, 5},
        {1, 2, 4},
        {0, 3, 5},
        {2, 4},
        {0, 1}
    };

    // Vertex attendance array
    vector<bool> is_visited(adj_list.size(), false);

    graph_t graph{adj_list, is_visited};

    // BFS from the zero vertex
    size_t init_vertex {0};

    graph.is_visited[init_vertex] = true;
    cout << "Initial vertex " << init_vertex << endl;

    BFS(graph, init_vertex);
    
    return 1;
}