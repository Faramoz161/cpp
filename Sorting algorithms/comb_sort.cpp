#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void comb_sort(vector<int> array) {
	const float factor = 1.247f;
	auto timer_begin = chrono::steady_clock::now();
	size_t size = array.size();
	size_t step = size - 1;

	while(step >= 1) {
		for(size_t i = 0; i < size - step; i++)
			if(array[i] > array[i + step])
				swap(array[i], array[i + step]);
		step = (size_t)(step * 1.0f / factor);
	}

	auto timer_end = chrono::steady_clock::now();
	cout << "Comb sort: " << chrono::duration_cast<chrono::milliseconds>(timer_end - timer_begin).count() << "\n";
}