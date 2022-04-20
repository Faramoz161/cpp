#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;

void radixLSD_sort(vector<int> array) {
	auto timer_begin = chrono::steady_clock::now();
	int max_k = (int)log10(array.size());

	for (int i = 0; i <= max_k; i++) {
		vector<vector<int>> categories(10);
		int p = (int)pow(10ll, i);

		for(int element : array)
			categories[(element / p) % 10].push_back(element);

		array.clear();
		for (auto category : categories)
			array.insert(end(array), begin(category), end(category));
	}

	auto timer_end = chrono::steady_clock::now();
	cout << "Radix(LSD) sort: " << chrono::duration_cast<chrono::milliseconds>(timer_end - timer_begin).count() << "\n";
}