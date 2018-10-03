#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> &adj_list, vector<bool> &is_visited, int vertex) {
    is_visited[vertex] = true;
    cout << "Visited vertex " << vertex << endl;

    for (size_t i {0}; i < adj_list[vertex].size(); i++)
        if (!is_visited[adj_list[vertex][i]])
            DFS(adj_list, is_visited, adj_list[vertex][i]);
    
    return;
}

int main(int argc, char const *argv[]) {
    /*
    Init adjacency list
    */

    // For example
    vector<vector<int>> adj_list{
        {1, 2, 3},
        {0, 4},
        {0, 3},
        {0, 2},
        {1}
    };

    // Vertex attendance array
    vector<bool> is_visited(adj_list.size(), false);

    // DFS from the first vertex
    int init_vertex {0};
    
    is_visited[init_vertex] = true;
    cout << "Initial vertex " << init_vertex << endl;

    for (size_t i {0}; i < adj_list[init_vertex].size(); i++)
        if (!is_visited[adj_list[init_vertex][i]])
            DFS(adj_list, is_visited, adj_list[init_vertex][i]);
    
    return 1;
}