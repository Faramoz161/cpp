#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[]) {
    
    vector<vector<int>> adjacency_list;

    for (auto i : adjacency_list) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;       
    }
}