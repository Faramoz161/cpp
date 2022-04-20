#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <chrono>

using namespace std;

void tree_sort(vector<int> array) {
	auto timer_begin = chrono::steady_clock::now();

	multiset<int> m;
	copy(begin(array), end(array), inserter(m, begin(m)));
	array.clear();
	copy(begin(m), end(m), back_inserter(array));

	auto timer_end = chrono::steady_clock::now();
	cout << "Tree sort: " << chrono::duration_cast<chrono::milliseconds>(timer_end - timer_begin).count() << "\n";
}