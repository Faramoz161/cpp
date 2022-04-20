#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

#include "ostream_iter.h"

using namespace std;

int main() {
    vector<int> a {0, 1, 2, 3, 4, 5, 6};
    copy(a.begin(), a.end(), ostream_iter<int>(cout, " ", 2));
    cout << endl;

    return 0;
}