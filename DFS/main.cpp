#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<size_t>> &adj_list, vector<bool> &is_visited, size_t vertex) {
    
    is_visited[vertex] = true;

    // Do something
    // For example
    cout << "Visited vertex " << vertex << endl;

    for (size_t i = 0; i < adj_list[vertex].size(); i++)
        if (!is_visited[adj_list[vertex][i]])
            DFS(adj_list, is_visited, adj_list[vertex][i]);
    
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

    // DFS from the zero vertex
    size_t init_vertex {0};
    
    is_visited[init_vertex] = true;
    cout << "Initial vertex " << init_vertex << endl;

    for (size_t i = 0; i < adj_list[init_vertex].size(); i++) {
        size_t vrtx = adj_list[init_vertex][i];
        if (!is_visited[vrtx])
            DFS(adj_list, is_visited, vrtx);
    }
    
    return 1;
}