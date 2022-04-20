#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void selection_sort(vector<int> array) {
	auto timer_begin = chrono::steady_clock::now();

	for(auto iter = begin(array); iter != end(array) - 1; ++iter) {
		auto iter_min = min_element(iter, end(array));
		if(iter != iter_min)
			swap(*iter, *iter_min);
	}

	auto timer_end = chrono::steady_clock::now();
	cout << "Selection sort: " << chrono::duration_cast<chrono::milliseconds>(timer_end - timer_begin).count() << "\n";
}