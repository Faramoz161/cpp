#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void insertion_sort(vector<int> array) {
	auto timer_begin = chrono::steady_clock::now();

	for(size_t i = 1; i < array.size(); i++)
		for (size_t j = i; j > 0 && array[j] < array[j - 1]; j--)
			swap(array[j], array[j - 1]);

	auto timer_end = chrono::steady_clock::now();
	cout << "Insertion sort: " << chrono::duration_cast<chrono::milliseconds>(timer_end - timer_begin).count() << "\n";
}