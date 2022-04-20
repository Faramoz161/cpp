#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void bubble_sort(vector<int> array) {
	auto timer_begin = chrono::steady_clock::now();
	size_t size = array.size();
	
	for(size_t i = 1; i < size; i++)
		for(size_t j = 0; j < size - i; j++)
			if(array[j] > array[j + 1])
				swap(array[j], array[j + 1]);

	auto timer_end = chrono::steady_clock::now();
	cout << "Bubble sort: " << chrono::duration_cast<chrono::milliseconds>(timer_end - timer_begin).count() << "\n";
}